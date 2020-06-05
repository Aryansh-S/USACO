#include <bits/stdc++.h>  
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <cxxabi.h> //for typenames
using namespace std; using namespace __gnu_pbds; 

namespace aryansh { 
	namespace type_macros {
		typedef long long ll; 
		typedef long double ld;
		typedef double db;
		typedef string str;
		typedef pair<int,int> pii; 
		typedef pair<ll,ll> pll;
		typedef vector<int> vi;
		template<class T> using minpq = priority_queue<T, vector<T>, greater<T> >;
		template<class T> using maxpq = priority_queue<T>;
		template<class T> using OST = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; 
		template<class T, class U> using OSM = tree<T, U, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
		template<class T> using hset = gp_hash_table<T, null_type, hash<T>>; //don't use unordered types 
		template<class T, class U> using hmap = gp_hash_table<T, U, hash<T>>; 
		template<class T> inline str type_name() { //get type as string
			typedef typename remove_reference<T>::type TR;
			unique_ptr<char, void(*)(void*)> own(abi::__cxa_demangle(typeid(TR).name(), nullptr,nullptr,nullptr),free); 
			str r = own != nullptr ? own.get() : typeid(TR).name();
			if (is_const<TR>::value) r += " const";
			if (is_volatile<TR>::value) r += " volatile";
			if (is_lvalue_reference<T>::value) r += "&";
			else if (is_rvalue_reference<T>::value) r += "&&";
			return r;
		}
	}
	using namespace type_macros; 

	namespace func_macros {
		#define fbo find_by_order //which element has x ones < it, or end
		#define ofk order_of_key //how many elements are/would be < it, or end
		#define pb push_back
		#define pf push_front
		#define ppb pop_back
		#define ppf pop_front
		#define eb emplace_back
		#define ef emplace_front
		#define ins insert
		#define emp emplace //faster than ins, not for pbds
		#define ers erase
		#define mp make_pair
		#define f first
		#define s second
		#define empt(x) (x).empty()
		#define sz(x) (empt(x) ? 0 : (int)(x).size())
		#define sq(x) (x)*(x)
		#define rsz resize
		#define lb lower_bound //first el in [left_it,right_it) >= val
		#define ub upper_bound //first el in [left_it,right_it) > val
		#define has(x,y) ((x).find(y)!=end(x)) //for nonlinear containers
		#define all(x) begin(x),end(x)
		#define rall(x) end(x),begin(x)
	}
	using namespace func_macros;

	namespace loop_macros {
		#define trav(a,x) for(auto&(a):(x))
		#define FOR(i,a,b) for(auto i=decltype(b){(a)-((a)>(b))};i!=(b)-((a)>(b));((a)>(b))?--i:++i) //go from i=lb to i=ub-1
		#define F0R(i,b) FOR(i,0,b)
		#define FOR_(i,a,b,d) for(auto i=decltype(b){(a)-((a)>(b))};(a>b)?(i>b-1):(i<b);i+=(((a)>(b))?-1:1)*abs(d)) //go from i=lb to i=ub-1 by size d increments
		#define F0R_(i,b,d) FOR_(i,0,b,d)
		#define R0F(i,n) FOR(i,n,0)
		#define R0F_(i,b,d) FOR_(i,b,0,d)
		#define F1R(i,b) FOR(i,1,b+1)
		#define R1F(i,b) FOR(i,b+1,1)
		#define F1R_(i,b,d) FOR_(i,1,b+1,d)
		#define R1F_(i,b,d) FOR_(i,b+1,1,d)
	}
	using namespace loop_macros;

	namespace const_macros {
		#define big (int)1e5
		#define bigg (int)(1e9+7)
		#define MOD (int)(1e9+7)
		#define INF 0x3f3f3f3f
		#define INFLL 0x3f3f3f3f3f3f3f3f
		#define EPS 1e-8
	}
	using namespace const_macros;
	
	namespace math_macros {
		#define ckmin(a,b) a=min(a,b)
		#define ckmax(a,b) a=max(a,b)
		#define gcd(a,b) ((!(a) || !(b)) ? (max(abs(a),abs(b))) : (__gcd((a),(b))))
		#define lcm(a,b) ((!(a) || !(b)) ? 0 : ((a)*(b))/gcd((a),(b)))
		ll POW(ll a, ll b) { //log
			ll res = 1; while(b) res *= (b & 1)? a : 1, a*=a, b>>=1;
			return res;
		}
		struct mi { //modular int
			typedef decay<decltype(MOD)>::type T;
			T val; 
			explicit operator T() const { return val; }
			mi() { val = 0; }
			mi(ll v) { 
				val = (-MOD <= v && v <= MOD) ? v : v % MOD;
				if (val < 0) val += MOD;
			}
			friend bool operator==(const mi& a, const mi& b) { 
				return a.val == b.val; }
			friend bool operator!=(const mi& a, const mi& b) { 
				return !(a == b); }
			friend bool operator<(const mi& a, const mi& b) { 
				return a.val < b.val; }
			friend ostream& operator<<(ostream& os, const mi& a) { 
				return os << a.val; }
			mi operator-() const { return mi(-val); }
			mi& operator+=(const mi& m) { 
				if ((val += m.val) >= MOD) val -= MOD; 
				return *this; }
			mi& operator-=(const mi& m) { 
				if ((val -= m.val) < 0) val += MOD; 
				return *this; }
			mi& operator++() { return *this += 1; }
			mi& operator--() { return *this -= 1; }
			friend mi operator+(mi a, const mi& b) { return a += b; }
			friend mi operator-(mi a, const mi& b) { return a -= b; }

			mi& operator*=(const mi& m) { 
				val = (ll)val*m.val%MOD; return *this; }
			friend mi pow(mi a, ll p) {
				mi ans = 1; assert(p >= 0);
				for (; p; p /= 2, a *= a) if (p&1) ans *= a;
				return ans;
			}
			friend mi inv(const mi& a) { 
				assert(!(a == 0)); return pow(a,MOD-2); }
			mi& operator/=(const mi& m) { return (*this) *= inv(m); }
			friend mi operator*(mi a, const mi& b) { return a *= b; }
			friend mi operator/(mi a, const mi& b) { return a /= b; }
		};
		typedef unsigned long long ull;
		typedef __uint128_t L128;
		struct FastMod {
			ull b, m;
			FastMod(ull b) : b(b), m(ull((L128(1) << 64) / b)) {}
			ull reduce(ull a) {
				ull q = (ull)((L128(m) * a) >> 64), r = a - q * b;
				return r >= b ? r - b : r;
			}
		};
	}
	using namespace math_macros;
	
	namespace grid_macros {
		const int xd[4] = {0,1,0,-1}, yd[4] = {1,0,-1,0}; 
		template<class T> struct bd{ //bdi for inclusive bounded int
			  T v = 0, l = 0, r = 1;
			  bd(T _v, T _l, T _r){l=_l,r=_r,v=_v; if(v < l) v = l; if(v > r) v = r;}
			  operator T(){return v;}
			  bd<T> operator++(){
			    bd<T> tmp(v,l,r); tmp.v = v + 1 > r ? r : ++v; return tmp; 
			  }
			  bd<T> operator--(){
			    bd<T> tmp(v,l,r); tmp.v = v - 1 < l ? l : --v; return tmp;
			  }
			  bd<T> operator+(int d){
			    bd<T> tmp(v,l,r); (d > 0) ? (tmp.v = v + d > r ? r : v + d) : (tmp.v = v + d < l ? l : v + d);
			    return tmp; 
			  }
			  bd<T> operator-(int d){return operator+(-1*d);}
		};
		using bdi = bd<int>;
	}
	using namespace grid_macros;

	namespace time_macros {
		auto TIME0 = chrono::steady_clock::now(); 
		#define TIME chrono::duration<double, milli>(chrono::steady_clock::now()-TIME0).count()
	}
	using namespace time_macros;

	namespace rand_macros {
		mt19937 mt(std::chrono::steady_clock::now().time_since_epoch().count());
		uniform_int_distribution<int> unifd(-INF,INF);
		#define RAND unifd(mt)
	}
	using namespace rand_macros;

	namespace io_macros {
		inline void in(){} inline void outln(){} inline void out_(){} //for fast, easy IO
		template<typename T, typename...Types> inline void in(T& var1, Types&...var2){cin >> var1; in(var2...);}
		template<typename T> inline void out(T var1){cout << var1 << "\n";}
		template<typename T, typename...Types> inline void out(T var1, Types...var2){cout << var1 << " "; out(var2...);}
		template<typename T, typename...Types> inline void outln(T var1, Types...var2){cout << var1 << "\n"; outln(var2...);}
		template<typename T,typename...Types> inline void out_(T var1, Types...var2){cout << var1 << " "; out_(var2...);}
		template<class T1, class T2> inline void in(pair<T1,T2>&pt){in(pt.f,pt.s);} 
		template<class T1, class T2> inline void out(pair<T1,T2> pt){out(pt.f,pt.s);}
		template<class T1, class T2> inline void out_(pair<T1,T2> pt){out_(pt.f,pt.s);}
		template<class T> inline void in(vector<T>&v,int sz){F0R(i,sz){T x; in(x); v.pb(x);}}
		template<class T> inline void in(T*a,int sz){F0R(i,sz) in(a[i]);}
		template<class T> inline void out(vector<T> v){trav(t,v) out(t);}
		template<class T> inline void out(vector<T> v,int sz){trav(t,v) out(t);}
		template<class T> inline void out_(vector<T> v){trav(t,v) out_(t);} //might need to int cast size
		template<class T> inline void out_(vector<T> v,int sz){trav(t,v) out_(t);}
		template<class T> inline void out(T*a,int sz){F0R(i,sz) out(a[i]);}
		template<class T> inline void out_(T*a,int sz){F0R(i,sz) out_(a[i]);}
		#define PRES(d) cout.precision(d);cout.setf(ios::fixed,ios::floatfield)
		#define MEM(a,v) if((!(v) || !((v)+1) || !((v)-INF) || !((v)+INF))) {\
		    (memset(&(a)[0],(v),sizeof(a)));}else {trav(k,(a)) {k=v;}}static_assert(1, "")
		#define NL cout << "\n"
		#define what(x) out_((#x));out_("is");out_(x);NL
        	#define type(x) type_name<decltype(x)>()
		#define IO(PNAME) if(fopen(PNAME ".in","r")){freopen(PNAME ".in","r",stdin);freopen(PNAME ".out","w",stdout);}cin.tie(0)->sync_with_stdio(0)
	}
	using namespace io_macros;
} //cmd + shift + r
using namespace aryansh;

// - - - - - - - - - - - - - - - - - - - - -

template<class T> struct SEG { // comb(ID,b) = b, 0-indexing works, any associative operation. 
	//seg[1] = qry(0,n-1) 
	const T ID = -INF; T comb(T a, T b) { return max(a,b); } 
	int n; vector<T> seg;
	void init(int _n) { n = _n; seg.assign(2*n, ID); } 
    	void init(vector<T>& v) { init(v.size()); move(begin(v), end(v), begin(seg) + n); build(); }
    	void init(T* a, int _n) { init(_n); move(a, a + n, begin(seg) + n); build(); }
    	void build() { for(int i = n - 1; i > 0; --i) pull(i); }
	void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
	void upd(int p, T val) { // set val at position p
		seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); 
    	}
	T qry(int l, int r) {	// comb on interval [l, r]
		T ra = ID, rb = ID; 
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = comb(ra,seg[l++]);
			if (r&1) rb = comb(seg[--r],rb);
		}
		return comb(ra,rb);
	}
};

int nxtpw2(int v) {
	if((bool)v & !(v & (v - 1))) return v; 
	int x = 1; while(x < v) x<<=1; return x; 
}

SEG<int> s; //segtree for bsearch

int bs(int node, int t) { //leftmost >=t, start with node = 1 (top)
    if(node >= s.n) return node - s.n;
    int lc = 2 * node, rc = lc + 1;
    if(s.seg[lc] >= t) return bs(lc,t);
    if(s.seg[rc] >= t) return bs(rc,t);
    return -1;
} //bsearch in only log, not log^2, easily :)

int n,t; vi v; 

int main() {
    IO("");
    in(n,t); in(v,n);
    v.rsz(nxtpw2(sz(v)));
    s.init(v);
    out(bs(1,t)); //gives idx
    //s.upd...
}


// - - - - - - - - - - - - - - - - - - - - -
	/* 
		do something! use ll if int overflow, analyze time complexity 
		~10^7 usually, at most 10^8, 2*10^8 is pushing it, i.e. n=10^5 is O(n log n) -- if(TIME>2000ms) -> TLE
		careful on sorting global arrays! the zeroes can mess things up, so if using array, instead of all(a) use a,a+n
		check 0-index, use exit(9) for segfault tests, check array index, use what() to debug
		look to amortize, use stacks/queues, heuristic, binary search for ans if monotonic, etc.
		if using double/ld use PRES(d) 
	*/
// - - - - - - - - - - - - - - - - - - - - -