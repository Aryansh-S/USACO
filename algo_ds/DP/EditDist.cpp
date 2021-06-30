#include <bits/stdc++.h>
using namespace std; 

string a, b; int dp[5005][5005]; //(n + 1) x (m + 1) 

//for every prefix i of a and j of b, what is the
//edit distance to transform i into j

int main() {
	cin.tie(0)->sync_with_stdio(0); 
	cin >> a >> b; int n = a.size(), m = b.size(); 
	for(int i = 0; i <= n; ++i) dp[i][0] = i; //same as above
	for(int i = 0; i <= m; ++i) dp[0][i] = i; //base case: if len 0, just add all chars
	for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) { //for each of the mn prefix combos
		if(a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1]; //optimal substructure: last two chars same
		else dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}); //if not, just check for best of subcases -- delete, add, replace 
	}
	cout << dp[n][m] << "\n"; 
}
