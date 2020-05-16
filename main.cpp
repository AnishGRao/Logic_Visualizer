#include <iostream>
#include "Chips.h"
#include "Primitives.h"
#include "Circuit.h"
int main() {
  vector<bool> hatred={true,true,true,true};
  //test: 14+11+1=26
  //out: 16+8+2=26
  vector<bool>out={_16B_FULL_ADDER({1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0},0)};
  
  for (auto a : out){
    if (a)
      cout<<"1\t";
    else
      cout<<"0\t";
  }
  
  
  /*
vector<bool> l ={1,0,0,0,0,0,0,0};
vector<bool> s ={1,1};
  cout<<"\n";
  s=_ENCODER(l);
  cout<<"\n";
  for (auto a : s){
    if (a)
      cout<<"1  ";
    else 
      cout<<"0  ";
  }
  //cout<<s.size();
  */
}