//Merge Sort Tree Version

#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;

vector<int> tree[1 << 18];
const int SZ = 1 << 17;

inline void insert(int x, int v){
    x |= SZ; tree[x].push_back(v);
}
inline void build(){
    for(int i=SZ-1; i; i--){
        tree[i].resize(tree[i << 1].size() + tree[i << 1 | 1].size());
        merge(all(tree[i << 1]), all(tree[i << 1 | 1]), tree[i].begin());
    }
}
int seg_query(int l, int r, int x){
    l |= SZ; r |= SZ; int ret = 0;
    while(l <= r){
        if(l & 1) ret += upper_bound(all(tree[l]), x) - lower_bound(all(tree[l]), x), l++;
        if(~r & 1) ret += upper_bound(all(tree[r]), x) - lower_bound(all(tree[r]), x), r--;
        l >>= 1, r >>= 1;
    }
    return ret;
}

int n, q;
int v[101010];
vector<int> inp[101010];
vector<int> g[101010];

int sz[101010], par[101010], dep[101010], top[101010], in[101010], pv;

void dfs(int v = 1, int p = -1){
    for(auto i : inp[v]) if(i ^ p){
        g[v].push_back(i); par[i] = v; dep[i] = dep[v] + 1;
        dfs(i, v);
    }
}
void dfs1(int v = 1){
    sz[v] = 1;
    for(auto &i : g[v]){
        dfs1(i); sz[v] += sz[i];
        if(sz[i] > sz[g[v][0]]) swap(i, g[v][0]);
    }
}
void dfs2(int v = 1){
    in[v] = ++pv;
    for(auto i : g[v]){
        top[i] = i == g[v][0] ? top[v] : i;
        dfs2(i);
    }
}

int query(int u, int v, int x){
    int ret = 0;
    while(top[u] ^ top[v]){
        if(dep[top[u]] < dep[top[v]]) swap(u, v);
        ret += seg_query(in[top[u]], in[u], x);
        u = par[top[u]];
    }
    if(dep[u] > dep[v]) swap(u, v);
    ret += seg_query(in[u], in[v], x);
    return !!ret;
}

int main(){
    freopen("milkvisits.in","r",stdin),freopen("milkvisits.out","w",stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for(int i=1; i<=n; i++) cin >> v[i];
    for(int i=1; i<n; i++){
        int s, e; cin >> s >> e;
        inp[s].push_back(e);
        inp[e].push_back(s);
    }
    dfs(); dfs1(); dfs2();
    for(int i=1; i<=n; i++) insert(in[i], v[i]);
    build();
    while(q--){
        int a, b, c; cin >> a >> b >> c;
        cout << query(a, b, c);
    }
}
