// a comprehensive list of gold algorithm/data structure implementations 

const int INF = 0x3f3f3f3f;

// the below are essential for point update range query type problems

// O(log n) update/query binary indexed tree (bit) aka fenwick
struct bit {
  
};

// O(log n) update/query segment tree (iterative implementation)
struct seg {
  int op(int a, int b) { return a + b; }
  const int op_identity = 0; // change op and op_identity to the desired associative operation
  int n; vector<int> tree;
  void init(int _n) { n = _n; tree.assign(2 * n, op_identity); }
  void upd(int p, int v) {
    tree[p += n] = v; // update replaces with new value
    for (p /= 2; p; p /= 2) tree[p] = op(tree[2 * p], tree[2 * p + 1]); 
  }
  int qry(int l, int r) {
    int qry_left = op_identity, qry_right = op_identity; 
    for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
      if (l & 1) qry_left = op(qry_left, tree[l++]); 
      if (r & 1) qry_right = op(tree[--r], qry_right);
    }
    return op(qry_left, qry_right);
  }
};

// the below are essential for graph problems
// all of these are for adjacency lists but can be easily modified for adjacency matrices if needed

int n, m; // # nodes, # edges
vector<vector<int>> u_adj; // use if graph unweighted
vector<vector<array<int, 2>>> adj; // use if graph weighted, where [0] is weight and [1] is adjacent node
// for shortest path algorithms, instead of a visited array, we can just check if dist is INF

// O(n + m) breadth first search (bfs) to find shortest path in unweighted graph
int bfs(int start, int end) {
  vector<int> dist(n, INF); 
  queue<int> todo; 
  todo.emplace(start); dist[start] = 0; 
  while (size(todo)) {
    int v = todo.front(); todo.pop();
    for (int u: u_adj[v]) if (dist[u] == INF) dist[u] = dist[v] + 1, todo.emplace(u); 
  }
  return dist[end];
}

// O(m log n) dijkstra to find shortest path in weighted graph where all weights >= 0
int dijkstra(int start, int end) {
  vector<int> dist(n, INF); 
  priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> todo; // min heap of arrays (weight, node)
  todo.emplace(array{dist[start] = 0, start}); 
  while (size(todo)) {
    auto [w, v] = todo.top(); todo.pop(); 
    if (dist[v] < w) continue; 
    for (auto [w_next, v_next]: adj[v]) if (dist[v_next] > w + w_next) todo.emplace(array{dist[v_next] = w + w_next, v_next}); 
  }
  return dist[end];
}
