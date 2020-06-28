//Merge Sort Tree for Subarray Existence Queries
  //Can even be used with HLD for existence queries of a node/edge in a tree path

template<class T0> struct SEG { //merge sort tree
    using T = vector<T0>; //each node is a vector
    
    //#define DYNAMIC	
    const T0 ID = 0; 
    const T IDv = {}; T combv(T a, T b) { T ret; merge(all(a),all(b),back_inserter(ret)); return ret; }
    T0 comb(T0 a, T0 b) { return a || b; }
	
    int n; 
    
    #ifndef DYNAMIC
        vector<T> seg;
    #else
        hmap<ll, T> seg; 
    #endif

    T get(int p) {
        #ifndef DYNAMIC
            return seg[p]; 
        #else
            return seg.find(p) == end(seg) ? IDv : seg[p];
        #endif
    }

    void init(int n0) { 
        n = n0; 
        #ifndef DYNAMIC
            seg.assign(2 * n, IDv); 
        #endif
    }

    #ifndef DYNAMIC    
	    template<typename it, typename = typename enable_if<is_iterator<it>::value>::type> 
	    void init(it bg, it nd) { init(distance(bg, nd)); move(bg, nd, begin(seg) + n); build(); }
    #endif

    void build() { int i = n - 1; do pull(i); while(--i); }

    inline int lc(int p) { return 2 * p; }
    inline int rc(int p) { return lc(p) + 1; }
    
    void pull(int p) { seg[p] = combv(get(lc(p)), get(rc(p))); }
    
    void upd(int p, T0 v) { //point update the value at index p to v
      seg[p += n] = (T){v};  
      for(p /= 2; p; p /= 2) pull(p);
    }
    T0 qry(int l, int r, T0 x) { //query for the existence of x in [l,r]
      T0 ret = 0; 
      for(l += n, r += n + 1; l < r; l /= 2, r /= 2) {
          if(l & 1) {
            auto L = get(l++); 
            ret = comb(ret,binary_search(all(L),x)); 
          }
          if(r & 1) {
            auto R = get(--r); 
            ret = comb(ret,binary_search(all(R),x));
          }
      }
      return ret;
    }
};

//Example with HLD: 

/*
template<int SZ, bool EDGE = 1> struct HLD { //add all edges, then init
  
  //#define RANGE_UPD //range updates? uses LSEG if defined; otherwise SEG
  
  vector<int> adj[SZ], rpos; //rpos not used, but could be useful
  int par[SZ], root[SZ], depth[SZ], siz[SZ], pos[SZ]; 
  int ti;
  
  void add(int x, int y) { adj[x].pb(y), adj[y].pb(x); }
  void init(int R = 0) {
    par[R] = depth[R] = ti = 0; dfsSz(R); 
    root[R] = R; dfsHld(R); 
  }
  
  #ifndef DYNAMIC
    template<typename it, typename = typename enable_if<is_iterator<it>::value>::type>
    void putnodes(it bg, it nd) { //use with node version as convenient
      tree.init(bg, nd); 
    }
  #endif
    
  #ifndef RANGE_UPD
    using T = int; //use for type if no range, otherwise change type within LSEG
  #endif
  
  #ifdef RANGE_UPD
    LSEG tree; using T = LSEG::Q;
    const T ID = tree.id.second; 
    T comb(T a, T b) { return tree.qop(a, LSEG::R(), b, LSEG::R()); } //T is query type
    HLD() : tree(SZ) {}
  #else
    SEG<T> tree; 
    const T ID = tree.ID; 
    T comb(T a, T b) { return tree.comb(a, b); }
    HLD() { tree.init(SZ); }
  #endif
  
  void dfsSz(int x) { 
    siz[x] = 1; 
    trav(y, adj[x]) {
      par[y] = x; depth[y] = depth[x]+1;
      adj[y].erase(find(all(adj[y]), x)); //remove parent from adj list
      dfsSz(y); siz[x] += siz[y];
      if(siz[y] > siz[adj[x][0]]) swap(y, adj[x][0]);
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
  int dist(int x, int y) { //# edges on path
    return depth[x] + depth[y] - 2 * depth[lca(x,y)]; 
  }

  template<typename fnc> void processPath(int x, int y, fnc&& op) {
      for(; root[x] != root[y]; y = par[root[y]]) {
        if(depth[root[x]] > depth[root[y]]) swap(x, y);
        op(pos[root[y]], pos[y]); 
      }
      if(depth[x] > depth[y]) swap(x,y);
      op(pos[x] + EDGE, pos[y]); 
  }
  
  #ifdef RANGE_UPD
    void updpath(int x, int y, int v) { 
        processPath(x,y,[this,&v](int l, int r) { 
        tree.upd(l,r,v); }); 
    }
  #else
    void upd(int x, int v) { //update a single node 
        processPath(x,x,[this,&v](int l, int r) { 
        tree.upd(l,v); }); 
    }
  #endif
  T qrypath(int x, int y, int m) { 
      T res = ID; processPath(x,y,[this,&res,&m](int l, int r) { 
      res = comb(res,tree.qry(l,r,m)); });
      return res; 
  }
  #ifdef RANGE_UPD
    void updsubtree(int x, int v) { 
        tree.upd(pos[x] + EDGE, pos[x] + siz[x] - 1, v); 
    }
  #endif
  T qrysubtree(int x) {
      return tree.qry(pos[x] + EDGE, pos[x] + siz[x] - 1);
  }
};

int main() {
  h.add(0,1),h.add(1,2); h.init(); h.upd(1,10); h.upd(0,100); assert(h.qrypath(0,2,100)==1); assert(h.qrypath(0,2,1)==0);  
}
*/
