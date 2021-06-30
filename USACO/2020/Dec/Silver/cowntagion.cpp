#include <bits/stdc++.h>
using namespace std; 

const int N = 2e5 + 5;

int n, ans, cnt[N];
vector<int> adj[N];
bool vis[N];

void dfs(int v) {
	vis[v] = 1;
	int need = 1; 
	for(int u: adj[v]) if(!vis[u]) ++need;
	while(cnt[v] < need) cnt[v] *= 2, ++ans;
	for(int u: adj[v]) if(!vis[u]) ++cnt[u], --cnt[v], ++ans, dfs(u); 
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n; 
	for(int i = 0; i < n - 1; ++i) { 
		int a,b; cin >> a >> b, --a, --b; 
		adj[a].emplace_back(b), adj[b].emplace_back(a);
	}
	cnt[0] = 1, dfs(0);
	cout << ans << "\n";
}
