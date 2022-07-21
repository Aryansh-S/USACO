// a comprehensive list of silver algorithm/data structure implementations

// note: because sizes are unknown, these implementations use vectors instead of arrays. (except for vector<bool>s. those are weird...)
// in practice, you may also use arrays of max variable size.
// also, you may have to replace ints with long longs to prevent overflow in some cases

// O(n log n) builtin sorting based on custom comparator function
// e.g., sort vector<array<int, 2>> by second element of array<int, 2> instead of first
// some ppl just insert elements backwards or do weird stuff to avoid custom comparators, but please don't :/ -- it makes your code confusing
void sort_by_second(vector<array<int, 2>> &v) {
	auto cmp = [](const auto &a, const auto &b) { return a[1] < b[1]; }; // comparator function by second element
	sort(begin(v), end(v), cmp);
	// you can also use cmp for a data structure, but the syntax is a bit trickier; e.g.: 
	// set<array<int, 2>, decltype(cmp)> s(cmp); s.emplace(array{1, 1}), s.emplace(array{2, 0});
	// then s contains array{2, 0} and array{1, 1} in that order
}

// O(n) two pointer search to find pair of indices in sorted array that satisfy a condition
// e.g., suppose we want to find pair of indices with elements that sum to a particular value
array<int, 2> two_pointers(const vector<int> &v, int sum) {
	for (int l = 0, r = size(v) - 1; l < r; v[l] + v[r] < sum ? ++l : --r) 
		if (v[l] + v[r] == sum) return array{l, r};
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

// O(brute force each half + combine halves) meet in the middle 
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
// be careful about repeating edges! manipulate input to avoid them before using these algorithms

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

// O(row * col) dfs through a grid (grids suck, this makes your life easy)
vector<vector<char>> g; 
bool vis[2005][2005]; // put at least max row/col + 1 in []
bool can_visit(int i, int j) {
	if (i < 0 || i >= size(g) || j < 0 || j >= size(g[0])) return 0; // out of bounds
	// if (g[i][j] == 'x') return 0; // uncomment to check for grid obstacles
	return !vis[i][j]; // if all else works, can visit if not yet visited
}
void dfs_grid(int i, int j) {
	vis[i][j] = 1; 
	// add code here to process cell (i, j)
	for (int di: {-1, 0, 1}) for (int dj: {-1, 0, 1}) if (abs(di + dj) == 1)
		if (can_visit(i + di, j + dj)) dfs_grid(i + di, j + dj);
}

// O(n log n) sweep line algorithms
// suppose you have n geometric objects (most commonly points/line segments) that exist in some geometric space (most commonly a line/plane)
// and you want to check some property among pairs of these objects 
// (e.g., given a bunch of points, find the smallest distance between any pair of them; or, given a bunch of line segments, find the number of 
// intersection points)
// we can easily brute force these kinds of problems in O(n^2): naively check the property for each of the O(n^2) pairs of objects
// however, in silver, typically n <= 10^5 for these kinds of problems, so we can afford O(n log n) at most. to achieve this, we use sweep line!
// the idea at the crux of sweep line is to first sort the data (e.g., an array of the geometric objects) by one dimension in O(n log n)
// and then take advantage of the sortedness as we process the data from left to right using some data structure 
// in silver, this data structure is almost always a set with a custom comparator to account for the second dimension of the data
// called the "active set"
// in particular, processing will consist of O(log n) updates (adding/removing an object from the active set) 
// and O(log n) queries (binary searching the active set to make decisions based on the second dimension of the data)
// but in the processing part of our algorithm overall, each object will be added and removed from the active set exactly once, giving us O(n log n)
// so because both the sorting and processing steps each take O(n log n) time, the overall algorithm is O(n log n) as desired
// it seems impractical to generalize sweep line -- the processing part of the algorithm will be slightly different each time depending on the problem
// -- so instead I've provided some implementations of common problems below
// as you read them, make sure you can clearly trace out the logic described in the comments above

// O(n log n) smallest distance between any pair of points
double smallest_dist_bw_any_pair(vector<array<int, 2>> v) {
	sort(begin(v), end(v)); 
	auto cmp = [](const auto &a, const auto &b) { return a[1] < b[1]; };
	set<array<int, 2>, decltype(cmp)> active(cmp); // active set (sorted by second dimension)
	double d = INF;
	int idx = 0; // track point index to erase next (so we only erase each point once)
	for (auto [x, y]: v) {
		while (x - v[idx][0] >= d) active.erase(v[idx++]); // remove any points >= d to the left of (x, y) that remain in the active set
		for (auto it = active.lower_bound(array{x, y - (int)ceil(d)}); it != active.upper_bound(array{x, y + (int)ceil(d)}); ++it)
			// within the vertical window of points <= d above or below (x, y), try to minimize d
			d = min(d, sqrt(((*it)[0] - x) * ((*it)[0] - x) + ((*it)[1] - y) * ((*it)[1] - y)));
		active.emplace(array{x, y}); // update active set with new point for next time
	}
	return d; 
}

// O(n log n) count line segment intersections
int cnt_line_seg_isect(vector<array<int, 4>> v) { // each segment array{x1, y1, x2, y2} is from point (x1, y1) to point (x2, y2)
}
