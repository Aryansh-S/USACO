template<int SZ> struct Euler{ //tree euler tour
	vi adj[SZ]; bool vis[SZ]; vi tour; //2SZ-1
	Euler() { tour.rsz(2*SZ-1); }
	void add(int a, int b) { adj[a].pb(b); adj[b].pb(a); }
	void add_(int a, int b) { adj[a].pb(b); }
	void dfs(int curr, int &idx){
		vis[curr]=1,tour[idx++]=curr;
		trav(v,adj[curr]) if(!vis[v]) dfs(v,idx),tour[idx++]=curr;
	}
	void upd(int rt){
		F0R(i,SZ) vis[i]=0;
		int idx=0; dfs(rt,idx);
	}
	vi query(){return tour;}
		vector<pii> edges(){
		vector<pii> ret; 
		F0R(i,2*SZ-2) ret.pb(mp(tour[i],tour[i+1]));
		return ret;
	}
};
