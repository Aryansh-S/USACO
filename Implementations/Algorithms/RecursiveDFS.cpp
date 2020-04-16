#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi; 
#define pb push_back
#define trav(a,x) for(auto&(a):(x))
#define FOR(i,a,b) for(__typeof(b)i=(a)-((a)>(b));i!=(b)-((a)>(b));i+=((a)>(b))?-1:1) //go from i=lb to i=ub-1
#define F0R(i,b) FOR(i,0,b)

//objective: outline the basic idea of DFS and write a recursive function

const int SZ=1e5;

vi adj[SZ]; bool visit[SZ]; 

/*
adj is an array of vectors -- the ith vector in this array stores all of the vertices adjacent to i (through an edge)
(this is also known as an adjacency list)
also, we want to visit each vertex only one to create an O(N) DFS algorithm, so we keep track of visited vertices
*/

void dfs(int v){
 //v represents the current vertex we are at
 if(!visit[v]){ //only DFS if not yet visited; otherwise, will do nothing and return
  //process vertex
  trav(a,adj[v]) dfs(a); 
 }
}

int main(){
  cin.tie(0)->sync_with_stdio(0); 
  //build adjacency list given information
  cin >> q; F0R(i,q){int a,b; cin >> a >> b; a--,b--; adj[a].pb(b); adj[b].pb(a);}
  dfs(0); //start dfs at 0
  return 0;
}
