#include <bits/stdc++.h>
using namespace std; 

int N;  
vector<vector<string>> prop;
int ans = 0;

int common(auto v1, auto v2) { // finds num common in O(n log n) rather than O(n^2), using merging and sorting 
	// PIE: |v1 isect v2| = |v1| + |v2| - |v1 union v2|
	int tot = size(v1) + size(v2);
	// now, we will change v2 into v1 union v2 by merging the vectors and keeping only distinct elements
	for (auto i: v1) v2.emplace_back(i); 
	sort(begin(v2), end(v2)); 
	v2.erase(unique(begin(v2), end(v2)), end(v2));
	tot -= size(v2); 
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
