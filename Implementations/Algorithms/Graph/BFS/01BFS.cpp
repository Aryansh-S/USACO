#include <bits/stdc++.h>
using namespace std;
//level: advanced silver, basic gold
//objective: find the single-sourced shortest path to all nodes in a graph whose edges are binary weighted (either 0 or 1) 
//in linear runtime (dijkstra, etc. usually introduce a log factor or more)

//the simple resolution is to maintain a double-ended queue and start BFS, greedily aiming to minimize distance
//store current distances in a global array as INF by default or 0 if source

const int mx=1e3;
int n,m,s,dist[mx]; deque<int> q; bool adj[mx][mx]; 

//adj matrix is convenient to use, but if your graph is sparse, you can use unordered_set 
//to optimize memory while maintaining O(1) search

#define INF 0x3f3f3f3f

int main(){
  cin.tie(0)->sync_with_stdio(0);
  
  cin >> n >> m >> s; while(m--){int a,b; bool w; cin >> a >> b >> w,a--,b--,adj[b][a]=adj[a][b]=w;}
  //s is the source
  q.push_back(s); for(int i=0; i<n; i++) dist[i]=INF; dist[s]=0;
  while(!q.empty()){
   int v=q.front(); q.pop_front(); 
   for(int i=0; i<n; i++) if(adj[i][v]){
    if(dist[i]>dist[v]+adj[i][v]) dist[i]=dist[v]+adj[i][v];
    if(adj[i][v]) q.push_back(i);
    else q.push_front(i);
   }
  }
  
  while(n--) cout << "shortest distance from " << s << " to " << n << " is " << dist[n] << "\n";
  return 0;
}
