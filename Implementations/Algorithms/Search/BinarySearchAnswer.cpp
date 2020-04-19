#include <bits/stdc++.h>
using namespace std;
//level: silver 

//objective: given a value of n specifying a discrete search space [0,n) for a variable k, search for optimal k that works

int n,ans;

int checkifworks(int k){
  // return 1 if k works, -1 if k too small, 0 if k too big (based on some monotonic conditions)
}

int main(){
  cin >> n; 
  //check for k from 0 to n-1
  int l=0,r=n-1;
  while(l<=r){
    int m=l+(r-l)/2;
    if(check(m)==1){ans=m; break;}
    else if(check(m)==-1 && check(m+1)==0) {ans=m; break;}
    else if(check(m)==0 && check(m+1)==-1) {ans=m+1; break;}
    else if(check(m)==-1) l=m+1;
    else r=m-1;
  }
  cout << ans << "\n";
  return 0;
}
