#include <bits/stdc++.h>
using namespace std;

//bounded type for simple floodfill

template<class T> struct bd{ 
  T v; int l,r;
  bd(int _l, int _r){l=_l,r=_r;}
  operator int(){return v;}
  bd operator++(){
    bd tmp; tmp.v = v + 1 > r ? r : ++v; return tmp; 
  }
  bd operator--(){
    bd tmp; tmp.v = v - 1 < l ? l : --v; return tmp;
  }
};
