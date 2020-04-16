#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi; 
#define FOR(i,a,b) for(__typeof(b)i=(a)-((a)>(b));i!=(b)-((a)>(b));i+=((a)>(b))?-1:1) //go from i=lb to i=ub-1
#define F0R(i,b) FOR(i,0,b)
#define all(x) begin(x),end(x)
#define pb push_back

vi v; int n; 

int main(){
  cin >> n; F0R(i,n){int x; cin >> x; v.pb(x);}
  sort(all(v)); //sorts in O(n log n)
  return 0;
}
