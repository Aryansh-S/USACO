#include <bits/stdc++.h>  
#include <bits/extc++.h>
using namespace std; using namespace __gnu_pbds;

using ll = long long; using ld = long double; using pii = pair<int,int>; using vi = vector<int>;
template<class T, class U = null_type, class chash = hash<T>> using hset = gp_hash_table<T,U,chash>; 
template<class T, class U = null_type, class cmp = less<T>> using oset = tree<T,U,cmp,rb_tree_tag,tree_order_statistics_node_update>;

#define fbo find_by_order
#define ook order_of_key
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define ef emplace_front
#define emp emplace
#define ins insert
#define ers erase
#define lb lower_bound
#define ub upper_bound 
#define sz(x) (int)(x).size()
#define all(x) begin(x),end(x)

template<class T> bool ckmin(T& a, const T b) { return a > b ? a = b, 1 : 0; } 
template<class T> bool ckmax(T& a, const T b) { return a < b ? a = b, 1 : 0; } 

#define trav(a,...) for(auto&a:__VA_ARGS__)
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define ROF(i,a,b) for(int i = (b)-1; i >= (a); --i)
#define F0R(i,a) FOR(i,0,a)
#define R0F(i,a) ROF(i,0,a)

using namespace chrono; 
#define NOW steady_clock::now()
#define TIME duration<ld,milli>(NOW-THEN).count()
auto THEN = NOW; 

#define IO(x) if(fopen(x ".in","r")) freopen(x ".in","r",stdin), freopen(x ".out","w",stdout); cin.tie(0)->sync_with_stdio(0)
#define dbg(...) {cerr << "[Line " << __LINE__ << "] " << #__VA_ARGS__ << " is "; de(__VA_ARGS__);} 

#define m1(x) template<class T, class... U> void x(T&& a, U&&... b)
#define m2(x) (int[]){(x forward<U>(b), 0)...}; 

m1(de) { cerr << forward<T>(a); m2(cerr << " " <<); cerr << endl; }
m1(pr) { cout << forward<T>(a); m2(cout << " " <<); cout << "\n"; }
m1(re) { cin >> forward<T>(a); m2(cin >>); }

template<class T> void in(T a, T b) { assert(a != b); while(b - a) re(*a), ++a; }
template<class T> void out(T a, T b) { assert(a != b); while(b - a - 1) cout << *a << " ", ++a; pr(*--b); }

const int _ = 105, mxv = 2e5 + 5, MOD = 1e9 + 7, xd[] = {0,1,0,-1}, yd[] = {1,0,-1,0}, INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;

int n,v[_]; ll c,w[_],dp[mxv]; // dp[val] = min wt
int ans = -INF; 

int main() { 
    IO("");    
    re(n,c); FOR(i,1,n+1) re(w[i],v[i]); 
    memset(dp,0x3f,sizeof(dp)); 
    dp[0] = 0; 
    FOR(i,1,n+1) R0F(j,1e5+1) ckmin(dp[j + v[i]], dp[j] + w[i]);
    F0R(i,1e5+1) if(dp[i] <= c) ckmax(ans,i); 
    pr(ans);
}





