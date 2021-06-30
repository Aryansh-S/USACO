#include <bits/stdc++.h>  
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std; using namespace __gnu_pbds;
using ll = long long; using pii = pair<int,int>; 
#define vt vector
using vi = vt<int>;
#define ar array
template<class T, class U = null_type, class chash = hash<T>> using hset = gp_hash_table<T,U,chash>; 
template<class T, class U = null_type, class cmp = less<T>> using oset = tree<T,U,cmp,rb_tree_tag,tree_order_statistics_node_update>;
#define fbo find_by_order
#define ook order_of_key
template<class T> using is_it = typename enable_if< is_convertible< class iterator_traits<T>::iterator_category, input_iterator_tag >::value >::type;
#define dbg(...) { cerr << "[Line " << __LINE__ << "] " << #__VA_ARGS__ << " is "; de(__VA_ARGS__); } 
void de(auto&&a, auto&&...b) {
	((cerr << a) << ... << (cerr << " ", b)) << "\n";
}
template<class T, class = is_it<T>> void de(T&&a, T&&b) {
	string s = ""; 
	for_each(a, b, [&](auto&&x) { cerr << s << x, s = " "; }); 
	cerr << endl;
}
void pr(auto&&a, auto&&...b) {
	((cout << a) << ... << (cout << " ", b)) << "\n";
}
template<class T, class = is_it<T>> void pr(T&&a, T&&b) {
	string s = ""; 
	for_each(a, b, [&](auto&&x) { cout << s << x, s = " "; }); 
	cout << "\n";
}
void re(auto&&...a) {
	(cin >> ... >> a);
}
template<class T, class = is_it<T>> void re(T&&a, T&&b) {
	for_each(a, b, [&](auto&&x) { cin >> x; }); 
}
bool ckmin(auto& a, const auto b) { return a > b ? a = b, 1 : 0; } 
bool ckmax(auto& a, const auto b) { return a < b ? a = b, 1 : 0; } 
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
#define rsz resize
#define lb lower_bound
#define ub upper_bound 
#define sz(x) (int)size(x)
#define all(x) begin(x),end(x)
#define trav(a,...) for(auto&a:__VA_ARGS__)
#define FOR(i,a,b) for(decltype(b) i = (a); i < (b); ++i)
#define ROF(i,a,b) for(decltype(b) i = (b)-1; i >= (a); --i)
#define F0R(i,a) FOR(i,0,a)
#define R0F(i,a) ROF(i,0,a)

const int N = 2e5 + 5, MOD = 1e9 + 7, INF = 0x3f3f3f3f, xd[] = {0,1,0,-1}, yd[] = {1,0,-1,0};
const ll INFLL = 0x3f3f3f3f3f3f3f3f;

auto f1(auto lo, auto hi, auto&& f) {
	if(!(f(hi) > f(lo))) return -1; // f must increase
	while(lo < hi) {
		auto mid = lo + (hi - lo) / 2; 
		f(mid) ? hi = mid : lo = mid + 1; 
	}
	return lo; 
}

ll ans; int n;
vi v; // idx to breed
vt<vi> breed; // breed to idx

int bit[N];
int sol[N];
vt<pii> query[N];
map<int, int> fst;
 
int qry(int i) {
	int res = 0; for (; i; i -= i&(-i)) { res += bit[i]; }
	return res;
}
void upd(int i, int val) {
	for (; i <= n; i += i & (-i)) { bit[i] += val; }
}

int nxt(int idx) { // next index with same breed or -1 if none
	int b = v[idx]; // this is the breed, and we need to search breed[b]
	int idx_within_breed = f1(0,sz(breed[b])-1,[&](int x){return breed[b][x] > idx;});
	if(idx_within_breed == -1) return -1;
	return breed[b][idx_within_breed];
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  re(n); v.rsz(n), breed.rsz(n); re(all(v)); 
  trav(t,v) --t; // zero index breeds
  F0R(i,n) breed[v[i]].eb(i); // put each cow in its breed vector
  F0R(i,n) { 
  	int l, r; 
  	l = i; 
  	r = ((nxt(l) != -1) ? (nxt(l)-1) : (n-1));
  	query[l+1].eb(r+1,i); // setup queries
  }
  for(int i = n; i >= 1; --i) {
  	int z = v[i-1];
  	if(fst.count(z)) upd(fst[z],-1);
  	fst[z] = i; upd(i,1); 
  	trav(t,query[i]) sol[t.s] = qry(t.f);
	}
	trav(t,sol) ans += t;
  pr(ans-n);
}
