#ifndef CHIPS_H_
#define CHIPS_H_




#include <bits/stdc++.h>
#include <math.h>
#include "Primitives.h"
using namespace std;
string binary="";


//n-input bool vectors, with log_2(n) selectors, rounded up.
bool _MUX(const vector<bool> &inputs, const vector<bool>&selectors){
  binary="";
  for (auto b : selectors)
    binary+=b?'1':'0';
  return inputs[std::bitset<64>(binary).to_ullong()];
}

//n-input bool vector
vector<bool> _DECODER(const vector<bool> &inputs){
  binary="";
  for (auto b : inputs)
    binary+=b?'1':'0';
  vector<bool> output(pow(2, inputs.size()), 0);
  output[std::bitset<64>(binary).to_ullong()]=1;
  return output;
}

//n-input bool vector
vector<bool> _NAND_DECODER(const vector<bool> &inputs){
  binary="";
  for (auto b : inputs)
    binary+=b?'1':'0';
  vector<bool> output(pow(2,inputs.size()), 1);
  output[std::bitset<64>(binary).to_ullong()]=0;
  return output;
}


//n-input bool vector, where log2(n) is an element of positive integers.
//tested, working--took an hour or so to make efficient.
vector<bool> _ENCODER(const vector<bool>&inputs){
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


vector<bool> _HALF_ADDER(bool input_one, bool input_two){
  return {
          _AND({input_one,input_two}), 
          _XOR(input_one,input_two)
  };
}

vector<bool> _1B_FULL_ADDER(bool input_one, bool input_two, bool carry){
  return{
        //CARRY  
        _OR({
              _AND({
                carry, 
                _XOR(input_one, input_two)
              }),

              _AND({input_one,  input_two})
            }),
        //SUM
        _XOR(
              _XOR(input_one, input_two),
              carry
            )
  };
}


//technically how does this function:
//really handwavy: a+b+c, where a and b are four bits, and c is one bit.
vector<bool> _4B_ADDER(const vector<bool> &input_one,const vector<bool> &input_two,bool carry){
  vector<bool> adder_1 = _1B_FULL_ADDER(input_one[3], input_two[3], carry);
  vector<bool> adder_2 = _1B_FULL_ADDER(input_one[2], input_two[2], adder_1[0]);
  vector<bool> adder_3 = _1B_FULL_ADDER(input_one[1], input_two[1], adder_2[0]);
  vector<bool> adder_4 = _1B_FULL_ADDER(input_one[0], input_two[0], adder_3[0]);
  return vector<bool>{adder_4[0], adder_4[1],adder_3[1],adder_2[1],adder_1[1]};
}


//works.
vector<bool> _16B_ADDER(const vector<bool> &input_one,const vector<bool> &input_two,bool carry){
  vector<bool> adder_1 = _4B_FULL_ADDER(vector<bool>(input_one.begin()+12, input_one.begin()+16),
                                        vector<bool>(input_two.begin()+12, input_two.begin()+16),
                                        carry);
  vector<bool> adder_2 = _4B_FULL_ADDER(vector<bool>(input_one.begin()+8, input_one.begin()+12),
                                        vector<bool>(input_two.begin()+8, input_two.begin()+12),
                                        adder_1[0]);
                                        //maybe change second from 4 to 5 and then stick with 8 on end of both
  vector<bool> adder_3 = _4B_FULL_ADDER(vector<bool>(input_one.begin()+4, input_one.begin()+8),
                                        vector<bool>(input_two.begin()+4, input_two.begin()+8),
                                        adder_2[0]);
  vector<bool> adder_4 = _4B_FULL_ADDER(vector<bool>(input_one.begin(), input_one.begin()+4),
                                        vector<bool>(input_two.begin(), input_two.begin()+4),
                                        adder_3[0]);
  vector<bool>output;
  output.reserve(adder_1.size()*4);
  output.insert(output.end(), adder_4.begin(), adder_4.end());
  output.insert(output.end(), adder_3.begin(), adder_3.end());
  output.insert(output.end(), adder_2.begin(), adder_2.end());
  output.insert(output.end(), adder_1.begin(), adder_1.end());
  return output;
}


vector<bool> _32B_ADDER(const vector<bool> &input_one,const vector<bool> &input_two,bool carry){
  vector<bool> adder_1 = _16B_ADDER(vector<bool>(input_one.begin()+16, input_one.begin()+32),
                                    vector<bool>(input_two.begin()+16, input_two.begin()+32),
                                    carry);
  vector<bool> adder_2 = _16B_ADDER(vector<bool>(input_one.begin(), input_one.begin()+17),
                                    vector<bool>(input_two.begin(), input_two.begin()+17),
                                    adder_1[0]);
  vector<bool>output;
  output.reserve(adder_1.size()*2);
  output.insert(output.end(), adder_2.begin(), adder_2.end());
  output.insert(output.end(), adder_1.begin(), adder_1.end());
  return output;

  
}
//TODO: n-bit full adder


vector<bool> _32BIT_ALU(const vector<bool> &input_one,const vector<bool> &input_two, bool ctrl_one, bool ctrl_two){
  //PSEUDOCODE:
  /*
      A && B----\
                mux 1: 0 up, 1, down--\
      A || B----/                      \
                                        mux 2: up 0, down 1--result      
      A +- B---------------------------/
  */
 return {0};
}


#endif