#include <bits/stdc++.h>
using namespace std;

//level: gold

//objective: use dijkstra's to find shortest path from one node to all other nodes in undirected or directed graph 
//with weights (if not weighted, standard BFS works)
//NO NEGATIVE WEIGHTED EDGES, cycles are fine

//set is easy to use but priority_queue works fine as well

typedef pair<int,int> pii; 
#define INF 0x3f3f3f3f
#define pb push_back
#define ins insert
#define ers erase
#define mp make_pair
#define f first
#define s second
const int sz=1e5; 

vector<pii> adj[sz]; int n,m,start,dist[sz]; //store dist from start to all other vertices
set<pii> curr; 

int main(){
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m >> start; start--; 
  for(int i=0; i<m; i++){
    int a,b,w; cin >> a >> b >> w; a--,b--; adj[a].pb(mp(b,w)); adj[b].pb(mp(a,w));
  }
  for(int i=0; i<n; i++) dist[i]=INF; 
  curr.ins(mp(0,start));
  while(!curr.empty()){
    pii tmp=*curr.begin(); curr.erase(curr.begin());
    int closest=tmp.s; 
    for(pii ptr:adj[closest]){
      int v=ptr.s, weight=ptr.f;
      //if shorter path to v thru closest
      if(dist[v]>dist[u]+weight){
        if(dist[v]!=INF) curr.ers(mp(dist[v],v)); //v is in our set so remove it 
        dist[v]=dist[u]+weight; //a shorter distance has been found
        curr.ins(mp(dist[v],v));
      }
    }
  }
  cout << "distance from " << start+1 << " to\n";
  for(int i=0; i<n; i++){
    cout << "vertex " << i+1 << " is " << dist[i] << "\n";
  }
  return 0;
}
