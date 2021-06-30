#include <bits/stdc++.h>
using namespace std; 

using ll = long long; using pii = pair<int,int>; using vi = vector<int>;

#define mp make_pair
#define f first
#define s second
#define pb push_back
#define pf push_front
#define eb emplace_back
#define ef emplace_front
#define ppb pop_back
#define ppf pop_front
#define ins insert
#define emp emplace
#define ers erase
#define lb lower_bound
#define ub upper_bound 
#define sz(x) (int)(x).size()
#define all(x) begin(x),end(x)

#define trav(a,...) for(auto&a:__VA_ARGS__)
#define FOR(i,a,b) for(decltype(b) i = (a); i < (b); ++i)
#define ROF(i,a,b) for(decltype(b) i = (b)-1; i >= (a); --i)
#define F0R(i,a) FOR(i,0,a)
#define R0F(i,a) ROF(i,0,a)

template<class T> bool ckmin(T& a, const T b) { return a > b ? a = b, 1 : 0; } 
template<class T> bool ckmax(T& a, const T b) { return a < b ? a = b, 1 : 0; } 

#define dbg(...) { cerr << "[Line " << __LINE__ << "] " << #__VA_ARGS__ << " is "; de(__VA_ARGS__); } 
#define m1(x) template<class T, class... U> void x(T&& a, U&&... b)
#define m2(x) (int[]){(x forward<U>(b), 0)...}

m1(de) { cerr << forward<T>(a); m2(cerr << " " <<); cerr << endl; }
m1(pr) { cout << forward<T>(a); m2(cout << " " <<); cout << "\n"; }
m1(re) { cin >> forward<T>(a); m2(cin >>); }

template<class T> void in(T a, T b) { assert(a != b); while(b - a) re(*a), ++a; }
template<class T> void out(T a, T b) { assert(a != b); while(b - a - 1) cout << *a << " ", ++a; pr(*--b); }

const int _ = 2e5 + 5, MOD = 1e9 + 7, INF = 0x3f3f3f3f, xd[] = {0,1,0,-1}, yd[] = {1,0,-1,0};
const ll INFLL = 0x3f3f3f3f3f3f3f3f;

#define io(x) if(fopen(x ".in","r")) freopen(x ".in","r",stdin), freopen(x ".out","w",stdout)

struct ar {
	ll a[5];
	bool operator<(const ar& b) const { F0R(i,5) if(a[i] != b.a[i]) return a[i] < b.a[i]; return 0; }
} v;

ll n;
map<ar,ll> setcnt; // how many cows like this subset of flavors
ll f[_][5];
ll ans;

// bitmask + PIE

ll lset,sz;

int main() { 
	cin.tie(0)->sync_with_stdio(0);
	io("cowpatibility");
	re(n);
	F0R(i,n) {
		in(all(f[i]));
		sort(all(f[i]));
		F0R(j,1<<5) {
			F0R(k,5) if((j >> k) & 1) v.a[lset] = f[i][k], ++lset;
			if(lset) ++setcnt[v];
			F0R(k,5) v.a[k] = 0; lset = 0;
		} // create counts for each subset
	}
	ans = n*(n-1)/2;
	trav(p,setcnt) {
		F0R(i,5) if(p.f.a[i] != 0) ++sz;
		ans -= (sz % 2 ? 1 : -1) * p.s * (p.s - 1)/2;
		sz = 0;
	}
	pr(ans);
}
