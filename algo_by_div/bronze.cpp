// a comprehensive list of bronze algorithm/data structure implementations 

// O(n) read data
void re(vector<int> &v) {
	int n; cin >> n; 
	v.resize(n); 
	for(int &t: v) cin >> t;
}

// O(n) write data
void pr(const vector<int> &v) {
	string s = "";
	for(int t: v) cout << s << t, s = " ";
	cout << "\n";
}

// O(n) complete search (returns leftmost idx if found and -1 otherwise)
int csearch(const vector<int> &v, const int x) {
	for(int i = 0; i < size(v); ++i) if(v[i] == x) return i; 
	return -1;
}

// O(1) check min (sets a to min(a, b) and returns true if change)
bool ckmin(auto &a, const auto b) { return a > b ? a = b, 1 : 0; } 

// O(n) running tally (e.g., min element overall)
int rmin(const vector<int> &v) {
	int m = v[0]; 
	for(int t: v) ckmin(m, t); 
	return m;
}

// O(n) get reverse index
auto ridx(const vector<int> &v) {
	vector<int> rv(2e5 + 5);
	for(int i = 0; i < size(v); ++i) rv[v[i]] = i;
	return rv;
}

// O(n^2) brute sort based on running mins (bronze alt to builtin O(n log n) sort)
void brsort(vector<int> &v) {
    for(int i = 0; i < size(v); ++i) {
        int idx = i; 
        for(int j = i; j < size(v); ++j) if(v[idx] > v[j]) idx = j;
        v.insert(begin(v) + i, v[idx]);
        v.erase(begin(v) + idx + 1);
    }
}

// O(n) recursion
void recur(const int n, int it = 0) {
	if(it < n) {
		cout << it << "\n";
		recur(n, ++it);
	}
}

// O(2^n) generate all subsets recursively
vector<int> subset;
void sub(const vector<int> &v, int idx = 0) {
	if(idx == size(v)) {
		// process subset
	}
	sub(v, idx + 1); 
	subset.emplace_back(v[idx]); 
	sub(v, idx + 1); 
	subset.pop_back();
}

// O(n!) generate all permutations
void perm(vector<int> v) {
	sort(begin(v), end(v)); 
	do {
		// process permutation
	} while(next_permutation(begin(v), end(v)));
}

// O(n log n) count distinct elements
int distcnt(vector<int> v) {
	sort(begin(v), end(v)); 
	v.erase(unique(begin(v), end(v)), end(v)); 
	return size(v); 
}
