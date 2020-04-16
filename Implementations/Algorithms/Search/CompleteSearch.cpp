#include <bits/stdc++.h>
using namespace std;
//level: bronze

//objective: search for a value in an array in O(n)

#define FOR(i,a,b) for(__typeof(b)i=(a)-((a)>(b));i!=(b)-((a)>(b));i+=((a)>(b))?-1:1) //go from i=lb to i=ub-1
#define F0R(i,b) FOR(i,0,b)

const int SZ = 1e5; 

int n, val, ans, a[SZ];

int main(){
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> val; F0R(i,n) cin >> a[i];
  F0R(i,n) if(a[i]==val) ans=i; 
  cout << ans << "\n";
  return 0;
}
