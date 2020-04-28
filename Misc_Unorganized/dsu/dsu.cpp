#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define pb push_back
#define ins insert
#define mp make_pair
#define f first
#define s second
#define sz(x) (x).size()
#define lb lower_bound
#define ub upper_bound
#define all(x) begin(x),end(x)
#define gint greater<int> //use with sort(all(), gint()) or set<int,gint> for backwards sort
#define lint lesser<int>
#define trav(a,x) for(auto&(a):(x))
#define FOR(i,a,b) for(__typeof(b)i=(a)-((a)>(b));i!=(b)-((a)>(b));i+=((a)>(b))?-1:1) //go from i=lb to i=ub-1
#define FOR_(i,a,b,d) for(__typeof(b)i=(a)-((a)>(b));(a>b)?(i>b-1):(i<b);i+=(((a)>(b))?-1:1)*abs(d)) //go from i=lb to i=ub-1 by size d increments
#define F0R(i,b) FOR(i,0,b)
#define F0R_(i,b,d) FOR_(i,0,b,d)
#define what(x) out((#x),"is",(x))
#define big (int)1e5
#define bigg (int)(1e9+7)

void in(){} void outln(){} void out_(){cout << "\n";}
template<typename T, typename...Types> void in(T& var1, Types&...var2){cin >> var1; in(var2...);}
template<typename T> void out(T var1){cout << var1 << "\n";}
template<typename T, typename...Types> void out(T var1, Types...var2){cout << var1 << ""; out(var2...);}
template<typename T, typename...Types> void outln(T var1, Types...var2){cout << var1 << "\n"; outln(var2...);}
template<typename T> void out_(T var1){cout << var1 << " ";}

bool comps(const pii&p1, const pii&p2){return (p1.s<p2.s);}
struct intpairf{bool operator()(const pii&a, const int&b){return(a.f<b);} bool operator()(const int&a, const pii&b){return(a<b.f);}};
struct intpairs{bool operator()(const pii&a, const int&b){return(a.s<b);} bool operator()(const int&a, const pii&b){return(a<b.s);}};

struct DSU{ //n is your maximum number
	vi e; void init(int n) { e = vi(n,-1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) { // union-by-rank
		x = get(x), y = get(y); if (x == y) return 0;
		if (e[x] > e[y]) swap(x,y);
		e[x] += e[y]; e[y] = x; return 1;
	}
};

template <class T, int ...Ns> struct BIT{ //general Fenwick BIT struct with range sum queries and point updates for D dimensions
	T val = 0; void upd(T v) {val += v;} //map<int,BIT> preferable to BIT array
	T query() {return val;} // * Usage: \texttt{BIT<int,10,10>} gives 2D BIT * Time: O((\log N)^D)
};
template <class T, int N, int... Ns> struct BIT<T, N, Ns...> { //general format (l1,r1,l2,r2,...) for queries
	BIT<T,Ns...> bit[N+1];
	template<typename... Args> void upd(int pos, Args... args) { //general format (pos1,pos2,...,val) for upd
		for (; pos<=N; pos+=pos&-pos) bit[pos].upd(args...); } //indexed by 1
	template<typename... Args> T sum(int r, Args... args) {
		T res=0; for (;r;r-=r&-r) res += bit[r].query(args...);
		return res; }
	template<typename... Args> T query(int l, int r, Args...
		args) { return sum(r,args...)-sum(l-1,args...); }
};


#define PNAME "dsu"
int ans=1;
int main(){
	cin.tie(0)->sync_with_stdio(0); if(fopen(PNAME ".in","r")){freopen(PNAME ".in","r",stdin); freopen(PNAME ".out","w",stdout);}
	DSU d; d.init(6); //0-1-2 3 4 5
	d.unite(0,1); d.unite(1,2);
	F0R(i,sz(d.e)-1) if(d.get(i)!=d.get(i+1)) ans++;
	out(ans);
	return 0;
}