
template<class T, const bool VALS_IN_EDGES = 1, typename TREE = LSEG> struct HLD {
  const T ID = 0; T comb(T a, T b) { return a + b; }
  //n, root, external lazy segment tree
  
  int n, root;
  vector<vector<int>> adj;
  vector<int> par, siz, depth, next, pos, rpos;
  TREE &tr; 
  
  HLD(int root, int n, TREE &tr) : n(n), root(root), adj(n), par(n, -1), siz(n, 1), depth(n), next(n), pos(n), tr(tr) {
    this->root = next[root] = root;
  }
  void add(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  
  void dfs_sz(int u){
    if(par[u] != -1) adj[u].erase(find(adj[u].begin(), adj[u].end(), par[u]));
    for(auto &v: adj[u]){
      par[v] = u, depth[v] = depth[u] + 1;
      dfs_sz(v);
      siz[u] += siz[v];
      if(siz[v] > siz[adj[u][0]]) swap(v, adj[u][0]);
    }
  }
  void dfs_hld(int u){
    static int t = 0;
    pos[u] = t++;
    rpos.push_back(u);
    for(auto &v: adj[u]){
      next[v] = (v == adj[u][0] ? next[u] : v);
      dfs_hld(v);
    }
  }
  void init(){
    dfs_sz(root), dfs_hld(root);
  }
  
  const int shift = 1; 
  
  template<typename Process> void processpath(int u, int v, Process act){
    for(; next[u] != next[v]; v = par[next[v]]){
      if(depth[next[u]] > depth[next[v]]) swap(u, v);
      act(pos[next[v]], pos[v] + 1);
    }
    if(depth[u] > depth[v]) swap(u, v);
    act(pos[u] + VALS_IN_EDGES, pos[v] + 1);
  }
  void updpath(int u, int v, T val){
    processpath(u, v, [this, &val](int l, int r){ tr.upd(l, r + shift, val); });
  }
  void updsubtree(int u, T val){
    tr.upd(pos[u] + VALS_IN_EDGES, pos[u] + siz[u] + shift, val);
  }
  T qrypath(int u, int v){
    T res = ID; 
    processpath(u, v, [this, &res](int l, int r){res = comb(res, tr.qry(l, r + shift));});
    return res;
  }
  T qrysubtree(int u){
    return tr.qry(pos[u] + VALS_IN_EDGES, pos[u] + siz[u] + shift);
  }
};
