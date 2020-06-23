#include <bits/stdc++.h>
using namespace std;
//level: basic silver

//objective: binary search the index of q queries in O(q log n) with O(n log n) sort preprocessing

#define FOR(i,a,b) for(__typeof(b)i=(a)-((a)>(b));i!=(b)-((a)>(b));i+=((a)>(b))?-1:1) //go from i=lb to i=ub-1
#define F0R(i,b) FOR(i,0,b)
#define lb lower_bound
#define ub upper_bound

const int SZ = 1e5;

int n, q, a[SZ];

void recursive_bin_search(int k, int l, int r){ //initialize as recursive_bin_search(k,0,n-1)
  if(r>=l){ //right pointer must be greater than left
    int mid=l+(r-l)/2; //find the midpoint
    if(a[mid]==k) {cout << "found at index " << mid << "\n"; return;}
    if(a[mid]>k) recursive_bin_search(k,l,mid-1);
    else recursive_bin_search(k,mid+1,r);
  }
  cout << "not found\n";
}

void iterative_bin_search(int k, int l, int r){ //initialize as iterative_bin_search(k,0,n-1)
  //very similar to two pointer method of iterative search
  while(l<=r){
    int mid=l+(r-l)/2;
    if(a[mid]==k) {cout << "found at index " << mid << "\n"; return;}
    if(a[mid]<k) l=mid+1;
    else r=mid-1;
  }
  cout << "not found\n";
}

void std_bin_search(int k){
  if(lb(a,a+n,k)==a+n) cout << "not found\n";
  else if(*lb(a,a+n,k)==k) cout << "found at index " << lb(a,a+n,k)-a << "\n";
  else cout << "not found\n";
}

int main(){
  cin.tie(0)->sync_with_stdio(0); 
  cin >> n >> q; F0R(i,n) cin >> a[i];
  sort(a, a+n); //first, sort
  //the easiest way to binary search is using the built-in std::lb and std::ub (macros)
  F0R(i,q) std_bin_search(i); 
  //but other ways to binary search manually are given as functions above 
  //you may sometimes be forced to use manual binary search if there is a very specific condition you are trying to check for
  return 0;
}
