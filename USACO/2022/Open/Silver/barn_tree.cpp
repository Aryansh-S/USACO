#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

using ll = long long;

vector<ll> h, subtree_tot;
vector<vector<int>> adj;

ll avg;
vector<tuple<int, int, ll>> orders; // {source, destination, bales}

void dfs_fill_subtrees(int node = 0,
                       int par = 0) { // root tree arbitrarily at 0
    // fill in total bales in each subtree and size of each subtree
    subtree_tot[node] = h[node] - avg;
    for (int child : adj[node])
        if (child != par) {
            dfs_fill_subtrees(child, node);
            subtree_tot[node] += subtree_tot[child];
        }
}

void dfs_make_orders(int node = 0, int par = 0) { // root tree arbitarily at 0
    // give from child to node
    for (int child : adj[node])
        if (child != par) {
            if (subtree_tot[child] >= 0) dfs_make_orders(child, node);
            if (subtree_tot[child] > 0)
                orders.emplace_back(child, node, subtree_tot[child]);
        }
    // give from node to child
    for (int child : adj[node])
        if (child != par && subtree_tot[child] < 0) {
            orders.emplace_back(node, child, -subtree_tot[child]);
            dfs_make_orders(child, node);
        }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    h.resize(n), adj.resize(n);
    for (ll &t : h) cin >> t, avg += t;
    avg /= n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v, --u, --v;
        adj[u].emplace_back(v), adj[v].emplace_back(u);
    }
    subtree_tot.resize(n);
    dfs_fill_subtrees();
    dfs_make_orders();
    cout << size(orders) << "\n";
    for (auto [u, v, b] : orders) cout << ++u << " " << ++v << " " << b << "\n";
}
