#include <bits/stdc++.h>
using namespace std;

const int xd[4] = {0,1,0,-1}, yd[4] = {1,0,-1,0}; 

//bounded type for simple floodfill -- no need to worry about bounding!

template<class T> struct bd{ //bdi for int
  T v = 0; int l = 0, r = 1;
  bd(int _v, int _l, int _r){l=_l,r=_r,v=_v; if(v < l) v = l; if(v > r) v = r;}
  operator int(){return v;}
  bd<T> operator++(){
    bd<T> tmp(v,l,r); tmp.v = v + 1 > r ? r : ++v; return tmp; 
  }
  bd<T> operator--(){
    bd<T> tmp(v,l,r); tmp.v = v - 1 < l ? l : --v; return tmp;
  }
  bd<T> operator+(int d){
    bd<T> tmp(v,l,r); (d > 0) ? (tmp.v = v + d > r ? r : v + d) : (tmp.v = v + d < l ? l : v + d);
    return tmp; 
  }
  bd<T> operator-(int d){return operator+(-1*d);}
};
using bdi = bd<int>;

bool vis[105][105];

void dfs(bdi i, bdi j){
  if(!vis[i][j]){
    vis[i][j]=1; 
    for(int k = 0; k < 4; ++k) dfs(i+xd[k], j+yd[k]);
  }
}

int main() {
  
  dfs(bdi(1,1,100),bdi(1,1,100)); 
  
  for(int i = 1; i <= 100; ++i) for(int j = 1; j <= 100; ++j) if(!vis[i][j]) return 0;
  
  cout << "success\n";
  
  return 0;
}
