#include <bits/stdc++.h>
using namespace std; 

//given items with value and weight, in quantity of either 0 or 1 (you can either use it once or not use), what's the max value you can get out of a knapsack
//space optimized (sliding window)

using pii = pair<int,int>;
#define f first
#define s second

vector<pii> items; int n; 
  //n items: val, weight

int knap; const int SZ = 1e5; 
  //knapsack size knap, max is SZ

int dp[2][SZ+5];
  //dp[i][j]: i is items up to (in sliding window of length 2), j is max tolerable weight
  //remember that we only have two window slots and must use modulo 2 indices (& 1 operations give modulo 2)
    //to remove this optimization, simply size the array back up and remove all & 1s in the code

int main() {
  cin >> n; items.resize(n + 1); 
  for(int i = 1; i <= n; ++i) cin >> items[i].f >> items[i].s;
    //get items (starting from 1) 
  
  cin >> knap; 
    //get knapsack size
  
  memset(dp, -0x3f, sizeof(dp)); //set dp to -INF for check max
  memset(dp[0], 0, sizeof(dp[0])); //base case: using the first 0 items only gives val 0
  
  for(int i = 0; i < n; ++i) //iterate over last item 
    for(int j = 0; j <= knap; ++j) { //iterate over max tolerable weight RN
      //we need to fill in dp[(i + 1) & 1][j] 
      
      if(items[i + 1].s > j) //if the next item is too much to fit
         dp[(i + 1) & 1][j] = dp[i & 1][j]; 
      
      else //otherwise, we can choose if we want to use it, based on the max value we CAN get
        dp[(i + 1) & 1][j] = max(dp[i & 1][j], dp[i & 1][j - items[i + 1].s] + items[i + 1].f); 
    }
  
  cout <<  dp[n & 1][knap] << "\n";
}
