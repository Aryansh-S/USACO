#include "longheader.h"

const int S = 2e5 + 5, MOD = 1e9 + 7, xd[] = {0,1,0,-1}, yd[] = {1,0,-1,0}, INF = 0x3f3f3f3f;
 
int n,x,ans; vi adj[S]; bool vis[S]; 
 
void dfs(int v, int d) {
	if(vis[v]) return; vis[v] = 1;
	if(ckmax(ans,d)) x = v;
	++d; trav(u,adj[v]) dfs(u,d); 
}
 
int main() { 
	IO("");	
	cin >> n;
	F0R(i,n-1) { int a,b; cin >> a >> b, --a, --b; adj[a].eb(b), adj[b].eb(a); }
	dfs(0,0); fill(all(vis),0); dfs(x,0); 
	pr(ans); 
}
