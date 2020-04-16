#include <bits/stdc++.h>
using namespace std;

//objective: perform BFS on an adjacency list graph 
//BFS is inherently an iterative process, using a queue

typedef queue<int> qi; //supports FIFO
typedef vector<int> vi; 
#define pb push_back
#define trav(a,x) for(auto&(a):(x))
#define FOR(i,a,b) for(__typeof(b)i=(a)-((a)>(b));i!=(b)-((a)>(b));i+=((a)>(b))?-1:1) //go from i=lb to i=ub-1
#define F0R(i,b) FOR(i,0,b)

const int SZ = 1e5;

vi adj[SZ]; bool visit[SZ]; qi line; 

int main(){
  cin.tie(0)->sync_with_stdio(0);
  int q; cin >> q; F0R(i,q){int a,b; cin >> a >> b; a--,b--; adj[a].pb(b); adj[b].pb(a);}
  line.push(0);
  while(!line.empty()){
    int v = line.front(); line.pop(); 
    if(!visit[v]){
      //process
      trav(a,adj[v]) line.push(a);
    }
  }
  return 0;
}
