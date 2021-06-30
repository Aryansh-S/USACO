#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std; using namespace __gnu_pbds; 

using ll = long long; using ld = long double; using pii = pair<int,int>; using vi = vector<int>;
template<class T, class U = null_type, class cmp = less<T>> using oset = tree<T,U,cmp,rb_tree_tag,tree_order_statistics_node_update>;
template<class T, class U = null_type, class chash = hash<T>> using hset = gp_hash_table<T,U,chash>;

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
#define dbg(...) { cerr << "[Line " << __LINE__ << "] " << #__VA_ARGS__ << " is "; de(__VA_ARGS__); } 

#define m1(x) template<class T, class... U> void x(T&& a, U&&... b)
#define m2(x) (int[]){(x forward<U>(b), 0)...}; 

m1(de) { cerr << forward<T>(a); m2(cerr << " " <<); cerr << endl; }
m1(pr) { cout << forward<T>(a); m2(cout << " " <<); cout << "\n"; }
m1(re) { cin >> forward<T>(a); m2(cin >>); }

template<class T> void in(T a, T b) { assert(a != b); while(b - a) re(*a), ++a; }
template<class T> void out(T a, T b) { assert(a != b); while(b - a - 1) cout << *a << " ", ++a; pr(*--b); }

const int _ = 2e5 + 5, MOD = 1e9 + 7, xd[] = {0,1,0,-1}, yd[] = {1,0,-1,0}, INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f; // use ll, negatives kill mods

int n,k;
int dp[_]; 
// dp[i] = max sum of skill levels achieved (after i) if you start a new group at idx i

struct SEG {
	using T = int;
	const T ID = -INF; T comb(T a, T b) { return max(a,b); }
	int n; vector<T> seg;
	void init(int n0) { n = n0; seg.assign(2 * n, ID); }
	void upd(int p, T v) {
		seg[p += n] = v; 
		for(p /= 2; p; p /= 2) seg[p] = comb(seg[2 * p], seg[2 * p + 1]);
	}
	T qry(int l, int r) {
		T ql = ID, qr = ID; 
		for(l += n, r += n + 1; l < r; l /= 2, r /= 2) {
			if(l & 1) ql = comb(ql, seg[l++]); 
			if(r & 1) qr = comb(seg[--r], qr);
		}
		return comb(ql, qr);
	}
} cow;

int solve(int i) {
	if(dp[i]) return dp[i];
	FOR(s, 1, min(n - i, k) + 1) ckmax(dp[i], cow.qry(i, i + s - 1) * s + solve(i + s));
	return dp[i];
}

int main() { 
	IO("teamwork");
	re(n,k);
	cow.init(n);
	F0R(i,n) { 
		int x; re(x); cow.upd(i,x); 
		if(i == n - 1) dp[i] = x; 
	}
	pr(solve(0));
}







