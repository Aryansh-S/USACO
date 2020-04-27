#include <bits/stdc++.h>
using namespace std;

//level: gold

//objective: use dijkstra's to find shortest path from one node to all other nodes in undirected or directed graph 
//with weights (if not weighted, standard BFS works)
//NO NEGATIVE WEIGHTED EDGES, cycles are fine

typedef pair<int,int> pii; 
template<class T> minpq using priority_queue<T, vector<T>, greater<T>>; 
#define INF 0x3f3f3f3f
#define pb push_back
#define ins insert
#define ers erase
#define mp make_pair
#define f first
#define s second
const int sz=1e5;

int n,m,start,dist[sz]; vector<pii> adj[sz]; //weight, node
bool vis[sz];

int main(){
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m >> start; start--; for(int i=0; i<n; i++) dist[i]=INF;
  for(int i=0; i<m; i++){
    int a,b,w; cin >> a >> b >> w; a--,b--; adj[a].pb(mp(w,b)); adj[b].pb(mp(w,a));
  }
  minpq<pii> q; //weight, node
  while(!q.empty()){
    pii curr=q.top(); q.pop();
    vis[curr.s]=1;
    for(pii v:adj[curr]){
      if(!vis[v.s]&&dist[curr.s]>dist[v.s]+v.f){
        dist[curr.s]=dist[v.s]+v.f;
        q.push(mp(dist[curr.s],curr.s));
      }
    }
  }
  cout << "The shortest distance from " << start+1 << " to\n"
  for(int i=0; i<n; i++) cout << "vertex " << i+1 << " is " << dist[i] << "\n";
  return 0;
}
