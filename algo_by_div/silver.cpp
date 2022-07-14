// a comprehensive list of silver algorithm/data structure implementations 

// note: because sizes are unknown, these implementations use vectors instead of arrays. (except for vector<bool>s. those are weird...)
// in practice, you may also use arrays of max variable size.
// also, you may have to replace ints with long longs to prevent overflow in some cases

// O(n) two pointer search to find pair of indices in sorted array that satisfy a condition
array<int, 2> two_pointers(const vector<int> &v, int sum) {
	int l = 0, r = size(v) - 1; 
	while (l < r) {
		if (v[l] + v[r] == sum) return array{l, r}; 
		v[l] + v[r] < sum ? ++l : --r; 
	}
	return array{-1, -1};
}

// O(log n) binary search for first true element in monotonic search space defined by increasing function
int first_true(int lo, int hi, auto increasing_f) {
	++hi; assert(lo <= hi);
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2; 
		increasing_f(mid) ? hi = mid : lo = mid + 1; 
	}
	return lo; 
}

// O(log n) binary search for last true element in monotonic search space defined by decreasing function
int last_true(int lo, int hi, auto decreasing_f) {
	--lo; assert(lo <= hi);
	while (lo < hi) {
		int mid = lo + (hi - lo + 1) / 2; 
		decreasing_f(mid) ? lo = mid : hi = mid - 1; 
	}
	return lo;
}

// you can also use the builtin lower_bound, upper_bound, equal_range, and binary_search functions

// O(n log n) coordinate compress with O(log n) index queries
void compress(vector<int> &v) {
	sort(begin(v), end(v)); 
	v.erase(unique(begin(v), end(v)), end(v)); 
}
void get_compressed_idx(const vector<int> &compressed_v, int x) {
	return lower_bound(begin(compressed_v), end(compressed_v), x) - begin(compressed_v); 
}

// O(brute force each half * combine halves) meet in the middle 
// signal: constraint seems small but ~ 2x allowed brute force
// e.g., count num subsets of array with sum x
// specifically, divide array in half and generate subsets sums of each half
// then, loop over all subset sums y of one of the halves and binary search to find the number of x - y subset sums in the other half
// y + (x - y) = x, so we can combine these two sums to yield the desired sum x
// this is O(n * 2^(n/2)) overall
int meet_in_the_middle(const vector<int> &v, int x) {
	vector<int> v1, v2; // two halves
	vector<int> sum1, sum2; // corresponding sums
	for (int i = 0; i < size(v); ++i) i < size(v) / 2 ? v1.emplace_back(v[i]) : v2.emplace_back(v[i]); 
	// bitmask to generate subset sums for each half
	for (int mask = 0; mask < (1 << size(v1)); ++mask) {
		int tot = 0; 
		for (int i = 0; i < size(v1); ++i) if (mask & (1 << i)) tot += v1[i]; 
		sum1.emplace_back(tot);
	}
	for (int mask = 0; mask < (1 << size(v2)); ++mask) {
		int tot = 0; 
		for (int i = 0; i < size(v2); ++i) if (mask & (1 << i)) tot += v2[i]; 
		sum2.emplace_back(tot); 
	}
	sort(begin(sum1), end(sum1)), sort(begin(sum2), end(sum2)); 
	int ret = 0; 
	for (int y: sum1) ret += upper_bound(begin(sum2), end(sum2), x - y) - lower_bound(begin(sum2), end(sum2), x - y); 
	return ret;
}

// the below are essential for range query type problems involving sums (zero indexed, inclusive on both ends)

// O(n) prefix sums in one dimension
void psum_1d(vector<int> &v) { // equivalent to partial_sum(begin(v), end(v), begin(v))
	for (int i = 1; i < size(v); ++i) v[i] += v[i - 1];  
}

// O(1) query range sum after prefix sums in one dimension
int qsum_1d(const vector<int> &psum, int l, int r) {
	return l > 0 ? psum[r] - psum[l - 1] : psum[r]; 
}

// O(n) difference array in one dimension (fix one dimension and loop over the other to extend to two dimensions)
void delta_1d(vector<int> &v) { // equivalent to adjacent_difference(begin(v), end(v), begin(v))
	vector<int> diff;
	diff.emplace_back(v[0]);
	for (int i = 1; i < n; ++i) diff.emplace_back(v[i] - v[i - 1]);
	v = diff;
}

// O(row * col) prefix sums in two dimensions (padded -- adds extra row and col to avoid hellish corner cases)
void psum_2d(vector<vector<int>> &v) {
	vector<vector<int>> psum(size(v) + 1, vector<int>(size(v[0]) + 1));
	for (int i = 0; i < size(v); ++i) for (int j = 0; j < size(v[0]); ++j) { // principle of inclusion exclusion
		psum[i + 1][j + 1] = v[i][j] + psum[i + 1][j] + psum[i][j + 1] - psum[i][j]; 
	}
	v = psum; 
}

// O(1) query rectangle sum after prefix sums in two dimensions
int qsum_2d(const vector<vector<int>> &psum, int from_row, int from_col, int to_row, int to_col) {
	return psum[to_row + 1][to_col + 1] - psum[from_row][to_col + 1] - psum[to_row + 1][from_col] + psum[from_row][from_col];
}

// the below are essential for graph problems
// all of these are for adjacency lists but can be easily modified for adjacency matrices if needed

int n, m; // # nodes, # edges
vector<vector<int>> adj; // store graph as adjacency list
bool vis[(int)(2e5 + 5)]; // keep track of which nodes visited for dfs // put at least max node + 1 in ()
vector<int> cc; // assign connected component ids

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

// O(n + m) dfs to designate connected components
void dfs_cc(int v, int id) {
	vis[v] = 1, cc[v] = id; 
	// add code here to process v (remember that v + 1 is the actual node in problem bc we zero idx)
	for (int u: adj[v]) if (!vis[u]) dfs_cc(u, id); 
}

// O(n + m) floodfill to find connected components
void flood_cc() {
	cc.resize(n); 
	int id = 0;
	for (int i = 0; i < n; ++i) if (!vis[i]) dfs_cc(i, id++); 
}

// O(n + m) iterative dfs (optional but instructive on the use of stacks and a parallel for how bfs will use queues later)
void dfs_it(int start) {
	stack<int> todo; 
	todo.emplace(start); 
	while (size(todo)) {
		int v = todo.top(); todo.pop(); 
		vis[v] = 1; 
		// add code here to process v (remember that v + 1 is the actual node in problem bc we zero idx)
		for (int u: adj[v]) if (!vis[u]) todo.emplace(u);
	}
}
