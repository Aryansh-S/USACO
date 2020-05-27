#include <bits/stdc++.h>
using namespace std;

//bounded type for simple floodfill

template<class T> struct bd{ 
  T v; int l,r;
  bd(int _l, int _r, int _v){l=_l,r=_r,v=_v;}
  operator int(){return v;}
  bd operator++(){
    bd tmp(l,r,v); tmp.v = v + 1 > r ? r : ++v; return tmp; 
  }
  bd operator--(){
    bd tmp(l,r,v); tmp.v = v - 1 < l ? l : --v; return tmp;
  }
  bd operator+(int d){
    bd tmp; d ? (tmp.v = v + d > r ? r : v + d) : (tmp.v = v + d < l ? l : v + d);
    return 0; 
  }
  bd operator-(int d){return operator+(-1*d);}
};
