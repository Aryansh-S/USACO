//binary lifting O(n log n) init, O(log) qry, init after adding

struct LCA {
	int N; vector<vi> par, adj; vi depth;
	void size(int _N) {  N = _N; 
		int d = 1; while ((1<<d) < N) d ++;
		par.assign(d,vi(N)); adj.rsz(N); depth.rsz(N);
	}
	void add(int x, int y) { adj[x].pb(y), adj[y].pb(x); }
	void init(int R = 0) { par[0][R] = R; dfs(R); }
	void dfs(int x = 0) {
		FOR(i,1,sz(par)) par[i][x] = par[i-1][par[i-1][x]];
		trav(y,adj[x]) if (y != par[0][x]) 
			depth[y] = depth[par[0][y] = x]+1, dfs(y);
	}
	int jmp(int x, int d) {
		F0R(i,sz(par)) if ((d>>i)&1) x = par[i][x];
		return x; }
	int lca(int x, int y) {
		if (depth[x] < depth[y]) swap(x,y);
		x = jmp(x,depth[x]-depth[y]); if (x == y) return x;
		R0F(i,sz(par)) {
			int X = par[i][x], Y = par[i][y];
			if (X != Y) x = X, y = Y;
		}
		return par[0][x];
	}
	int dist(int x, int y) {
		return depth[x]+depth[y]-2*depth[lca(x,y)]; }
};

