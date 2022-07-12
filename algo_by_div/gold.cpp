// a comprehensive list of gold algorithm/data structure implementations 

const int INF = 0x3f3f3f3f;

// note: because sizes are unknown, these implementations use vectors instead of arrays. (except for vector<bool>s. those are weird...)
// in practice, you may also use arrays of max variable size.
// also, you may have to replace ints with long longs to prevent overflow in some cases

// O(|small set| log |large set|) small to large merging of sets
void merge_sets(set<int> &a, set<int> &b) { // efficiently merges b into a
  if (size(a) < size(b)) swap(a, b); 
  for (int t: b) a.emplace(t);
}

// O(log*(n)) ~ O(1) get/unite disjoint set union (dsu) aka union find
struct dsu {
  vector<int> par; // stores node parent or else negative comp size
  void init(int n) { par.assign(n, -1); }
  void get(int i) { return par[i] < 0 ? i : par[i] = get(par[i]); } // get component using path compression
  int size(int i) { return -par[get(i)]; }
  bool unite(int i, int j) { // unite by size, false if already united
    i = get(i), j = get(j); 
    if (i == j) return 0; 
    if (par[i] > par[j]) swap(i, j); 
    par[i] += par[j]; par[j] = i; 
    return 1;
  }
};

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

// O(log n) update/query order statistics tree (like a set/map but with indices!)
// functions: find_by_order() and order_of_key()
// only works on true gcc compilers (supported by most platforms, including USACO and Codeforces)
// but you may have to install a true gcc compiler separately through a package manager (e.g., Homebrew) to make it work
// include the below lines in your code and refer to https://codeforces.com/blog/entry/11080 for use
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<class T, class U = null_type, class cmp = less<T>> using oset = tree<T, U, cmp, rb_tree_tag, tree_order_statistics_node_update>;

// the below are essential for graph problems
// all of these are for adjacency lists but can be easily modified for adjacency matrices if needed

int n, m; // # nodes, # edges
vector<vector<int>> u_adj; // use if graph unweighted
vector<vector<array<int, 2>>> adj; // use if graph weighted, where [0] is weight and [1] is adjacent node
// for shortest path algorithms, instead of maintaining a visited array, we can just check conditions in dist

// O(n + m) construct graph in unweighted adjacency list format from edges
void read_u_adj_list() {
  u_adj.resize(n);
  for (int i = 0; i < m; ++i) {
    int a, b; // nodes in edge
    cin >> a >> b; 
    --a, --b; // zero idx nodes
    u_adj[a].emplace_back(b); // adds directed edge a->b
    // u_adj[b].emplace_back(a); // uncomment if undirected edge (adds directed edge b->a)
  }
}

// O(n + m) construct graph in weighted adjacency list format from edges
void read_adj_list() {
  adj.resize(n); 
  for (int i = 0; i < m; ++i) {
    int a, b, w; // nodes in edge with weight
    cin >> a >> b >> w; 
    --a, --b; // zero idx nodes
    adj[a].emplace_back(array{w, b}); // adds directed edge a->b with weight w
    // adj[b].emplace_back(array{w, a}); // uncomment if undirected edge (adds directed edge b->a with weight w)
  }
}

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

// O(n^3) floyd warshall to find shortest path in weighted graph with no negative cycles
int floyd(int start, int end) {
  vector<vector<int>> dist(n, vector<int>(n, INF));
  for (int i = 0; i < n; ++i) {
    dist[i][i] = 0;
    for (auto [w, j]: adj[i]) dist[i][j] = min(dist[i][j], w); 
  }
  for (int k = 0; k < n; ++k) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) { // kij order
    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  }
  return dist[start][end];
}

// O(nm) shortest path faster algorithm (spfa) to find shortest path in weighted graph with no negative cycles
// experimentally ~ O(m) for a random graph, essentially optimized bellman ford for average case 
// see https://en.wikipedia.org/wiki/Shortest_Path_Faster_Algorithm for more details 
// (yes, you can slightly optimize this with a deque and a million other things, but that's unnecessary imo)
int spfa(int start, int end) {
  vector<int> dist(n, INF); 
  queue<int> todo; 
  bool inq[(int)(2e5 + 5)] {}; // currently in queue? // put at least max node + 1 in ()
  todo.emplace(start); dist[start] = 0; inq[start] = 1; 
  while (size(todo)) {
    int v = todo.front(); todo.pop(); inq[v] = 0;
    for (auto [w, u]: adj[v]) if (dist[u] > dist[v] + w) {
      dist[u] = dist[v] + w; 
      if (!inq[u]) todo.emplace(u), inq[u] = 1;
    }
  }
  return dist[end];
}
