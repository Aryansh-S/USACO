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

int n; 
vt<pii> v; 
ll ans;

bool ccw(pii a, pii b, pii c) {
	return (c.s - a.s) * (b.f - a.f) > (b.s - a.s) * (c.f - a.f);
}
bool isect(pii a, pii b, pii c, pii d) {
	bool isect_at_all = (ccw(a,c,d) != ccw(b,c,d) && ccw(a,b,c) != ccw(a,b,d)); 
	bool isect_endpt = (a == c || a == d || b == c || b == d);
	return isect_at_all && !isect_endpt;
}

vt<pair<pii,pii>> seg; // segments so far

int main() {
  cin.tie(0)->sync_with_stdio(0);
  // pr(isect({0,0},{1,1},{1,0},{0,1})); exit(0); 
  
  re(n); v.rsz(n);
  F0R(i,n) re(v[i].f,v[i].s);
  
  int ctr = 0;
  sort(all(v));
  do {
  	bool works = 1;
  	seg.eb(v[0],v[1]);
  	seg.eb(v[1],v[2]);
  	seg.eb(v[2],v[0]);
  	FOR(i,3,n) {
  		int cnt = 0; 
  		F0R(j,i) {
				bool b = 1;
				trav(t,seg) if(isect(v[i],v[j],t.f,t.s)) b = 0; 
				if(b) seg.eb(v[i],v[j]), ++cnt;
			}
			if(cnt != 3) works = 0;
		}
		if(works) ++ans, ans %= MOD;
		seg.clear();
	} while(next_permutation(all(v)));
	
	pr(ans % MOD);
}
