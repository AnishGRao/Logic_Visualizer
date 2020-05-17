#include <iostream>
#include "Chips.h"
#include "Primitives.h"
#include "Circuit.h"
#include "Clock_Sensitive.h"
void output_cleaner(vector<bool>&binary){
  for (auto bit : binary){
    if (!bit)
      binary.erase(binary.begin());
    else
      return;
  }
}


int main() {
  vector<bool> hatred={true,true,true,true};
  //test: 10, 9
  //out: 14
  vector<bool>out=_32BIT_ALU({0,1}, {1,0}, 0, 1);//_NAND({{1,1,0,1},{0,1,0,1,0,1},{0,1,1,1,1},{0,0,0,1,1,1}});
  //output_cleaner(out);

  //fucntionally equivalent to 01000, 00010.
  //ans:6
  //01000+11101
  //8+(1+4+8+16)
  //8+29
  //37
  //100101
  int i =0;
  for (auto a : out){
    
    
    if (i==0 && out.size()>32){
      if (a)
        cout<<"-";
      else
        cout<<" ";
      i++;
      continue;
    }
    
    if (a)
      cout<<"1 ";
    else
      cout<<"0 ";
      
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