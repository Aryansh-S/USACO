#include <bits/stdc++.h>
using namespace std;

//bounded type for simple floodfill

template<class T> struct bd{ 
  T v; int l,r;
  bd(int _l = 0, int _r, int v){l=_l,r=_r;}
  operator int(){return v;}
  bd operator++(){
    bd tmp; tmp.v = v + 1 > r ? r : ++v; return tmp; 
  }
  bd operator--(){
    bd tmp; tmp.v = v - 1 < l ? l : --v; return tmp;
  }
  bd operator+(int d){
    bd tmp; d ? (tmp.v = v + d > r ? r : v + d) : (tmp.v = v + d < l ? l : v + d);
    return 0; 
  }
  bd operator-(int d){return bd+1*d;}
};
