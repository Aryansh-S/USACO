#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f, SZ = 1e5;

vector<int> vals; 
  //which coin vals can we use to make change?
int dp[SZ], how_many, val_to_make; 
  //state: value making; trans: take coin; ans: min coins needed

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> how_many;
  while(how_many--) { int x; cin >> x; vals.emplace_back(x); }
  cin >> val_to_make;
  memset(dp, INF, sizeof(dp)); dp[0] = 0;
  for(int i = 0; i < SZ; ++i) for(int v: vals) dp[i + v] = min(dp[i + v], dp[i] + 1); 
    //for each state, transition out
  out(dp[val_to_make]); 
    //output ans of desired state
}
