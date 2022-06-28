#include <bits/stdc++.h>
using namespace std; 

// basic graph problems sometimes show up in bronze
// this one is a dfs of a graph

const int mxN = 100; 

int N; 
bool vis[mxN]; // visited array
vector<int> adj[mxN]; // adjacency list representation
int cnt[mxN]; // from how many vertices can you visit this vertex

void dfs(int v) {
	vis[v] = 1; 
	++cnt[v];
	for (int u: adj[v]) if (!vis[u]) dfs(u);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("factory.in", "r", stdin); 
	freopen("factory.out", "w", stdout); 

	cin >> N; 
	for (int i = 0; i < N - 1; ++i) {
		int a, b; 
		cin >> a >> b; 
		--a, --b; // zero index
		adj[a].emplace_back(b); // add directed edge
	}

	for (int i = 0; i < N; ++i) {
		dfs(i); 
		memset(vis, 0, sizeof(vis));
	}
	
	for (int i = 0; i < N; ++i) if (cnt[i] == N) { cout << i + 1 << "\n"; exit(0); }
	cout << "-1\n";
}
