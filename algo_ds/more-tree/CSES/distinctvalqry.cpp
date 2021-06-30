#include "longheader.h"

const int S = 2e5 + 5, MOD = 1e9 + 7, xd[] = {0,1,0,-1}, yd[] = {1,0,-1,0}, INF = 0x3f3f3f3f;
 
int n,c[S],ans[S]; vi adj[S];
 
set<int> dfs(int v, int p) {
  set<int> ret; ret.ins(c[v]);
  trav(u,adj[v]) if(u != p) {
      set<int> res = dfs(u, v);
      if(res.size() > ret.size()) swap(res, ret);
      trav(i,res) ret.insert(i);
  }
  ans[v] = ret.size();
  return ret;
}
 
int main() { 
	IO("");	
	cin >> n; in(c,c+n); 
	F0R(i,n-1) { int a,b; cin >> a >> b, --a, --b; adj[a].eb(b), adj[b].eb(a); }
	dfs(0,0); 
	out(ans,ans+n);
}
