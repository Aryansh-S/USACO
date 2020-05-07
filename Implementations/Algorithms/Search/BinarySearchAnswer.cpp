#include <bits/stdc++.h>
using namespace std;
//level: silver 

bool works(int m){
 //check if works
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
