template<int SZ> struct TopSort { //works for DAG
    //pls 0 index
    //topological sort and detect cycles
    vi adj[SZ], res; int sto[SZ], n=SZ,mx;
    //void add(int a, int b){adj[a].pb(b); adj[b].pb(a);}
    void add_(int a, int b){adj[a].pb(b); sto[b]++;}
    void sort(int _n=SZ){ //sort from 0..n-1 (#el)
      n=_n; queue<int> q;
      F0R(i,n) if(!sto[i]) q.push(i);
      while(!q.empty()){
        int v=q.front(); q.pop(); res.pb(v);
        trav(i,adj[v]) if(!--sto[i]) q.push(i);
      }
    }
    vi get(){return res;}
    bool cyc(){return (sz(res)!=n);} //sort first
  };
