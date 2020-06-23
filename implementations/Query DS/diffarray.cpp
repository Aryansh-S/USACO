#include <bits/stdc++.h>
using namespace std;
//level: basic silver

//objective: use difference arrays (aka +1/-1 trick) to support point queries with range increment updates 

#define FOR(i,a,b) for(__typeof(b)i=(a)-((a)>(b));i!=(b)-((a)>(b));i+=((a)>(b))?-1:1) //go from i=lb to i=ub-1
#define F0R(i,b) FOR(i,0,b)

const int SZ = 1e5; 

int n, u, q, data[SZ], diffdp[SZ];

int main(){
  cin >> n >> q; F0R(i,n) cin >> data[i];
  FOR(i,1,n) diffdp[i]=data[i]-data[i-1]; //draw out into differences (carry and drop off)
  F0R(i,u){int a,b; cin >> a >> b; a--,b--; diffdp[a]++; diffdp[b+1]--;} //perform updates
  F0R(i,n-1) diffdp[i+1]+=diffdp[i]; //collapse back w/ psums 
  F0R(i,q){int a; cin >> a; a--; cout << diffdp[a] << "\n";}
  return 0;
}
