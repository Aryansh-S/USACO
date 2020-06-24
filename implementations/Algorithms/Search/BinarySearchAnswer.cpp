#include <bits/stdc++.h>
using namespace std;
//level: silver 

bool works(int m){
 //check if works
 //make this an inequality that can be true over a search space monotonically instead of a flat equation 
 //otherwise won't work
}

int main(){
  int lo = 0; int hi = N;
  int ans = 0;
  while(lo <= hi){
    int mid = lo+(hi-lo)/2;
    if(works(mid)){
      ans = mid;
      hi = mid-1;
    }
    else{
      lo = mid+1;
    }
  } return 0;
}
