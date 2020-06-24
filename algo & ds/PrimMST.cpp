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
