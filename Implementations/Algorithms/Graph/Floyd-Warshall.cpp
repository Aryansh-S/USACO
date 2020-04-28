#include <bits/stdc++.h>
using namespace std;
//level: gold

//objective: use the floyd-warshall graph algorithm to find the shortest distance between all pairs of vertices 
//advantages: easy to implement, works for negative edges, can be changed to longest path, etc...can detect negative cycles
//disadvantages: O(N^3) complexity

#define INF 0x3f3f3f3f
#define ckmin(a,b) a=min(a,b)
const int sz=1e3;
int adj[sz][sz], n, m; 

int main(){
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m; 
  for(int i=0; i<m; i++){int x,y,d; cin >> x >> y >> d; x--,y--; adj[x][y]=d;}
  for(int i=0; i<n; i++) for(int j=0; j<n; j++) adj[i][j]=INF; 
  for(int k=0; k<n; k++) for(int i=0; i<n; i++) for(int j=0; j<n; j++){
    ckmin(dist[i][j],dist[i][k]+dist[k][j]);
  }
  for(int i=0; i<n; i++) for(int j=i; j<n; j++) if(i!=j) 
    cout << "The shortest distance between vertices " << i << " and " << j << " is " << dist[i][j]; 
  return 0;
}
