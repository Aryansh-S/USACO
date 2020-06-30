//Merge Sort Tree, Insertion & Deletion

template<class T, int SZ> struct MBIT { //merge sort bit (zero indexed!)
	OST<pair<T, int>> val[SZ + 1]; 
	void upd(int x, T y, int t = 1) { //0 del, 1 ins -- put y at index x
    		++x;
		for(int X = x; X < SZ; X += X&-X) {
			if(t == 1) val[X].ins({y,x});
			else val[X].ers({y,x});
		}
	}
	int qryd(int i, T a) {
		int res = 0; 
		for(; i; i -= i&-i) res += val[i].ook({a,MOD});
		return res;
	}
	int qry(int i, int j, T a, T b) { //in subarray [i,j], how many are in range [a,b]
    		++i,++j;
		return qryd(j,b)-qryd(j,a-1)-qryd(i-1,b)+qryd(i-1,a-1); 
	}
};

//example with HLD
/*template<int SZ, bool EDGE = 1> struct HLD { //add all edges, then init
  
  //#define RANGE_UPD //range updates? uses LSEG if defined; otherwise SEG
  
  //#define OTHER_DS //use a DS other than segtree? fenwick,etc.
  
  vector<int> adj[SZ], rpos; //rpos not used, but could be useful
  int par[SZ], root[SZ], depth[SZ], siz[SZ], pos[SZ]; 
  int ti;
  
  void add(int x, int y) { adj[x].pb(y), adj[y].pb(x); }
  void init(int R = 0) {
    par[R] = depth[R] = ti = 0; dfsSz(R); 
    root[R] = R; dfsHld(R); 
  }
  
  #ifndef OTHER_DS
    #ifndef RANGE_UPD
      using T = int; 
      MBIT<T,SZ+5> tree; 
      const T ID = 0; 
      T comb(T a, T b) { return a+b; }
      HLD() { }
    #else
      LSEG tree; using T = LSEG::Q;
      const T ID = tree.id.second; 
      T comb(T a, T b) { return tree.qop(a, LSEG::R(), b, LSEG::R()); } //T is query type
      HLD() : tree(SZ) {}    
    #endif
  #else //use other ds like fenwick
    using T = int; 
    BIT<T,SZ> tree; 
    const T ID = tree.op.ID; 
    T comb(T a, T b) { return tree.op.comb(a, b); }
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
  T qrypath(int x, int y, T a, T b) { 
      T res = ID; processPath(x,y,[this,&res,&a,&b](int l, int r) { 
      res = comb(res,tree.qry(l,r,a,b)); });
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
HLD<3,0> h;

int main() {
  IO("");
  h.add(0,1),h.add(1,2); h.init(); h.upd(0,10); h.upd(1,100); h.upd(2,1000); assert(h.qrypath(0,2,10,1000)==3);
}
*/
