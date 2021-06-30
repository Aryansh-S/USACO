// efficient coordinate compression -- O(n log n) preprocessing with O(log n) lookup 
// much better than binary search trees and hashtables due to very little overhead
// sometimes referred to as a "reverse/inverted index" or "binary searching on the sorted array"

int main() {
	cin.tie(0)->sync_with_stdio(0); 
	int n; cin >> n; 
	vector<int> v(n); 
	for(int i = 0; i < n; ++i) cin >> v[i]; 
	auto cmp = v; 
	sort(begin(cmp), end(cmp)); 
	cmp.erase(unique(begin(cmp), end(cmp)), end(cmp)); 
	int cid = [&](int x) { return lower_bound(begin(cmp), end(cmp), x) - begin(cmp); }
	// cid gives compressed id
} 
