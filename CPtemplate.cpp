#include <bits/stdc++.h>  
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std; using namespace __gnu_pbds; 

// :pray: :fishy15: :pray: :summitosity: :pray: :prodakcin: 

// C++ Template (Aryansh Shrivastava) -- run w/ cmd+shift+r

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
		template<class T> using hset = gp_hash_table<T, null_type, hash<T>>; 
		template<class T, class U> using hmap = gp_hash_table<T, U, hash<T>>;
	}
	using namespace type_macros; 

	namespace func_macros {
		#define fbo find_by_order
		#define ofk order_of_key
		#define pb push_back
		#define pf push_front
		#define ppb pop_back
		#define ppf pop_front
		#define eb emplace_back
		#define ef emplace_front
		#define ins insert
		#define ers erase
		#define mp make_pair
		#define f first
		#define s second
		#define empt(x) (x).empty()
		#define sz(x) (empt(x) ? 0 : (int)(x).size())
		#define sq(x) (x)*(x)
		#define rsz resize
		#define lb lower_bound //first el in [l,r) >= val
		#define ub upper_bound //first el in [l,r) > val
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
		void in(){} void outln(){} void out_(){} //for fast, easy IO
		template<typename T, typename...Types> void in(T& var1, Types&...var2){cin >> var1; in(var2...);}
		template<typename T> void out(T var1){cout << var1 << "\n";}
		template<typename T, typename...Types> void out(T var1, Types...var2){cout << var1 << " "; out(var2...);}
		template<typename T, typename...Types> void outln(T var1, Types...var2){cout << var1 << "\n"; outln(var2...);}
		template<typename T,typename...Types> void out_(T var1, Types...var2){cout << var1 << " "; out_(var2...);}
		template<class T1, class T2> void in(pair<T1,T2>&pt){in(pt.f,pt.s);} 
		template<class T1, class T2> void out(pair<T1,T2> pt){out(pt.f,pt.s);}
		template<class T1, class T2> void out_(pair<T1,T2> pt){out_(pt.f,pt.s);}
		template<class T> void in(vector<T>&v,int sz){F0R(i,sz){T x; in(x); v.pb(x);}}
		template<class T> void in(T*a,int sz){F0R(i,sz) in(a[i]);}
		template<class T> void out(vector<T> v){trav(t,v) out(t);}
		template<class T> void out(vector<T> v,int sz){trav(t,v) out(t);}
		template<class T> void out_(vector<T> v){trav(t,v) out_(t);}
		template<class T> void out_(vector<T> v,int sz){trav(t,v) out_(t);}
		template<class T> void out(T*a,int sz){F0R(i,sz) out(a[i]);}
		template<class T> void out_(T*a,int sz){F0R(i,sz) out_(a[i]);}
		#define what(x) out((#x),"is",(x))
		#define PRES(d) cout.precision(d);cout.setf(ios::fixed,ios::floatfield)
		#define MEM(a,v) if((!(v) || !((v)+1) || !((v)-INF) || !((v)+INF))) {\
		    (memset((a),(v),sizeof(a)));}else {trav(k,(a)) {k=v;}}static_assert(1, "")
		#define NL cout << "\n"
		#define IO(PNAME) if(fopen(PNAME ".in","r")){freopen(PNAME ".in","r",stdin);freopen(PNAME ".out","w",stdout);}cin.tie(0)->sync_with_stdio(0)
	}
	using namespace io_macros;
}

using namespace aryansh;

// - - - - - - - - - - - - - - - - - - - - -



int main() {
	IO(""); 
	
}


// - - - - - - - - - - - - - - - - - - - - -
	/* 
		do something! use ll if int overflow, analyze time complexity 
		~10^7 usually, at most 10^8, 2*10^8 is pushing it, i.e. n=10^5 is O(n log n) -- if(TIME>2000ms) -> TLE
		careful on sorting global arrays! the zeroes can mess things up, so if using array, instead of all(a) use a,a+n
		check 0-index, use exit(0) for segfault tests, check array index, use what() to debug
		look to amortize, use stacks/queues, heuristic, binary search for ans if monotonic, etc.
		if using double/ld use PRES(d) 
	*/
// - - - - - - - - - - - - - - - - - - - - -
