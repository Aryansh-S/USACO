template <class T, int SZ> struct Dijk { //class T is the type of weight being used, works in O(E log V)
  vector<pair<T,int> > adj[SZ]; T dist[SZ]; bool vis[SZ];
  int mom[SZ];
  void add(int a, int b, T w){adj[a].pb(mp(w,b)); adj[b].pb(mp(w,a));}
  void add_(int a, int b, T w){adj[a].pb(mp(w,b));} //if edge is directed
  void upd(int start){
    F0R(i,SZ) dist[i]=(i!=start)?INF:0, vis[i]=0, mom[i]=i;
    minpq<pair<T,int> > q;
    q.push(mp(0,start));
    while(!q.empty()){
      auto curr=q.top(); q.pop(); vis[curr.s]=1;
      trav(v,adj[curr.s]){
        if(vis[v.s]) continue;
        if(dist[v.s]>dist[curr.s]+v.f){
          dist[v.s]=dist[curr.s]+v.f;
          mom[v.s]=curr.s;
          q.push(mp(dist[v.s],v.s));
        }
      }
    }
  }
  T qry(int v){return dist[v];}
  T qry_(int st, int v){upd(st); return qry(v);}
  vector<pii> path(int v){
    vector<pii> ret; int i=v;
    while(mom[i]!=i){ret.pb(mp(mom[i],i)),i=mom[i];}
    reverse(all(ret)); return ret;
  }
  vector<pii> path_(int st, int v){
    upd(st); return path(st,v);
  }
};
