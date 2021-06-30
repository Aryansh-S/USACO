#include <bits/stdc++.h>
using namespace std; 

const int INF = 0x3f3f3f3f; 
int dp[505][505], a, b; 

int sol(int x, int y) {
	if(dp[x][y] < INF) return dp[x][y]; 
	for(int i = 1; i < x; ++i) dp[x][y] = min(dp[x][y], 1 + sol(i, y) + sol(x - i, y)); 
	for(int i = 1; i < y; ++i) dp[x][y] = min(dp[x][y], 1 + sol(x, i) + sol(x, y - i)); 
	return dp[x][y]; 
}

int main() {
	cin.tie(0)->sync_with_stdio(0); 
	memset(dp, 0x3f, sizeof(dp)); 
	for(int i = 1; i < 505; ++i) dp[i][i] = 0; 
	cin >> a >> b; cout << sol(a, b) << "\n"; 
}
