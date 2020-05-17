
#ifndef PRIMITIVES_H_
#define PRIMITIVES_H_
#include <bits/stdc++.h>

using namespace std;

//helper: https://www.geeksforgeeks.org/bitwise-and-of-n-binary-strings/
int makeEqualLength(string &a, string &b)
{
  int len_a = a.length();
  int len_b = b.length();

  int num_zeros = abs(len_a - len_b);

  if (len_a < len_b)
  {
    for (int i = 0; i < num_zeros; i++)
    {
      a = '0' + a;
    }
    // Return len_b which is highest.
    // No need to proceed further!
    return len_b;
  }
  else
  {
    for (int i = 0; i < num_zeros; i++)
    {
      b = '0' + b;
    }
  }
  // Return len_a which is greater or
  // equal to len_b
  return len_a;
}
string andOperationBitwise(string s1, string s2)
{
  // Make both strings of same length with the
  // maximum length of s1 & s2.
  int length = makeEqualLength(s1, s2);

  // Initialize res as NULL string
  string res = "";

  // We start from left to right as we have
  // made both strings of same length.
  for (int i = 0; i < length; i++)
  {
    // Convert s1[i] and s2[i] to int and perform
    // bitwise AND operation, append to "res" string
    res = res + (char)(((s1[i] - '0') & (s2[i] - '0')) + '0');
  }
  return res;
}
bool longest_vec(const std::vector<int> &lhs, const std::vector<int> &rhs)
{
  return lhs.size() < rhs.size();
}

//n-input bools
vector<bool> _AND(const vector<vector<bool>> &inputs)
{
  vector<bool> output;
  vector<string> strings;
  string binary = "";
  for (auto values : inputs)
  {
    for (auto bit : values)
    {
      binary += bit ? '1' : '0';
    }
    strings.push_back(binary);
    binary = "";
  }
  string result = strings[0];
  for (size_t i = 1; i < strings.size(); i++)
  {
    result = andOperationBitwise(result, strings[i]);
  }
  for (auto a : result)
    output.push_back(a == '1');
  return output;
}

//n-input bools
vector<bool> _OR(const vector<vector<bool>> &inputs)
{
  vector<bool> output;
  vector<string> strings;
  string binary = "";
  for (auto values : inputs)
  {
    for (auto bit : values)
    {
      binary += bit ? '1' : '0';
    }
    strings.push_back(binary);
    binary = "";
  }
  string arr[strings.size()];
  copy(strings.begin(), strings.end(), arr);
  int n = strings.size();
  string res;

  int max_size = INT_MIN;

  // Get max size and reverse each string
  // Since we have to perform OR operation
  // on bits from right to left
  // Reversing the string will make it easier
  // to perform operation from left to right
  for (int i = 0; i < n; i++)
  {
    max_size = max(max_size, (int)arr[i].size());
    reverse(arr[i].begin(), arr[i].end());
  }

  for (int i = 0; i < n; i++)
  {

    // Add 0s to the end of strings
    // if needed
    string s;
    for (size_t j = 0; j < max_size - arr[i].size(); j++)
      s += '0';

    arr[i] = arr[i] + s;
  }

  // Perform OR operation on each bit
  for (int i = 0; i < max_size; i++)
  {
    int curr_bit = 0;
    for (int j = 0; j < n; j++)
      curr_bit = curr_bit | (arr[j][i] - '0');

    res += (curr_bit + '0');
  }

  // Reverse the resultant string
  // to get the final string
  reverse(res.begin(), res.end());

  for (auto a : res)
    output.push_back(a == '1');
  return output;
}

//1-input bool
vector<bool> _NOT(vector<bool> input)
{
  input.flip();
  return input;
}

//n-input bools
vector<bool> _NAND(const vector<vector<bool>> &inputs)
{
  return _NOT(_AND(inputs));
}

//n-input bools
vector<bool> _NOR(const vector<vector<bool>> &inputs)
{
  return _NOT(_OR(inputs));
}

//The two-input _XOR is applied in th regular way
//multi-input XOR can be thought of as effectively one-hot detectors. This sucks.
//We will instead be implementing them as cascades of XOR, useful for %2, or parity generators.
vector<bool> _XOR(const vector<vector<bool>> &inputs)
{
  vector<bool> result = inputs[0];
  uint max_size = 0;

  //get largest input vector--this is to prevent conflicts from differing length binary strings
  for (auto it : inputs)
    max_size = it.size() > max_size ? it.size() : max_size;

  while (result.size() < max_size)
  {
    result.insert(result.begin(), false);
  }
  //todo fix insertion
  vector<bool> current_string;
  for (size_t i = 1; i < inputs.size(); i++)
  {
    current_string = inputs[i];
    while (current_string.size() < max_size)
      current_string.insert(current_string.begin(), false);

    vector<bool> nand_one = _NAND({result, current_string});
    vector<bool> nand_two = _NAND({result, nand_one});
    vector<bool> nand_three = _NAND({nand_one, current_string});
    result = _NAND({nand_two, nand_three});
  }
  return result;
}

//2-input bools
vector<bool> _XNOR(const vector<vector<bool>> &inputs)
{
  return _NOT(_XOR(inputs));
}

#endif
