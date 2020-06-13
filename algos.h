//My General Algo Implementations 

namespace graph_type {
  struct DSU { //from 0 to n-1
    vi e; void init(int n) { e = vi(n,-1); }
    bool cycfind; 
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -e[get(x)]; } //also use to check connected
    DSU(int SZ = 0) { init(SZ); }
    bool unite(int x, int y) { // union-by-rank
      x = get(x), y = get(y);
      if(x==y){
        cycfind=1; return 0;
      }
      if (e[x] > e[y]) swap(x,y);
      e[x] += e[y]; e[y] = x; return 1;
    }
    // void setpar(int a, int b){e[b]=-1; if(e[a]<0) e[a]=b; else e[e[a]]=b;} //make b parent of a
    int compnum(){ //return the number of components -- if want to check connected, don't use
    int ret=1;
    F0R(i,sz(e)-1) if(get(i)!=get(i+1)) ret++;
    return ret;
  }
  bool cyc(){return cycfind;}
};

namespace shortest_path {
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
    T query(int v){return dist[v];}
    T query_(int st, int v){upd(st); return query(v);}
    vector<pii> path(int st, int v){
      vector<pii> ret; int i=v;
      while(mom[i]!=i){ret.pb(mp(mom[i],i)),i=mom[i];}
      reverse(all(ret)); return ret;
    }
    vector<pii> path_(int st, int v){
      upd(st); return path(st,v);
    }
  };
  
  template <class T, int SZ> struct Floyd {
    T dist[SZ][SZ];
    Floyd(){F0R(i,SZ) F0R(j,SZ) dist[i][j]=INF;}
    void add(int a, int b, T w){dist[a][b]=dist[b][a]=w;}
    void add_(int a, int b, T w){dist[a][b]=w;}
    void upd(){
      F0R(k,SZ) F0R(i,SZ) F0R(j,SZ) ckmin(dist[i][j],dist[i][k]+dist[k][j]);
    }
    T query(int a, int b){return dist[a][b];}
    bool negcyc(){F0R(i,SZ) if(dist[i][i]<0) return 1; return 0;}
  };
  
  template <class T, int SZ> struct SPFA { //average O(E), wc bell-ford, check for negcyc
    vector<pair<T,int> > adj[SZ]; int mom[SZ],r[SZ]; T dist[SZ]; bool negcycbad;
    bool inq[SZ];
    void add(int a, int b, T w){
      adj[a].pb(mp(w,b)); adj[b].pb(mp(w,a));
    }
    void add_(int a, int b, T w){adj[a].pb(mp(w,b));}
    void upd(int start=0){
      F0R(i,SZ) dist[i]=(i!=start)?INF:0, mom[i]=i, inq[i]=0;
      deque<int> q; q.pb(start); inq[start]=1;
      while(!q.empty()){
        int curr=q.front(); q.pop_front(); inq[curr]=0;
        trav(v,adj[curr]){
          if(dist[v.s]>dist[curr]+v.f){
            dist[v.s]=dist[curr]+v.f; mom[v.s]=curr; r[v.s]++;
            if(r[v.s]==SZ){negcycbad=1; break;} //can't relax so much
            if(!inq[v.s]){
              if(q.empty()) q.pb(v.s);
              if(dist[q.front()]>dist[v.s]) q.push_front(v.s);
              else q.pb(v.s);
            }
          }
        }
      }
    }
    T query(int v){return dist[v];}
    T query_(int st, int v){upd(st); return query(v);}
    vector<pii> path(int v){
      vector<pii> ret; int i=v; 
      while(mom[i]!=i){ret.pb(mp(mom[i],i)); i=mom[i];}
      reverse(all(ret)); return ret;
    }
    vector<pii> path_(int st, int v){upd(st); return path(v);}
    bool negcyc(){return negcycbad;}
  };
}

namespace MST {
  template<class T, int SZ> struct Prim { // T is type weight
    minpq<pair<T,int> > temp; //key,vertex
    bool vis[SZ]; int mom[SZ]; T key[SZ];
    Prim(){F0R(i,SZ) mom[i]=-1;}
    vector<pair<T,int> > adj[SZ]; //store weight first
    void add(int a, int b, T w){
      adj[a].pb(mp(w,b)); adj[b].pb(mp(w,a));
    }
    void add_(int a, int b, T w){ //directed edge
      adj[a].pb(mp(w,b));
    }
    void upd(int rt=0){ //root the MST at rt
      mom[rt]=rt; //let the root be its own mom
      F0R(i,SZ) if(i!=rt) key[i]=INF;
      temp.push(mp(0,rt));
      F0R(i,SZ) if(i!=rt) temp.push(mp(INF,i));
      while(!temp.empty()){
        auto curr=temp.top(); temp.pop(); vis[curr.s]=1;
        for(auto v:adj[curr.s]){
          if(!vis[v.s] && key[v.s]>v.f){
            key[v.s]=v.f; temp.push(mp(key[v.s],v.s));
            mom[v.s]=curr.s;
          }
        }
      }
    }
    int par(int v){return mom[v];} //get parent
    array<vi,SZ> dirMST(){
      //want parent to contain all children
      array<vi,SZ> ret;
      F0R(i,SZ) if(mom[i]!=-1) ret[mom[i]].pb(i);  
      return ret; 
    }
    array<vi,SZ> undirMST(){
      array<vi,SZ> ret;
      F0R(i,SZ) if(mom[i]!=-1) {ret[mom[i]].pb(i); ret[mom[i]].pb(i);}
      return ret;
    }
    T sum(){T ret=0; F0R(i,SZ) if(vis[i] && key[i]!=INF) ret+=key[i]; return ret;}
  };
  
  template<class T, int SZ> struct Krus { //also get DSU
    DSU d; T weight; Krus(){d.init(SZ);}
    vector<pair<T,pii> > edge,MST;
    void add(int a, int b, T w){
      edge.pb(mp(w,mp(a,b)));
      edge.pb(mp(w,mp(b,a)));
    }
    void add_(int a, int b, T w){
      edge.pb(mp(w,mp(a,b)));
    }
    void upd(){
      sort(begin(edge),end(edge));
      F0R(i,edge.size()){
        int urep=d.get(edge[i].s.f),
        vrep=d.get(edge[i].s.s);
        if(urep!=vrep){
          MST.pb(edge[i]); d.unite(edge[i].s.f,edge[i].s.s); weight+=edge[i].f;
        }
      }
    }
    T sum(){return weight;}
    vector<pair<T,pii> > getMST(){return MST;}
  };
}
namespace tree_spec {
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
  
  template<int SZ> struct Euler{ //tree euler tour
    vi adj[SZ]; bool vis[SZ]; vi tour; //2SZ-1
    Euler(){tour.rsz(2*SZ-1);}
    void add(int a, int b){adj[a].pb(b); adj[b].pb(a);}
    void add_(int a, int b){adj[a].pb(b);}
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
  namespace LCA_spec {
    template <int SZ> struct BLCA{ //lca with binary lifting -- O(log n) query with O(n) preprocess
      vi adj[SZ]; const static int lg=32-__builtin_clz(SZ);
      int dp[SZ][lg],lvl[SZ]; BLCA(){F0R(i,SZ) memset(dp[i],-1,sizeof(dp[i]));}
      void add(int a, int b){adj[a].pb(b); adj[b].pb(a);}
      void add_(int a, int b){adj[a].pb(b);}
      void dfs(int u, int p){
        dp[u][0]=p; for(int i=1; i<lg; i++) dp[u][i]=dp[dp[u][i-1]][i-1];
        trav(v,adj[u]) if(v!=p) lvl[v]=lvl[u]+1,dfs(v,u);
      }
      int lca(int a, int b){
        if(lvl[a]<lvl[b]) swap(a,b);
        for(int i=lg-1; i>=0; i--) if(lvl[a]-pow(2,i)>=lvl[b]) a=dp[a][i];
        if(a==b) return a; for(int i=lg-1; i>=0; i--) if(dp[a][i]!=dp[b][i]) a=dp[a][i],b=dp[b][i]; return dp[a][0];
      }
      void upd(int rt=0){dfs(rt,0);}
      int dist(int a, int b){ //# of edges between a and b
        return lvl[a]+lvl[b]-2*lvl[lca(a,b)];
      }
    };
    
    template <int SZ> struct TLCA{ //offline tarjan LCA with in-built DSU 
      struct query{int x,y,lca;}; vector<query> queries;
      struct node{int mom,ancestor; bool seen; vi adj,qs;} nodes[SZ]; 
      //DSU
      int get(int x){return nodes[x].mom=(nodes[x].mom!=x)?get(nodes[x].mom):x;}
      void unite(int x, int y){nodes[get(x)].mom=get(y);}
      TLCA(){F0R(i,SZ) nodes[i].mom=nodes[i].ancestor=i;} 
      //add edges and queries
      void add(int a, int b){nodes[a].adj.pb(b); nodes[b].adj.pb(a);}
      void add_(int a, int b){nodes[a].adj.pb(b);}
      void addq(int x, int y){ //push in queries before next linear upd
        nodes[x].qs.pb(sz(queries)); nodes[y].qs.pb(sz(queries)); 
        query q; q.x=x,q.y=y,q.lca=-1; queries.pb(q);
      }
      //find lca recursive
      void findlca(int curr, int prev){
        trav(i,nodes[curr].adj) if(i!=prev){
          findlca(i,curr); unite(i,curr); nodes[get(curr)].ancestor=curr;
        }
        nodes[curr].seen=1; trav(i,nodes[curr].qs){
          int other_endpt=queries[i].x==curr?queries[i].y:queries[i].x;
          if(nodes[other_endpt].seen) queries[i].lca=get(other_endpt);
        }
      }
      void upd(int rt){findlca(rt,-1);}
      int lca(int qry){return queries[qry].lca;} //find LCA query by query number
    };
  }
}
}

namespace query_type {
  namespace fenwick {
    template<class T> struct operation { //for qry & upd
      const T ID = 0; 
      T comb(T a, T b) { return a + b; }
      T inv_comb(T a, T b) { return a - b; }
      T m_comb(T a, int L) { return a * L; } 
      //how does it compose with itself over a range
    }; 
    
    //point upd, range qry -- multiple dimensions
    template <class T, int ...Ns> struct BIT {
      operation<T> op; 
      
      T val = op.ID; 
      void upd(T v) { val = op.comb(val,v); } 
      T qry() { return val; } 
    };
    template <class T, int N, int... Ns> struct BIT<T, N, Ns...> { 
      BIT<T,Ns...> bit[N+1]; operation<T> op; 
      
      template<typename... Args> void upd(int pos, Args... args) { 
        for (; pos<=N; pos+=pos&-pos) bit[pos].upd(args...); 
      } 
      template<typename... Args> T sum(int r, Args... args) {
        T res = op.ID; for (;r;r-=r&-r) res = op.comb(res, bit[r].qry(args...)); 
        return res; 
      }
      template<typename... Args> T qry(int l, int r, Args...args) { 
        return op.inv_comb(sum(r, args...),sum(l - 1, args...)); 
      }
    };
    
    //range upd, range qry (lazy, same operation)
    template<class T, int SZ> struct LBIT { 
      BIT<T,SZ> bit[2]; operation<T> op; 
      
      void upd(int l, int r, T val) {
        bit[0].upd(l, val); 
        bit[0].upd(r, op.inv_comb(op.ID, val));
        bit[1].upd(l, op.m_comb(val, l - 1));
        bit[1].upd(r, op.inv_comb(op.ID, op.m_comb(val, r)));
      }
      
      T sum(int x) { return op.inv_comb(op.m_comb(bit[0].sum(x),x), bit[1].sum(x)); }
      T qry(int x, int y) { return op.inv_comb(sum(y),sum(x-1)); }
    }; 
  }
}
