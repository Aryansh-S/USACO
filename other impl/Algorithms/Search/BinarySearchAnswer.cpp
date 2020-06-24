#include <bits/stdc++.h>
using namespace std;
//level: silver 

bool works(int m){
 //check if works
 //make this an inequality that can be true over a search space monotonically instead of a flat equation 
 //otherwise won't work
}

int main(){
  int lo = 0, hi = N, ans = 0;
  while(lo <= hi){
    int mid = lo + (hi - lo) / 2;
    if(works(mid)) ans = mid, hi = mid - 1;
    else lo = mid + 1;
  } 
}


//footnote: (hi + low) can overflow, so do hi + (hi - lo) / 2 instead of (hi + lo) / 2
