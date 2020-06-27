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
		const int MOD = 1e9 + 7, _ = 1e5, INF = 0x3f3f3f3f;
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

struct LSEG {
	using R = array<int, 2>; 
		// Range type -- begin, end indices
	using L = ll; 
		// Lazy type -- type you want to update with 
	using Q = ll; 		
		// Query type -- type you want to query for

	L lop(const L &lazy, const R &r0, const L &x, const R &r1) {
		return x;
	} 
		// how does a lazy operation in range r1 "add" with one in range r0? r1 always contains r0

	Q qop(const Q &lval, const R &r0, const Q &rval, const R &r1) {
		return lval ^ rval; 
	} 
		// what is the query operation between lval and rval? always r0[1] == r1[0]

	Q aop(const Q &val, const R &r0, const L &x, const R &r1) {
		return x;
	} 
		// how does the lazy operation apply over a range? r1 always contains r0

	const pair<L, Q> id = {INF, 0}; 
		//ids of lazy and query types

	Q init(const int &p) { return 0; } 
		//how to initialize all queries 

	vector<int> roots; int n, h;
	vector<R> range; vector<L> lazy; 
	vector<Q> val; 
		//this is equivalent of seg, last n are leaves

	template<typename it, typename = typename enable_if<is_iterator<it>::value>::type> 
	LSEG(it bg, it nd): n(distance(bg, nd)), h(__lg(n) + 1), range(2 * n), lazy(2 * n, id.first), val(n, id.second) {
		init_range();
		val.insert(end(val), bg, nd);
		build(0, n);
	}
	LSEG(int n): n(n), h(__lg(n) + 1), range(2 * n), lazy(2 * n, id.first), val(2 * n) {
		init_range();
		for(int i = n; i < 2 * n; ++i) val[i] = init(i - n);
		build(0, n);
	}

	inline int lc(int p) { return 2 * p; }
	inline int rc(int p) { return lc(p) + 1; }

	void init_roots() {
		vector<int> roots_r;
		for(auto l = n, r = 2 * n; l < r; l /= 2, r /= 2) {
			if(l & 1) roots.push_back(l++);
			if(r & 1) roots_r.push_back(--r);
		}
		roots.insert(end(roots), begin(roots_r), end(roots_r));
	}
	void init_range() {
		for(int i = n; i < 2 * n; ++i) range[i] = {i - n, i - n + 1};
		for(int i = n - 1; i > 0; --i) range[i] = {range[lc(i)][0], range[rc(i)][1]};
	}

	void refresh(int p) {
		if(p < n) val[p] = qop(val[lc(p)], range[lc(p)], val[rc(p)], range[rc(p)]);
		if(lazy[p] != id.first) val[p] = aop(val[p], range[p], lazy[p], range[p]);
	}
	void build(int l, int r) {
		for(l += n, r += n - 1; l > 1; ) {
			l /= 2, r /= 2;
			for(int i = r; i >= l; --i) refresh(i);
		}
	}

	void push(int l, int r) {
		int s = h;
		for(l += n, r += n - 1; s > 0; --s) {
			for(int i = l >> s; i <= r >> s; ++i) if(lazy[i] != id.first) {
				val[lc(i)] = aop(val[lc(i)], range[lc(i)], lazy[i], range[i]);
				lazy[lc(i)] = lop(lazy[lc(i)], range[lc(i)], lazy[i], range[i]);
				val[rc(i)] = aop(val[rc(i)], range[rc(i)], lazy[i], range[i]);
				lazy[rc(i)] = lop(lazy[rc(i)], range[rc(i)], lazy[i], range[i]);
				lazy[i] = id.first;
			}
		}
	}

	void upd(int l, int r, L x) {
    		++r; //for the sake of inclusivity on right bound
		if(l >= r) return;
		const R update_range{l, r};
		push(l, l + 1), push(r - 1, r);
		bool cl = 0, cr = 0;
		for(l += n, r += n; l < r; l /= 2, r /= 2) {
			if(cl) refresh(l - 1);
			if(cr) refresh(r);
			if(l & 1) {
				val[l] = aop(val[l], range[l], x, update_range);
				if(l < n) lazy[l] = lop(lazy[l], range[l], x, update_range);
				++l;
				cl = 1;
			}
			if(r & 1) {
				--r;
				val[r] = aop(val[r], range[r], x, update_range);
				if(r < n) lazy[r] = lop(lazy[r], range[r], x, update_range);
				cr = 1;
			}
		}
		for(--l; r > 0; l /= 2, r /= 2) {
			if(cl) refresh(l);
			if(cr && (!cl || l != r)) refresh(r);
		}
	}
	Q qry(int l, int r) {
    		++r; //for the sake of inclusivity on right bound
		push(l, l + 1);
		push(r - 1, r);
		Q resl = id.second, resr = id.second;
		R l_range{l, l}, r_range{r, r};
		for(l += n, r += n; l < r; l /= 2, r /= 2) {
			if(l & 1) resl = qop(resl, l_range, val[l], range[l]), l_range[1] = range[l][1], ++l;
			if(r & 1) --r, resr = qop(val[r], range[r], resr, r_range), r_range[0] = range[r][0];
		}
		return qop(resl, l_range, resr, r_range);
	}
	/*
	void print() {
		for(int u = 0; u < 2 * n; ++u){
			cout << u << "-th node represents [" << range[u][0] << ", " << range[u][1] 
			<< "], val = " << val[u] << ", lazy = " << lazy[u] << "\n";
		}
	}
	*/
};

template<int SZ, bool EDGE = 1> struct HLD { //get LSEG; add all edges, then init
  vector<int> adj[SZ], rpos; //rpos not used, but could be useful
  int par[SZ], root[SZ], depth[SZ], siz[SZ], pos[SZ]; 
  int ti;
  
  void add(int x, int y) { adj[x].pb(y), adj[y].pb(x); }
  void init(int R = 0) {
    par[R] = depth[R] = ti = 0; dfsSz(R); 
    root[R] = R; dfsHld(R); 
  }

  LSEG tree; using T = LSEG::Q;
  const T ID = tree.id.second; 
  T comb(T a, T b) { return tree.qop(a, LSEG::R(), b, LSEG::R()); } //T is query type
  HLD() : tree(SZ) {}
  
  void dfsSz(int x) { 
    siz[x] = 1; 
    trav(y, adj[x]) {
      par[y] = x; depth[y] = depth[x]+1;
      adj[y].erase(find(all(adj[y]), x)); //remove parent from adj list
      dfsSz(y); siz[x] += siz[y];
      if(siz[y] > siz[adj[x][0]]) swap(y, adj[x][0]);
    }
  }
  void dfsHld(int x) {
    pos[x] = ti++; rpos.pb(x);
    trav(y,adj[x]) {
      root[y] = (y == adj[x][0] ? root[x] : y);
      dfsHld(y); 
    }
  }
  
  int lca(int x, int y) {
    for(; root[x] != root[y]; y = par[root[y]])
      if(depth[root[x]] > depth[root[y]]) swap(x,y);
    return depth[x] < depth[y] ? x : y;
  }
  int dist(int x, int y) { //# edges on path
    return depth[x] + depth[y] - 2 * depth[lca(x,y)]; 
  }

  template<typename fnc> void processPath(int x, int y, fnc&& op) {
      for(; root[x] != root[y]; y = par[root[y]]) {
        if(depth[root[x]] > depth[root[y]]) swap(x, y);
        op(pos[root[y]], pos[y]); 
      }
      if(depth[x] > depth[y]) swap(x,y);
      op(pos[x] + EDGE, pos[y]); 
  }
  
  void updpath(int x, int y, int v) { 
      processPath(x,y,[this,&v](int l, int r) { 
      tree.upd(l,r,v); }); 
  }
  T qrypath(int x, int y) { 
      T res = ID; processPath(x,y,[this,&res](int l, int r) { 
      res = comb(res,tree.qry(l,r)); });
      return res; 
  }
  void updsubtree(int x, int v) { 
      tree.upd(pos[x] + EDGE, pos[x] + siz[x] - 1, v); 
  }
  T qrysubtree(int x) {
      return tree.qry(pos[x] + EDGE, pos[x] + siz[x] - 1);
  }
};

int n,q; ll e[_];
HLD<_,0> h;

int main() {
	IO("cowland");
  in(n,q); in(e,e+n); 
  F0R(i,n-1) { int a,b; in(a,b),--a,--b; h.add(a,b); }
  h.init(); 
  F0R(i,n) h.updpath(i,i,e[i]); 
  while(q--) {
    int t; in(t); 
    if(t == 1) {
      int i,v; in(i,v),--i; h.updpath(i,i,v); 
    }
    else {
      int i,j; in(i,j),--i,--j; out(h.qrypath(i,j)); 
    }
  }
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
// // // // // // // // // // // // // // // // //
