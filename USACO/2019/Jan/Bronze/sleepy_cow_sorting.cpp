#include <bits/stdc++.h>
using namespace std; 

// compute the longest sorted suffix

int main() {
	cin.tie(0)->sync_with_stdio(0); 
	freopen("sleepy.in", "r", stdin); 
	freopen("sleepy.out", "w", stdout); 

	int n; 
	cin >> n; 
	vector<int> v(n); 
	for (int &t: v) cin >> t; 
	for (int i = n - 1; i > 0; --i)
		if (v[i - 1] > v[i]) { cout << i << "\n"; exit(0); }
	cout << "0\n";
}
