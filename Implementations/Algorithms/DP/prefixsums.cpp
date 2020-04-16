#include <bits/stdc++.h>
using namespace std;

//objective: use prefix sums to answer static range sum queries

#define FOR(i,a,b) for(__typeof(b)i=(a)-((a)>(b));i!=(b)-((a)>(b));i+=((a)>(b))?-1:1) //go from i=lb to i=ub-1
#define F0R(i,b) FOR(i,0,b)

const int SZ = 1e5;

int n, q, dp[SZ+1]; //it is convenient to 1-index

int main(){
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> q; FOR(i,1,n+1) cin >> dp[i];
  F0R(i,q){int a,b; cin >> a >> b; cout << dp[b]-dp[a-1] << "\n";}
  return 0;
}
