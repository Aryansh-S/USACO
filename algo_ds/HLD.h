// Newest HLD -- Well-Tested & Generalized
// Decomposes path into log n chains, which can be treated like contiguous subarrays
// Supports subtrees (without adding the extra log factor that it does for paths into chains)
// Add all edges and then init

template<int SZ, bool EDGE = 1> struct HLD {	
	// init ds
	// using T = int; 
	// SEG<T> tree; 
	// const T ID = tree.ID; 
	// T comb(T a, T b) { return tree.comb(a, b); }
	// HLD() { tree.init(SZ); }

	vector<int> adj[SZ], rpos;
	int par[SZ], root[SZ], depth[SZ], siz[SZ], pos[SZ], ti;

	void add(int x, int y) { adj[x].pb(y), adj[y].pb(x); }
	void init(int R = 0) { par[R] = depth[R] = ti = 0; dfsSz(R); root[R] = R; dfsHld(R); }

	void dfsSz(int x) { 
		siz[x] = 1; 
		trav(y, adj[x]) {
			par[y] = x; depth[y] = depth[x]+1;
			adj[y].erase(find(all(adj[y]), x));
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
	int dist(int x, int y) {
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
	T qrypath(int x, int y) { 
		T res = ID; processPath(x,y,[this,&res](int l, int r) { 
				res = comb(res,tree.qry(l,r)); });
		return res; 
	}
	T qrysubtree(int x) {
		return tree.qry(pos[x] + EDGE, pos[x] + siz[x] - 1);
	}
	void updpath(int x, int y, T v) { 
		processPath(x,y,[this,&v](int l, int r) { 
				tree.upd(l,r,v); }); 
	}	
	void updsubtree(int x, T v) { 
		tree.upd(pos[x] + EDGE, pos[x] + siz[x] - 1, v); 
	}
};
