#ifndef CHIPS_H_
#define CHIPS_H_




#include <bits/stdc++.h>
#include <math.h>
#include <boost/lexical_cast.hpp>
using namespace std;
string binary="";


//n-input bool vectors, with log_2(n) selectors, rounded up.
bool _MUX(vector<bool> &inputs, vector<bool>&selectors){
  binary="";
  for (auto b : selectors)
    binary+=b?'1':'0';
  return inputs[std::bitset<64>(binary).to_ullong()];
}

//n-input bool vector
vector<bool> _DECODER(vector<bool> &inputs){
  binary="";
  for (auto b : inputs)
    binary+=b?'1':'0';
  vector<bool> output(pow(2, inputs.size()), 0);
  output[std::bitset<64>(binary).to_ullong()]=1;
  return output;
}

//n-input bool vector
vector<bool> _NAND_DECODER(vector<bool> &inputs){
  binary="";
  for (auto b : inputs)
    binary+=b?'1':'0';
  vector<bool> output(pow(2,inputs.size()), 1);
  output[std::bitset<64>(binary).to_ullong()]=0;
  return output;
}


//n-input bool vector, where log2(n) is an element of positive integers.
//tested, working--took an hour or so to make efficient.
vector<bool> _ENCODER(vector<bool>&inputs){
  binary="";
  if (floor(log2(inputs.size()))!=log2(inputs.size()) || count(inputs.begin(),inputs.end(), true)>1 || count(inputs.begin(),inputs.end(), true)==0){
    cout<<"bad input, no possible simple encoder.";
  }

  ptrdiff_t pos = distance(inputs.begin(), find(inputs.begin(), inputs.end(), true));

  binary=bitset<64>((inputs.size()-1)-pos).to_string().substr(64-log2(inputs.size()),log2(inputs.size()));
  vector<bool>output;
  for (char b : binary){
    if (b=='1')
      output.push_back(true);
    else 
      output.push_back(false);

  }
  return output;
}






#endif