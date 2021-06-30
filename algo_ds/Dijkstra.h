#include <bits/stdc++.h>
using namespace std; 
template<class T> using minpq = priority_queue<T, vector<T>, greater<T>>; 
#define mp make_pair
const int INF = 0x3f3f3f3f; 
#define f first
#define s second
#define trav(a, b) for(auto& (a):(b))
#define F0R(i,n) for(int (i) = 0; (i) < (n); ++(i))
#define pii pair<int,int> 
#define pb push_back
#define all(x) begin(x),end(x)
#include <ext/pb_ds/assoc_container.hpp> //hset, hmap
using namespace __gnu_pbds; 
template<class T, class U, class chash = hash<T>> using hmap = gp_hash_table<T, U, chash>; 
using vi = vector<int>; 

///// --- ABOVE FOR ISOLATED TESTING --- ////// 

//REGULAR: NO EDGE MODIFICATION

//O(E log V) single source shortest path

template <class T, int SZ> struct Dijk { //class T is the type of weight being used, works in O(E log V)
  vector<pair<T,int> > adj[SZ]; T dist[SZ];
  int mom[SZ];
  void add(int a, int b, T w){adj[a].pb(mp(w,b)); adj[b].pb(mp(w,a));}
  void add_(int a, int b, T w){adj[a].pb(mp(w,b));} //if edge is directed
  void upd(int start){
    F0R(i,SZ) dist[i]=(i!=start)?INF:0, mom[i]=i;
    minpq<pair<T,int> > q;
    q.push(mp(0,start));
    while(!q.empty()){
      auto curr=q.top(); q.pop();
      if(curr.f != dist[curr.s]) continue; 
      trav(v,adj[curr.s]){
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

//MAP VERSION TO MODIFY EDGES:

template <class T, int SZ> struct Dijk { //map version, class T is the type of weight being used, works in O(E log V)
  //#define DIJKHASH //get hash version?
  vi adj[SZ]; T dist[SZ];
  
  #ifndef DIJKHASH
    map<pii,T> pipe; //stores edges as edge -> weight 
  #else
    struct chash {int operator()(pii x) const { return (0x9e3779b9 + (x.f << 2)) ^ 1273123712 ^ (0x9e3448b2 + (x.s << 5));}};
    hmap<pii,T,chash> pipe; //stores edges hash as edge -> weight
  #endif
  
  int mom[SZ];
  void add(int a, int b, T w) { adj[a].pb(b); adj[b].pb(a); pipe[mp(a,b)] = pipe[mp(b,a)] = w; } 
  void add_(int a, int b, T w) { adj[a].pb(b); pipe[mp(a,b)] = w; } 
  void ch(int a, int b, T w) { pipe[mp(a,b)] = pipe[mp(b,a)] = w; }
  void ch_(int a, int b, T w) { pipe[mp(a,b)] = w; }
  void del(int a, int b) { pipe.erase(mp(a,b)); pipe.erase(mp(b,a)); }
  void del_(int a, int b) { pipe.erase(mp(a,b)); }
  void upd(int start){
    F0R(i,SZ) dist[i]=(i!=start)?INF:0, mom[i]=i;
    minpq<pair<T,int> > q;
    q.push(mp(0,start));
    while(!q.empty()){
      auto curr=q.top(); q.pop();
      if(curr.f != dist[curr.s]) continue; 
      trav(v,adj[curr.s]){
        if(dist[v]>dist[curr.s]+pipe[mp(curr.s,v)]){
          dist[v]=dist[curr.s]+pipe[mp(curr.s,v)];
          mom[v]=curr.s;
          q.push(mp(dist[v],v));
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

// DENSE GRAPHS, O(V^2), todo {also will add dense prim afterwards}: 
/*
template<class T, size SZ> struct Dijkd {
  T adj[SZ][SZ], dist[SZ]; bool vis[SZ];
  int mom[SZ];
  void add(int a, int b, T w) { adj[a][b] = adj[b][a] = w; }
  void add_(int a, int b, T w) { adj[a][b] = w; }
  void upd(int start) {
    F0R(i,SZ) dist[i]=(i!=start)?INF:0, vis[i]=0, mom[i]=i;
    F0R(i,SZ) {
      vis
    }
  }
  T qry
  T qry_
  vector<pii> path
  vector<pii> path_
};
*/

/// --- BELOW FOR TESTING --- ///

int main() {
  
}
