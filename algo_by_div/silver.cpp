// a comprehensive list of silver algorithm/data structure implementations 

// note: because sizes are unknown, these implementations use vectors instead of arrays. (except for vector<bool>s. those are weird...)
// in practice, you may also use arrays of max variable size.
// also, you may have to replace ints with long longs to prevent overflow in some cases



// the below are essential for graph problems (optional for bronze but necessary for silver)
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
