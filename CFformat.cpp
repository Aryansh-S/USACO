#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
// warning: pragmas don't work on USACO and just set to O0

#include <bits/stdc++.h>  
#include <ext/pb_ds/assoc_container.hpp> //gp_hash_table<T, U, chash>; 
#include <ext/pb_ds/tree_policy.hpp> //tree<T, U, cmp, rb_tree_tag,tree_order_statistics_node_update>;
using namespace std; using namespace __gnu_pbds; 
// shorter template (CF specialization, because compile time better)

inline int RAND(int l, int r) { 
  mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
  uniform_int_distribution<int> unifd(l,r); return unifd(mt); 
} 

template<class T> using pq = priority_queue<T, vector<T>, greater<T>>; 
using ll = long long; using db = double; using ld = long double; using pii = pair<int,int>; using pll = pair<ll,ll>; using vi = vector<int>; 
using vll = vector<ll>; const int xd[4] = {0,1,0,-1}, yd[4] = {1,0,-1,0};

#define mp make_pair
#define f first
#define s second
#define eb emplace_back

//#define TC
const auto INF = 0x3f3f3f3f; const db EPS = 1e-8;
const int MOD = 1e9 + 7, //998244353
_ = 2e5 + 5;

void solve() {
  
}

int main() { 
  cin.tie(0)->sync_with_stdio(0); //cout << setprecision(3) << fixed << showpoint; 
  int t = 1; 
  #ifdef TC
    cin >> t; 
  #endif
  while(t--) solve(); 
}
