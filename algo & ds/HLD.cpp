// Newest HLD -- Well-Tested & Generalized

template<int SZ, bool EDGE = 1> struct HLD { //get LSEG; add all edges, then init
  vector<int> adj[SZ]; 
  int par[SZ], root[SZ], depth[SZ], siz[SZ], pos[SZ], rpos[SZ]; //rpos not used, but could be useful
  int ti;
  
  void add(int x, int y) { adj[x].pb(y), adj[y].pb(x); }
  void init(int R = 0) {
    par[R] = depth[R] = ti = 0; dfsSz(R); 
    root[R] = R; dfsHld(R); 
  }

  LSEG tree; using T = LSEG::Q;
  const T ID = tree.id.second; 
  T comb(T a, T b) { return tree.qop(a, {0,0}, b, {0,0}); } //T is query type
  HLD() : tree(SZ) {}
  
  void dfsSz(int x) { 
    siz[x] = 1; 
    trav(y,adj[x]) {
      par[y] = x; depth[y] = depth[x]+1;
      adj[y].erase(find(all(adj[y]),x)); // remove parent from adj list
      dfsSz(y); siz[x] += siz[y];
      if(siz[y] > siz[adj[x][0]]) swap(y,adj[x][0]);
    }
  }
  void dfsHld(int x) {
    pos[x] = ti++; rpos.pb(x);
    trav(y,adj[x]) {
      root[y] = (y == adj[x][0] ? root[x] : y);
      dfsHld(y); 
    }
  }
  int lca(int x, int y) {
    for(; root[x] != root[y]; y = par[root[y]])
      if(depth[root[x]] > depth[root[y]]) swap(x,y);
    return depth[x] < depth[y] ? x : y;
  }
  int dist(int x, int y) { // # edges on path
    return depth[x]+depth[y]-2*depth[lca(x,y)]; 
  }

  template<typename fnc> void processPath(int x, int y, fnc&& op) {
      for(; root[x] != root[y]; y = par[root[y]]) {
        if(depth[root[x]] > depth[root[y]]) swap(x,y);
        op(pos[root[y]],pos[y]); 
      }
      if(depth[x] > depth[y]) swap(x,y);
      op(pos[x]+EDGE,pos[y]); 
  }
  void updpath(int x, int y, int v) { 
      processPath(x,y,[this,&v](int l, int r) { 
      tree.upd(l,r,v); }); 
  }
  T qrypath(int x, int y) { 
      T res = ID; processPath(x,y,[this,&res](int l, int r) { 
      res = comb(res,tree.qry(l,r)); });
      return res; 
  }
  void updsubtree(int x, int v) { 
      tree.upd(pos[x] + EDGE, pos[x] + siz[x] - 1, v); 
  }
  T qrysubtree(int x) {
      return tree.qry(pos[x] + EDGE, pos[x] + siz[x] - 1);
  }
};
