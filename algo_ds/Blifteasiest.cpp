#include <bits/stdc++.h>
using namespace std; 

const int mxn = 1 << 20, lvl = 20; 

int n = 5; // consider adj list for a tree with 5 nodes
vector<int> adj[] = {{1,2},{0,3,4},{0},{1},{1}}; 

int up[mxn][lvl]; // [x,y] is lifting up 2^y times from x
bool vis[mxn];

void dfs(int v, int p) { // dfs, keeping track of parent of each node in separate array
    up[v][0] = p; // 2^0 = 1, so this is immediate parent
    vis[v] = 1; 
    for(int u: adj[v]) if(!vis[u]) dfs(u,v);
}

int main() {
    cin.tie(0)->sync_with_stdio(0); 
    memset(up,-1,sizeof(up)); // first, set so no parents exist for any nodes
    dfs(0,-1); // start dfs at root and fill out immediate parents

    // preprocess 
    for(int l = 1; l < lvl; ++l) 
        for(int i = 0; i < n; ++i) 
            if(up[i][l - 1] != -1) up[i][l] = up[up[i][l - 1]][l - 1]; 
    
    // put in a node and distance to lift
    int node, dist; 
    cin >> node >> dist; 
    for(int l = 0; l < lvl && node != -1; ++l) if(dist & (1 << l)) node = up[node][l];
    cout << node << "\n";
}
