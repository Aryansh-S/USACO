#include <bits/stdc++.h>
using namespace std;

//#define int ll 
typedef long long ll; //only use above for test
typedef long double ld;
typedef double db;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
template<class T> using minpq = priority_queue<T, vector<T>, greater<T> >;
template<class T> using maxpq = priority_queue<T>;
#define pb push_back
#define ins insert
#define ers erase
#define mp make_pair
#define f first
#define s second
#define sz(x) (int)(x).size()
#define sq(x) (x)*(x)
#define rsz resize
#define lb lower_bound
#define ub upper_bound
#define all(x) begin(x),end(x)
#define rall(x) end(x),begin(x)
#define trav(a,x) for(auto&(a):(x))
#define FOR(i,a,b) for(__typeof(b)i=(a)-((a)>(b));i!=(b)-((a)>(b));i+=((a)>(b))?-1:1) //go from i=lb to i=ub-1
#define F0R(i,b) FOR(i,0,b)
#define FOR_(i,a,b,d) for(__typeof(b)i=(a)-((a)>(b));(a>b)?(i>b-1):(i<b);i+=(((a)>(b))?-1:1)*abs(d)) //go from i=lb to i=ub-1 by size d increments
#define F0R_(i,b,d) FOR_(i,0,b,d)
#define R0F(i,n) FOR(i,n,0)
#define R0F_(i,b,d) FOR_(i,b,0,d)
#define F1R(i,b) FOR(i,1,b+1)
#define R1F(i,b) FOR(i,b+1,1)
#define F1R_(i,b,d) FOR_(i,1,b+1,d)
#define R1F_(i,b,d) FOR_(i,b+1,1,d)
#define what(x) out((#x),"is",(x))
#define big (int)1e5
#define bigg (int)(1e9+7)
#define MOD (int)(1e9+7)
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-8
#define ckmin(a,b) a=min(a,b)
#define ckmax(a,b) a=max(a,b)
#define TIME chrono::duration<double, milli>(chrono::steady_clock::now()-TIME0).count()
#define PRES(d) cout.precision(d);cout.setf(ios::fixed,ios::floatfield)

#include <random>
auto TIME0=chrono::steady_clock::now(); //lim=2000ms, use TIME for curr time
//srand(SEED) to set SEED, rand() to get 
random_device rd;mt19937 mt(rd()+std::chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> unifd(-INF,INF);
#define RAND unifd(mt)
//can be negative

void in(){} void outln(){} void out_(){cout << "\n";} //for fast, easy IO
template<typename T, typename...Types> void in(T& var1, Types&...var2){cin >> var1; in(var2...);}
template<typename T> void out(T var1){cout << var1 << "\n";}
template<typename T, typename...Types> void out(T var1, Types...var2){cout << var1 << " "; out(var2...);}
template<typename T, typename...Types> void outln(T var1, Types...var2){cout << var1 << "\n"; outln(var2...);}
template<typename T> void out_(T var1){cout << var1 << " ";}

struct comps{bool operator()(const pii&p1, const pii&p2){return (p1.s!=p2.s)?(p1.s<p2.s):(p1.f<p2.f);}}; 
//sort and search with special pair conditions & compare int-pair
struct ipf{bool operator()(const pii&a, const int&b){return(a.f!=b)?(a.f<b):(a.s<b);}
bool operator()(const int&a, const pii&b){return(a!=b.f)?(a<b.f):(a<b.s);}};
struct ips{bool operator()(const pii&a, const int&b){return(a.s!=b)?(a.s<b):(a.f<b);}
bool operator()(const int&a, const pii&b){return(a!=b.s)?(a<b.s):(a<b.f);}};
//in some cases use struct() and other cases use struct

#define PNAME ""

signed main(){
	cin.tie(0)->sync_with_stdio(0); if(fopen(PNAME ".in","r")){freopen(PNAME ".in","r",stdin); freopen(PNAME ".out","w",stdout);}
	return 0; //read the bottom
}

//do something! use ll if int overflow, analyze time complexity 
//-- ~10^6 usually, at most 10^7, 10^8 is pushing it, i.e. n=10^5 is O(n log n) -- if(TIME>2000ms) -> TLE
//careful on sorting global arrays! the zeroes can mess things up, so if using array, instead of all(a) use a,a+n
//check 0-index, use exit(0) for segfault tests, check array index, use what() to debug
//look to amortize, use stacks/queues, heuristic, binary search for ans if monotonic, etc.
//if using double/ld use PRES(d)
