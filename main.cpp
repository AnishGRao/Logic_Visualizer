#include <iostream>
#include "Chips.h"
#include "Primitives.h"
int main() {
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
}