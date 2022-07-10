#include <bits/stdc++.h>
using namespace std; 

int N;  
vector<vector<string>> prop;
int ans = 0;

int common(auto v1, auto v2) { // finds num common in O(n^2), slow but enough to pass
	int tot = 0; 
	for (auto i: v1) tot += (find(begin(v2), end(v2), i) != end(v2));
	return tot;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("guess.in", "r", stdin); 
	freopen("guess.out", "w", stdout);
	
	cin >> N;
	prop.resize(N); 
	for (int i = 0; i < N; ++i) {
		string s; int num; 
		cin >> s >> num; 
		while (num--) cin >> s, prop[i].emplace_back(s);
	}
	for (int i = 0; i < N; ++i) for (int j = 0; j < i; ++j) 
		ans = max(ans, common(prop[i], prop[j]) + 1);
	cout << ans << "\n";
}
