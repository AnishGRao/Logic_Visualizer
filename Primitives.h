
#ifndef PRIMITIVES_H_
#define PRIMITIVES_H_
#include <bits/stdc++.h>

using namespace std;


//n-input bools
bool _AND(const vector<bool>&inputs){
  if (std::find((inputs).begin(), (inputs).end(), false)==(inputs).end()){
    return true;
  }
  return false;
}

//n-input bools
bool _OR(const vector<bool>&inputs){
  if (std::find((inputs).begin(), inputs.end(), true) != (inputs).end()){
    return true;
  }
  return false;
}

//1-input bool
bool _NOT(bool input){
  return !input;
}

//n-input bools
bool _NAND(const vector<bool>&inputs){
  if (std::find((inputs).begin(), (inputs).end(), false) != (inputs).end()){
    return true;
  }
  return false;
}

//n-input bools
bool _NOR(const vector<bool>&inputs){
  if (std::find((inputs).begin(), (inputs).end(), true) != (inputs).end()){
    return false;
  }
  return true;
}

//2-input bools
bool _XOR(bool input_one, bool input_two){
  if (input_one==input_two)
    return false;
  return true;
}

//2-input bools
bool _ENOR(bool input_one, bool input_two){
  if (input_one==input_two)
    return !false;
  return !true;
}


#endif


