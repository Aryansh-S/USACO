#include <bits/stdc++.h>
using namespace std;
//level: basic silver

//objective: design an iterative DFS using stack 
//read about adjacency list and visited array in recursive impl for more info

typedef stack<int> si; //supports FILO
typedef vector<int> vi; 
#define pb push_back
#define trav(a,x) for(auto&(a):(x))
#define FOR(i,a,b) for(__typeof(b)i=(a)-((a)>(b));i!=(b)-((a)>(b));i+=((a)>(b))?-1:1) //go from i=lb to i=ub-1
#define FOR_(i,a,b,d) for(__typeof(b)i=(a)-((a)>(b));(a>b)?(i>b-1):(i<b);i+=(((a)>(b))?-1:1)*abs(d)) //go from i=lb to i=ub-1 by size d increments
#define F0R(i,b) FOR(i,0,b)

const int SZ = 1e5; 

vi adj[SZ]; bool visit[SZ]; si pile; 

int main(){
  cin.tie(0)->sync_with_stdio(0); 
  int q; cin >> q; F0R(i,q){int a,b; cin >> a >> b; a--,b--; adj[a].pb(b); adj[b].pb(a);}
  pile.push(0);
  while(!pile.empty()){
    int v = pile.top(); pile.pop();
    if(!visited[v]){
      visited[v]=1;
      //process
    }
    trav(a,adj[v]) if(!visit[a]) pile.push(a);
  }
  return 0;
}
