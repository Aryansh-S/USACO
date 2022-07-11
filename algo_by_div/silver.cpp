// a comprehensive list of silver algorithm/data structure implementations 



// the below are essential for graph problems (optional for bronze but necessary for silver)
// all of these are for adjacency lists but can be easily modified for adjacency matrices if needed

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

// O(n + m) floodfill
void flood() {
	for (int i = 0; i < n; ++i) if (!vis[i]) dfs(i); 
	// visits all nodes in graph by dfsing from each node not visited
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
