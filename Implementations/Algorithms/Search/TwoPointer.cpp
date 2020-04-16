#include <bits/stdc++.h>
using namespace std;

//objective: given an array, find a pair of elements that sums to a given sum in O(n log n) total runtime or less
//we can't just brute force with two nested for loops -- that would be O(n^2); instead we use two pointers
//first, sort the array in O(n log n)
//have a left pointer l and a right pointer r (indices); initialize them at the beginning and end of the array respectively
//keep a running tally of the sum a[l]+a[r]; if it is too big, shift r left; if it is too small, shift l right 

#define FOR(i,a,b) for(__typeof(b)i=(a)-((a)>(b));i!=(b)-((a)>(b));i+=((a)>(b))?-1:1) //go from i=lb to i=ub-1
#define F0R(i,b) FOR(i,0,b)

const int SZ = 1e5;

int n, a[SZ], S, L, R;

int main(){
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> S; F0R(i,n) cin >> a[i];
  sort(a,a+n);
  int l=0, r=n-1; //keep two pointers (simply indices)
  while(l<r){ //we require the left pointer l to be to the left of r
    if(a[l]+a[r]==S) {L=l,R=r; break;}
    if(a[l]+a[r]<S) l++; else r--;
  }
  cout << L << " " << R << "\n";
  return 0;
}
