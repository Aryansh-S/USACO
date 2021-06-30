#include <bits/stdc++.h>  
#include <ext/pb_ds/assoc_container.hpp> //hset, hmap
#include <ext/pb_ds/tree_policy.hpp> //OST, OSM
#include <cxxabi.h> //for typenames
using namespace std; using namespace __gnu_pbds; //pbds memory :(	

//cmd + shift + r 

namespace aryansh { 
	namespace type_macros {
		using ll = long long; using db = double; using ld = long double; using str = string; 
		using pii = pair<int,int>; using pll = pair<ll,ll>; using vi = vector<int>; using vll = vector<ll>; 
		template<class T, int SZ> using ar = array<T, SZ>; //tuples
		template<class T> using mset = multiset<T>; template<class T, class U> using mmap = multimap<T, U>; 
		
		template<class T> using minpq 
			= priority_queue<T, vector<T>, greater<T>>;
		template<class T> using maxpq 
			= priority_queue<T>;
		
		template<class T> using OST 
			= tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; 
		template<class T> using MOST //allow multi
			= tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>; 
		template<class T, class U> using OSM 
			= tree<T, U, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
		template<class T, class U> using MOSM //allow multi
			= tree<T, U, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
		
		template<class T, class chash = hash<T>> using hset 
			= gp_hash_table<T, null_type, chash>; 
		template<class T, class U, class chash = hash<T>> using hmap 
			= gp_hash_table<T, U, chash>; 
				//don't bother using unordered types, use a custom hash argument if you want
				//struct chash {int operator()(T x) const {/*return hash id*/}}; if hash<T> doesn't exist
		
		template<class T> inline str type_name() { 
			typedef typename remove_reference<T>::type TR;
			unique_ptr<char, void(*)(void*)> own
				(abi::__cxa_demangle(typeid(TR).name(), nullptr,nullptr,nullptr),free); 
			str r = own != nullptr ? own.get() : typeid(TR).name();
			if (is_const<TR>::value) 
				r += " const";
			if (is_volatile<TR>::value) 
				r += " volatile";
			if (is_lvalue_reference<T>::value) 
				r += "&";
			else if (is_rvalue_reference<T>::value) 
				r += "&&";
			return r;
		}
		
		template<class T> class is_iterator { //check if iterator or pointer   
			static T makeT();
			typedef void * twoptrs[2];  
			static twoptrs & test(...); 
			template<class R> static typename R::iterator_category * test(R); // Iterator
			template<class R> static void * test(R *); // Pointer
			public: static const bool value = sizeof(test(makeT())) == sizeof(void *); 
		};
		template<class T> class is_streamable { //check if can be used with cin >>, cout << 
			template<typename SS, typename TT> static auto test(int)->
			decltype(declval<SS&>() << declval<TT>(),true_type());
			template<typename, typename> static auto test(...)->false_type;
			public: static const bool value = decltype(test<ostream, const T&>(0))::value;
		};
	}
	using namespace type_macros; 

	namespace func_macros {
		#define fbo find_by_order 
			//which element has x ones < it, or end
		#define ook order_of_key 
			//how many elements are/would be < it, or end
		
		#define pb push_back
		#define pf push_front
		#define eb emplace_back 
			//faster than push
		#define ef emplace_front
		#define emp emplace 
			//faster than ins, not for pbds
		
		#define ins insert
		#define ft front
		#define bk back
		
		#define ppb pop_back
		#define ppf pop_front
		#define ers erase
		#define clr clear
		
		#define mp make_pair
			//prefer to {}
		#define f first
		#define s second
		
		template<class T> inline T sq(T a) { return a * a; }
		template<class T> inline T sqdist(pair<T,T> a, pair<T,T> b) { return sq(a.f - b.f) + sq(a.s - b.s); }
		
		#define empt(x) (x).empty()
		#define sz(x) (empt(x) ? 0 : (int)(x).size())
		#define rsz resize
		
		#define lb lower_bound 
			//first el in [left_it,right_it) >= val
		#define ub upper_bound 
			//first el in [left_it,right_it) > val
				//set::lb/ub, not std::lb/ub
		
		template<class T, typename fnc> T bsearch(T l, T r, fnc&& works, T inval = -1, int tp = 3) { 
			//search works() in [l,r], where works() is an inequality bool >= or <= 
			//tp = 0 for find min, tp = 1 for find max (inferred unless forced)
			//returns inval if invalid
			if(tp != 0 && tp != 1) tp = works(l); //check if forced
			T lo = l, hi = r, ans = tp ? r : l;
			while(lo <= hi) {
				T mid = lo + (hi - lo) / 2; 
				if(works(mid)) ans = mid, tp ? lo = mid + 1 : hi = mid - 1;
				else tp ? hi = mid - 1 : lo = mid + 1; 
			}
			return works(ans) ? ans : inval; 
		}
		
		#define all(x) begin(x),end(x)
		#define rall(x) end(x),begin(x)
	}
	using namespace func_macros;

	namespace loop_macros {
		#define trav(a,x) for(auto&(a):(x))
		
		#define FOR(i,a,b) \
			for(auto i=decltype(b){(a)-((a)>(b))};i!=(b)-((a)>(b));((a)>(b))?--i:++i) //[lb,ub-1]
		#define FOR_(i,a,b,d) \
			for(auto i=decltype(b){(a)-((a)>(b))};(a>b)?(i>b-1):(i<b);i+=(((a)>(b))?-1:1)*abs(d)) //[lb,ub-1] by d
		
		#define F0R(i,b) FOR(i,0,b)
		#define F0R_(i,b,d) FOR_(i,0,b,d)
		#define F1R(i,b) FOR(i,1,b+1) //inclusive both ends
		#define F1R_(i,b,d) FOR_(i,1,b+1,d)
		
		#define R0F(i,n) FOR(i,n,0)
		#define R0F_(i,b,d) FOR_(i,b,0,d)
		#define R1F(i,b) FOR(i,b+1,1)
		#define R1F_(i,b,d) FOR_(i,b+1,1,d)
	}
	using namespace loop_macros;
	
	namespace const_macros {
		const int MOD = 1e9 + 7, MODP = 998244353, _ = 1e5 + 5, __ = 2 * _, INF = 0x3f3f3f3f;
		const ll INFLL = 0x3f3f3f3f3f3f3f3f; 
		const db EPS = 1e-8;
	}
	using namespace const_macros;
	
	namespace math_macros {
		template<class T, class U> bool ckmin(T& a, U b) { return a > b ? a = b, 1 : 0; } 
		template<class T, class U> bool ckmax(T& a, U b) { return a < b ? a = b, 1 : 0; } 
		
		ll gcd(ll a, ll b) { return (a == 0 || b == 0) ? max(abs(a), abs(b)) : __gcd(a, b); }
		ll lcm(ll a, ll b) { return (a == 0 || b == 0) ? 0 : a * b / gcd(a, b); }
		
		struct mi { //modular int -- with ll for best results
			typedef decay<decltype(MOD)>::type T; T val; 
			explicit operator T() const { return val; }
			mi() { val = 0; }
			mi(ll v) { val = (-MOD <= v && v <= MOD) ? v : v % MOD; if (val < 0) val += MOD; }
			friend bool operator==(const mi& a, const mi& b) { return a.val == b.val; }
			friend bool operator!=(const mi& a, const mi& b) { return !(a == b); }
			friend bool operator<(const mi& a, const mi& b) { return a.val < b.val; }
			friend bool operator>(const mi& a, const mi& b) { return a.val > b.val; }
			friend istream& operator>>(istream& is, mi& a) { is >> a.val; a = mi(a.val); return is; }
			friend ostream& operator<<(ostream& os, const mi& a) { return os << a.val; }
			mi operator-() const { return mi(-val); }
			mi& operator+=(const mi& m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
			mi& operator-=(const mi& m) { if ((val -= m.val) < 0) val += MOD; return *this; }
			mi& operator++() { return *this += 1; }
			mi& operator--() { return *this -= 1; }
			friend mi operator+(mi a, const mi& b) { return a += b; }
			friend mi operator-(mi a, const mi& b) { return a -= b; }
			mi& operator*=(const mi& m) { val = (ll)val*m.val%MOD; return *this; }
			friend mi pow(mi a, ll p) {
				mi ans = 1; assert(p >= 0);
				for (; p; p /= 2, a *= a) if (p&1) ans *= a;
				return ans;
			}
			friend mi inv(const mi& a) { assert(!(a == 0)); return pow(a,MOD-2); }
			mi& operator/=(const mi& m) { return (*this) *= inv(m); }
			friend mi operator*(mi a, const mi& b) { return a *= b; }
			friend mi operator/(mi a, const mi& b) { return a /= b; }
		};
		
		const int xd[4] = {0,1,0,-1}, yd[4] = {1,0,-1,0}; 
			//use with grid/floodfill
	}
	using namespace math_macros;

	namespace rand_macros {
		mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
		uniform_int_distribution<int> unifd(-INF,INF);
		#define RAND unifd(mt) //set const @beginning for hash
	}
	using namespace rand_macros;

	namespace io_macros {
		#define NL cout << "\n"
		
		template<typename T, typename = typename enable_if<is_streamable<T>::value>::type> 
		inline void in(T& var1)
			{cin >> var1;}
		template<typename T1, typename T2> inline void in(pair<T1,T2>&pt)
			{in(pt.f); in(pt.s);}
		template<typename T, typename...Types> inline void in(T& var1, Types&...var2)
			{in(var1); in(var2...);}
		template<typename it, typename = typename enable_if<is_iterator<it>::value>::type> 
		inline void in(it bg, it nd) 
			{while(distance(bg,nd)) in(*bg), ++bg;}
		
		inline void out() { NL; }
		template<typename T, typename = typename enable_if<is_streamable<T>::value>::type> 
		inline void out_(T var1)
			{cout << var1;}
    		template<typename T, typename = typename enable_if<is_streamable<T>::value>::type> 
    		inline void out(T var1) 
      			{cout << var1; NL;}
		template<typename T1, typename T2> inline void out_(pair<T1,T2> pt)
			{out_(pt.f); cout << " "; out_(pt.s);}
		template<typename T, typename...Types> inline void out(T var1, Types...var2)
			{out_(var1); cout << " "; out(var2...);}   
		template<typename it, typename = typename enable_if<is_iterator<it>::value>::type> 
		inline void out(it bg, it nd) 
			{while(distance(bg,nd)) out_(*bg), cout << " ", ++bg; NL;}
		
		inline void outln(){}
		template<typename T, typename = typename enable_if<is_streamable<T>::value>::type> 
		inline void out_ln(T var1)
			{cout << var1; NL;}
		template<typename T1, typename T2> inline void out_ln(pair<T1,T2> pt)
			{out_(pt.f); out_(pt.s); NL;}
		template<typename T, typename...Types> inline void outln(T var1, Types...var2)
			{out_ln(var1); outln(var2...);}   
		template<typename it, typename = typename enable_if<is_iterator<it>::value>::type> 
		inline void outln(it bg, it nd)    
			{while(distance(bg,nd)) outln(*bg), ++bg;}
			
			//functions: out and outln, use all/rsz for containers, use fwd ptr ranges
			//only works with linear containers

		#define TIME \
			chrono::duration<ld, milli>(chrono::steady_clock::now()-CLK).count()
		
		#define TICK \
			CLK = chrono::steady_clock::now() 
		
		#define what(x) \
			cout << "[Line " << __LINE__ << "] "; cout << (#x) << " is "; out(x)
		
		#define pres(d) \
			cout.precision(d); cout.setf(ios::fixed,ios::floatfield)
		
		#define mem(a,v) \
			if(type(a[0]).find("int")!=string::npos && (!(v) || !((v)+1) || !((v)-INF) || !((v)+INF))) { \
				(memset(&(a)[0],(v),sizeof(a))); \
			} else {trav(k,(a)) {k=v;}} static_assert(1, "") 
		
		#define type(x) type_name<decltype(x)>()
		
		#define IO(PNAME) \
			if(fopen(PNAME ".in","r")) freopen(PNAME ".in","r",stdin), freopen(PNAME ".out","w",stdout); \
			cin.tie(0)->sync_with_stdio(0); TICK
	}
	using namespace io_macros;
}
using namespace aryansh; auto TICK; //for best results, TICK after input taken 

// - - - - - - - - - - - - - - - - - - - - - - - -

int n,m; map<pii,pii> pipe;

template <class T, int SZ> struct Dijk { //class T is the type of weight being used, works in O(E log V)
  vi adj[SZ]; T dist[SZ]; bool vis[SZ];
  int mom[SZ];
  void add(int a, int b) { adj[a].pb(b); adj[b].pb(a); } //a->b
  void upd(int start){
    F0R(i,SZ) dist[i]=(i!=start)?INF:0, vis[i]=0, mom[i]=i;
    minpq<pair<T,int> > q;
    q.push(mp(0,start));
    while(!q.empty()){
      auto curr=q.top(); q.pop(); vis[curr.s]=1;
      trav(v,adj[curr.s]){
        if(vis[v]) continue;
        if(dist[v]>dist[curr.s]+pipe[mp(curr.s,v)].f){
          dist[v]=dist[curr.s]+pipe[mp(curr.s,v)].f;
          mom[v]=curr.s;
          q.push(mp(dist[v],v));
        }
      }
    }
  }
  T qry(int v){return dist[v];}
  T qry_(int st, int v){upd(st); return qry(v);}
  vector<pii> path(int v){
    vector<pii> ret; int i=v;
    while(mom[i]!=i){ret.pb(mp(mom[i],i)),i=mom[i];}
    reverse(all(ret)); return ret;
  }
  vector<pii> path_(int st, int v){
    upd(st); return path(st,v);
  }
};

int ans; Dijk<int,_> d; const int sc = 1e6; 

int main() {
  IO("pump");
  in(n,m); 
	F0R(i,m) { 
		int a,b,c,f; 
		in(a,b,c,f),--a,--b;
		pipe[mp(a,b)]=pipe[mp(b,a)]=mp(c,f); d.add(a,b);
	}
	d.upd(0);
	F0R(i,n) { //keep removing min flow pipe and ckmax
		int cst = d.qry(n-1), fl = INF; pii bade;
		vector<pii> pth = d.path(n-1);
		trav(e,pth) if(ckmin(fl,pipe[e].s)) bade=e; 
		if(cst < INF) ckmax(ans,((db)fl/cst)*sc); 
		pipe[bade] = pipe[mp(bade.s,bade.f)] = mp(INF,0); d.upd(0);
	}
	out(ans);
}

// // // // // // // // // // // // // // // // //
// do something! stay organized!                //  
// int overflow : ll                            //
// segfault : exit(9), goto pt; pt: <do smth>;  //
// wrong ans : what(x)                          //
// tle : if(TIME > 2000)                        //
// index carefully!                             //
// sort global array : use a + n, not all(a)    //
// bsearch if monotonic                         //
// try amortized, use stack/queue, heuristic    //
// if using double/ld use PRES(d)               //
// runtime : 1e7 usually, 2e8 edgy              //
// careful using ++, etc. for macros like all() //
// // // // // // // // // // // // // // // // //
