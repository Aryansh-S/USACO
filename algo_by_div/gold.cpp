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

// O(log*(n)) get/unite disjoint set union (dsu) aka union find, essentially O(1)
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

// the below are essential for point update range query type problems (zero indexed, inclusive on both ends)

// O(log n) update/query sums fenwick aka binary indexed tree (bit)
struct fenwick {
  int n; vector<int> tree; 
  void init(int _n) { n = _n; tree.resize(n + 1); }
  void upd(int i, int x) {
    ++i; // guarantee zero indexing externally
    for (; i <= n; i += i & -i) tree[i] += x; 
  }
  int qry(int i) {
    ++i; // guarantee zero indexing externally
    int ret = 0; 
    for (; i > 0; i -= i & -i) ret += tree[i]; 
    return ret;
  }
  int qry(int l, int r) {
    return qry(r) - qry(l - 1);
  }
};

// O(log n) update/query associative operations segment tree (iterative implementation)
struct segtree {
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

// O(n log n) count inversions using any update/query data structure (common base for many complex problems)
int cnt_inv(const vector<int> &v) {
  // compress coordinates just in case
  auto v_ord = v; // order the unique elements in v
  sort(begin(v_ord), end(v_ord)); 
  v_ord.erase(unique(begin(v_ord), end(v_ord)), end(v_ord)); 
  vector<int> v_comp; // compress v based on v_ord
  for (int t: v) v_comp.emplace_back(lower_bound(begin(v_ord), end(v_ord), t) - begin(v_ord)); 
  // e.g., count inversions w/ fenwick
  int inv = 0; 
  fenwick occ; occ.init(size(v_ord) + 1); // make size >= max compressed element id + 1
  for (int t: v_comp) occ.upd(t, 1), inv += occ.qry(t + 1, occ.n - 1);
  return inv;
}

// the below are essential for graph problems
// all of these are for adjacency lists but can be easily modified for adjacency matrices if needed
// be careful about repeating edges! manipulate input to avoid them before using these algorithms

int n, m; // # nodes, # edges
vector<vector<int>> u_adj; // use if graph unweighted
vector<vector<pair<int, int>>> adj; // use if graph weighted, pairs (weight, node)
vector<vector<int>> dist; // use with floyd warshall

// for shortest path algorithms, instead of maintaining a visited array, we can just check distance conditions

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
    adj[a].emplace_back(w, b); // adds directed edge a->b with weight w
    // adj[b].emplace_back(w, a); // uncomment if undirected edge (adds directed edge b->a with weight w)
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
  using pii = pair<int, int>; // pairs (weight, node)
  priority_queue<pii, vector<pii>, greater<pii>> todo;
  todo.emplace(dist[start] = 0, start); 
  while (size(todo)) {
    auto [w, v] = todo.top(); todo.pop(); 
    if (dist[v] < w) continue; 
    for (auto [w_next, v_next]: adj[v]) if (dist[v_next] > w + w_next) todo.emplace(dist[v_next] = w + w_next, v_next); 
  }
  return dist[end];
}

// O(n^3) floyd warshall to find shortest path in weighted graph with no negative cycles
// never favorable over spfa but arguably easier to code, so...
int floyd(int start, int end) {
  // initially, set up dist as a weighted adjacency matrix such that dist[i][j] = edge ij if adjacent, else INF
  for (int k = 0; k < n; ++k) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) { // kij order
    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  }
  // now, dist[i][j] is the shortest path between i and j for all i, j
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

// O(m log m) kruskal minimum spanning tree (mst) using dsu
int kruskal() {
  vector<tuple<int, int, int>> edges; // (weight, start_node, end_node)
  for (int i = 0; i < n; ++i) for (auto [w, j]: adj[i]) edges.emplace_back(w, i, j);
  sort(begin(edges), end(edges)); // the slowest step (bottleneck), everything else is ~ O(m)
  dsu trees; trees.init(n); 
  int mst = 0, cnt = 0; // # iterations of loop below must be n - 1 (# edges in mst) for mst to exist
  for (auto [w, i, j]: edges) if (trees.unite(i, j)) mst += w, ++cnt;
  return cnt == n - 1 ? mst : INF;
}

// O(m log n) prim minimum spanning tree (mst) using a variation of dijkstra
int prim() {
  vector<int> edge(n, INF); // best edge for each node
  edge[0] = 0; // root at 0 (arbitrary)
  using pii = pair<int, int>; // pairs (weight, node)
  priority_queue<pii, vector<pii>, greater<pii>> todo;
  bool vis[(int)(2e5 + 5)] {}; // put at least max node + 1 in () 
  for (int i = 0; i < n; ++i) todo.emplace(edge[i], i);
  while (size(todo)) {
    auto [w, v] = todo.top(); todo.pop(); vis[v] = 1; 
    for (auto [w_next, v_next]: adj[v]) if (!vis[v_next] && edge[v_next] > w_next) todo.emplace(edge[v_next] = w_next, v_next);
  }
  int mst = 0, cnt = 0; // # iterations of loop below must be n - 1 (# edges in mst) for mst to exist
  for (int i = 1; i < n; ++i) if (edge[i] < INF) mst += edge[i], ++cnt;
  return cnt == n - 1 ? mst : INF;
}
