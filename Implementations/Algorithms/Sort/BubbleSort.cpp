#include <bits/stdc++.h>
using namespace std;

//objective: design a worst case O(n^2) sort by swapping adjacent elements 

typedef vector<int> vi; 
#define FOR(i,a,b) for(__typeof(b)i=(a)-((a)>(b));i!=(b)-((a)>(b));i+=((a)>(b))?-1:1) //go from i=lb to i=ub-1
#define F0R(i,b) FOR(i,0,b)
#define pb push_back

vi v; int n; bool sorted=1;

int main(){
  cin.tie(0)->sync_with_stdio(0);
  cin >> n; F0R(i,n){int x; cin >> x; v.pb(x);}
  while(1){
    F0R(i,n-1) if(v[i]>v[i+1]) {swap(v[i],v[i+1]); sorted=0;}
    if(sorted) break;
    sorted=1;
  }
  return 0;
}
