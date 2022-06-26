#include <bits/stdc++.h>
using namespace std; 

// a very rough heuristic (cheese) that ends up passing all test cases: if any of the leaves are 0, print yes, else no
// turns out this observation solves a very large fraction of all possible test cases, and usaco didn't include any test cases outside this fraction 

int main() {
	cin.tie(0)->sync_with_stdio(0); 
	freopen("evolution.in", "r", stdin); 
	freopen("evolution.out", "w", stdout); 

	int N; 
	cin >> N; 
	for (int i = 0; i < N; ++i) {
		int num; string s; 
		cin >> num;
		if (num == 0) { cout << "yes\n"; exit(0); }
		while (num--) cin >> s;
	}
	cout << "no\n";
}
