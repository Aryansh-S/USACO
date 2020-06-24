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
