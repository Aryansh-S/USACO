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
      
      #define sq(x) (x)*(x)
      
      #define empt(x) (x).empty()
      #define sz(x) (empt(x) ? 0 : (int)(x).size())
      #define rsz resize
      
      #define lb lower_bound 
      //first el in [left_it,right_it) >= val
      #define ub upper_bound 
      //first el in [left_it,right_it) > val
      //set::lb/ub, not std::lb/ub
      
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
      
      inline void out(){NL;}
      template<typename T, typename = typename enable_if<is_streamable<T>::value>::type> 
      inline void out_(T var1)
      {cout << var1 << " ";}
      template<typename T1, typename T2> inline void out_(pair<T1,T2> pt)
      {out_(pt.f); out_(pt.s);}
      template<typename T, typename...Types> inline void out(T var1, Types...var2)
      {out_(var1); out(var2...);}   
      template<typename it, typename = typename enable_if<is_iterator<it>::value>::type> 
      inline void out(it bg, it nd) 
      {while(distance(bg,nd)) out_(*bg), ++bg; NL;}
      
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
  
  template<class T> struct SEG {
    const T ID = 0; T comb(T a, T b) { return a + b; } 
    
    int n; vector<T> seg; 
    
    void init(int n0) { n = n0; seg.assign(2 * n, ID); }    
    template<typename it, typename = typename enable_if<is_iterator<it>::value>::type> 
    void init(it bg, it nd) { init(distance(bg, nd)); move(bg, nd, begin(seg) + n); build(); }
    
    void build() { int i = n - 1; do pull(i); while(--i); }
    
    inline int lc(int p) { return 2 * p; }
    inline int rc(int p) { return lc(p) + 1; }
    void pull(int p) { seg[p] = comb(seg[lc(p)], seg[rc(p)]); }
    
    void upd(int p, T v) {
      seg[p += n] = v; 
      for(p /= 2; p; p /= 2) pull(p);
    }
    T qry(int l, int r) {
      T ra = ID, rb = ID; 
      for(l += n, r += n + 1; l < r; l /= 2, r /= 2) {
        if(l & 1) ra = comb(ra, seg[l++]); 
        if(r & 1) rb = comb(seg[--r], rb);
      }
      return comb(ra, rb); 
    }
  };
  
  int n,k; vi v,w; SEG<int> s; 
  
  bool works(int m, int p) {
    return s.qry(0,m) >= p;
  }
  
  int main() {
    IO("");
    in(n); v.rsz(n); w.rsz(n); mem(w,1); s.init(all(w));  
    in(all(v)); 
    F0R(i,n) {
      int p; in(p); 
      int lo = 0, hi = n - 1, ans = 0; 
      while(lo <= hi) {
        int mid = hi + (lo - hi) / 2; 
        if(works(mid, p)) ans = mid, hi = mid - 1; 
        else lo = mid + 1; 
      }
      out_(v[ans]); 
      s.upd(ans,0); 
    } NL; 
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
