#include <bits/stdc++.h>
using namespace std; 

//each item type has a value and a weight and exists in infinite quantity, find the most value you can get out of a knapsack of certain weight

using pii = pair<int,int>; 
#define f first
#define s second

vector<pii> items; int n;
  //n items: val, weight

int knap; const int SZ = 1e5; 
  //weight of knapsack, at most 1e5

int dp[SZ+5]; 
  //store a value for each weight state up to SZ

int main() {
  cin >> n; items.resize(n);
  for(int i = 0; i < n; ++i) cin >> items[i].f >> items[i].s;
    //get in items
  
  cin >> knap;
    //get in knapsack max weight
  
  memset(dp, -0x3f, sizeof(dp)); //start with -INF for checking max
  dp[0] = 0; //base case state: weight 0 dp, i.e. dp[0], has 0 value 
  
  for(int w = 0; w < knap; ++w) //iterate thru weight states w
    for(int t = 0; t < n; ++t) //iterate thru possible transitions t on weight state w, adding an item
      dp[w + items[t].s] = max(dp[w + items[t].s], items[t].f + dp[w]); //see if value can be optimized further given this transition's result
  
  cout << dp[knap] << "\n";
}
