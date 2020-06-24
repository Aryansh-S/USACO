template<int SZ> struct LCA { //binary lifting O(n log n) init, O(log) qry, init after adding
  static const int BITS = 32-__builtin_clz(SZ);
  int N, R = 1, par[BITS][SZ], depth[SZ]; vi adj[SZ]; 
  /// INITIALIZE
  void add(int u, int v) { adj[u].pb(v), adj[v].pb(u); }
  void add_(int u, int v) { adj[u].pb(v); }
  void dfs(int u, int prv){
    depth[u] = depth[par[0][u] = prv]+1;
    trav(v,adj[u]) if (v != prv) dfs(v,u); }
  void init(int _N) {
    N = _N; dfs(R,0);
    FOR(k,1,BITS) FOR(i,1,N+1) 
    par[k][i] = par[k-1][par[k-1][i]];
  }
  // QUERY
  int getPar(int a, int b) {
    R0F(k,BITS) if (b&(1<<k)) a = par[k][a];
    return a; }
  int lca(int u, int v){
    if (depth[u] < depth[v]) swap(u,v);
    u = getPar(u,depth[u]-depth[v]);
    R0F(k,BITS) if (par[k][u] != par[k][v]) 
    u = par[k][u], v = par[k][v];
    return u == v ? u : par[0][u];
  }
  int dist(int u, int v) { // # edges on path
    return depth[u]+depth[v]-2*depth[lca(u,v)]; 
  }
};
