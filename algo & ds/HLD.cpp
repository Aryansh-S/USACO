// Newest HLD (Well-Tested)
// possible todo: extend to arbitrary root

template<class T, bool EDGE = 1> struct HLD { //get LSEG
  //constructor: provide graph as adj list
  vector<int> parent, heavy, depth, root, treePos; int SZ; 
  
  LSEG tree; //T must be same as qry type
  const T ID = tree.id.second; 
  T comb(T a, T b) { return tree.qop(a, {0,0}, b, {0,0}); } //T is query type
  
  #define n adj.size()
  
  template<typename G> HLD(const G& adj): SZ(n), parent(n), heavy(n,-1), depth(n), root(n), treePos(n), tree(n) {
    parent[0] = -1; 
    depth[0] = 0;
    dfs(adj, 0);
    for (int i = 0, currentPos = 0; i < n; ++i)
    if (parent[i] == -1 || heavy[parent[i]] != i)
    for (int j = i; j != -1; j = heavy[j]) {
      root[j] = i;
      treePos[j] = currentPos++;
    }
  }
  
  template<typename G> int dfs(const G& adj, int v) {
    int size = 1, maxSubtree = 0;
    for (int u : adj[v]) if (u != parent[v]) {
      parent[u] = v;
      depth[u] = depth[v] + 1;
      int subtree = dfs(adj, u);
      if (subtree > maxSubtree) heavy[v] = u, maxSubtree = subtree;
      size += subtree;
    }
    return size;
  }
  
  template<typename fnc> void processPath(int u, int v, fnc&& op) {
    for (; root[u] != root[v]; v = parent[root[v]]) {
      if (depth[root[u]] > depth[root[v]]) swap(u, v);
      op(treePos[root[v]], treePos[v] + 1);
    }
    if (depth[u] > depth[v]) swap(u, v);
    op(treePos[u] + EDGE, treePos[v]);
  }
  
  void updpath(int u, int v, const T& value) {
    processPath(u, v, [this, &value](int l, int r) { tree.upd(l, r, value); });
  }
  void updsubtree(int u, const T& value) {
    tree.upd(treePos[u] + EDGE, treePos[u] + heavy[u] + 1, value); 
  }
  T qrypath(int u, int v) {
    T res = ID; 
    processPath(u, v, [this, &res](int l, int r) { res = comb(res,tree.qry(l, r)); });
    return res;
  }
  T qrysubtree(int u) {
    return tree.qry(treePos[u] + EDGE, treePos[u] + heavy[u] + 1);
  }
  
  #undef n
};
