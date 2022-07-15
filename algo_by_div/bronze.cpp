// a comprehensive list of bronze algorithm/data structure implementations 

// note: because sizes are unknown, these implementations use vectors instead of arrays. (except for vector<bool>s. those are weird...)
// in practice, you may also use arrays of max variable size.
// also, you may have to replace ints with long longs to prevent overflow in some cases

// O(1) set up io for competitive programming -- fast optimization, uncomment line for file io (useful for past problems)
void io() {
	cin.tie(0)->sync_with_stdio(0); // only use if offline processing allowed (true for all bronze), remove for interactive problems
	// if (fopen("name.in", "r")) freopen("name.in", "r", stdin), freopen("name.out", "w", stdout);
}

// O(n) read data
void re(vector<int> &v) {
	int n; cin >> n; 
	v.resize(n); 
	for (int &t: v) cin >> t;
}

// O(n) write data
void pr(const vector<int> &v) {
	for (int t: v) cout << t << "\n";
}

// O(n) complete search (returns leftmost idx if found and -1 otherwise)
int csearch(const vector<int> &v, const int x) {
	for (int i = 0; i < size(v); ++i) if (v[i] == x) return i; 
	return -1;
}

// O(1) check min (sets a to min(a, b) and returns true if change), flip > to < for ckmax
bool ckmin(auto &a, const auto b) { return a > b ? a = b, 1 : 0; } 

// O(n) running tally (e.g., min element overall)
int rmin(const vector<int> &v) {
	int m = v[0]; 
	for (int t: v) ckmin(m, t); 
	return m;
}

// O(n) get reverse index -- store index given value for quick lookup without having to complete search
vector<int> ridx(const vector<int> &v) {
	vector<int> rv(2e5 + 5); // put at least max element + 1 in ()
	// assumes all elements integers >= 0, so make the necessary corrections (e.g., subtract min element) or use a (hash)map
	for (int i = 0; i < size(v); ++i) rv[v[i]] = i;
	return rv;
}

// O(n^2) brute sort based on running mins (bronze alt to builtin O(n log n) sort)
void brsort(vector<int> &v) {
    for (int i = 0; i < size(v); ++i) {
        int idx = i; 
        for (int j = i; j < size(v); ++j) if(v[idx] > v[j]) idx = j;
        v.emplace(begin(v) + i, v[idx]);
        v.erase(begin(v) + idx + 1);
    }
}

// O(n) recursion
void recur(const int n, int it = 0) {
	if (it < n) {
		cout << it << "\n";
		recur(n, ++it);
	}
}

// O(n * 2^n) construct all subsets recursively
vector<int> subset;
void sub_rec(const vector<int> &v, int idx = 0) {
	if (idx == size(v)) {
		// process subset
	}
	sub_rec(v, idx + 1); 
	subset.emplace_back(v[idx]); 
	sub_rec(v, idx + 1); 
	subset.pop_back();
}

// O(n * 2^n) process all subsets iteratively (bitmasking), construction optional
void sub_it(const vector<int> &v) {
	// vector<int> subset; // uncomment to construct subset (optional)
	for (int mask = 0; mask < (1 << size(v)); ++mask) {
		for (int i = 0; i < size(v); ++i) if (mask & (1 << i)) {
			// subset.emplace_back(v[i]); // uncomment to construct subset (optional)
			// process subset without construction here
		}
		// process subset after construction here
		// subset.clear(); // reset construction
	}
}

// O(n!) generate all permutations (yes, you can do this recursively like sub_rec but what's the point? it's builtin)
void perm(vector<int> v) {
	sort(begin(v), end(v)); 
	do {
		// process permutation
	} while (next_permutation(begin(v), end(v)));
}

// O(n) count distinct elements using visited array
int distcnt_vis(vector<int> v) {
	bool vis[(int)(2e5 + 5)] {}; // put at least max element + 1 in ()
	// assumes all elements integers >= 0, so make the necessary corrections (e.g., subtract min element) or use a (hash)map
	for (int t: v) vis[t] = 1;
	int ans = 0;
	for (bool t: vis) ans += t;
	return ans;
}

// O(n log n) count distinct elements using sorting
int distcnt_sort(vector<int> v) {
	sort(begin(v), end(v)); 
	v.erase(unique(begin(v), end(v)), end(v)); 
	return size(v); 
}

// O(n log n) count distinct elements using set
int distcnt_set(vector<int> v) {
	set<int> s;
	for (int t: v) s.emplace(t); 
	return size(s);
}

// O(1) update/lookup hash table (like an unordered set/map but much faster!) 
// functions: same as unordered_set or unordered_map
// only works on true gcc compilers (supported by most platforms, including USACO and Codeforces)
// but you may have to install a true gcc compiler separately through a package manager (e.g., Homebrew) to make it work
// include the below lines in your code and refer to https://codeforces.com/blog/entry/60737 for use
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T, class U = null_type, class chash = hash<T>> using hset = gp_hash_table<T, U, chash>;
// to make it even faster, construct with an initial capacity that's a power of 2: hset<int> h({}, {}, {}, {}, {1 << 13}); 
// for Codeforces, change chash to avoid getting hacked!

// the below are optional but useful for the occasional bronze graph problems
// be careful about repeating edges! manipulate input to avoid them before using these algorithms

int n, m; // # nodes, # edges
vector<vector<int>> adj; // store graph as adjacency list
bool vis[(int)(2e5 + 5)]; // keep track of which nodes visited for dfs // put at least max node + 1 in ()

// O(n + m) construct graph in adjacency list format from edges
void read_adj_list() {
	adj.resize(n);
	for (int i = 0; i < m; ++i) {
		int a, b; // nodes in edge
		cin >> a >> b; 
		--a, --b; // zero idx nodes
		adj[a].emplace_back(b); // adds directed edge a->b
		// adj[b].emplace_back(a); // uncomment if undirected edge (adds directed edge b->a)
	}
}

// O(n + m) do depth first search (dfs) of graph modeled by adjacency list
void dfs(int v) { // initiate by calling dfs(starting_node)
	vis[v] = 1;
	// add code here to process v (remember that v + 1 is the actual node in problem bc we zero idx)
	for (int u: adj[v]) if (!vis[u]) dfs(u); 
}
