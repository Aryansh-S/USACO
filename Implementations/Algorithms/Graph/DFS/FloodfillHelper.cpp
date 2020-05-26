#include <bits/stdc++.h>
using namespace std;

//bounded type for simple floodfill

template<class T, int l = 0, int r> bd{ 
  T v; 
  operator int(){return v;}
  bd operator++(){
    bd tmp; tmp.v = v + 1 > r ? r : ++v; return tmp; 
  }
  bd operator--(){
    bd tmp; tmp.v = v - 1 < l ? l : --v; return tmp;
  }
};

int n;

void dfs(bd<int, n> i, bd<int, n> j){
  if(!vis[(int)i][(int)j]){
    vis[(int)i][(int)j]) = 1;
  }
}

int main(){
  
  
  
  return 0;
}
