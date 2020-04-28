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
#define trav(a,x) for(auto&(a):(x))
#define FOR(i,a,b) for(__typeof(b)i=(a)-((a)>(b));i!=(b)-((a)>(b));i+=((a)>(b))?-1:1) //go from i=lb to i=ub-1
#define FOR_(i,a,b,d) for(__typeof(b)i=(a)-((a)>(b));(a>b)?(i>b-1):(i<b);i+=(((a)>(b))?-1:1)*abs(d)) //go from i=lb to i=ub-1 by size d increments
#define F0R(i,b) FOR(i,0,b)
#define F0R_(i,b,d) FOR_(i,0,b,d)
#define R0F(i,n) FOR(i,n,0)
#define what(x) out((#x),"is",(x))
#define big (int)1e5
#define bigg (int)(1e9+7)

void in(){} void outln(){} void out_(){cout << "\n";} //for fast, easy IO
template<typename T, typename...Types> void in(T& var1, Types&...var2){cin >> var1; in(var2...);}
template<typename T> void out(T var1){cout << var1 << "\n";}
template<typename T, typename...Types> void out(T var1, Types...var2){cout << var1 << " "; out(var2...);}
template<typename T, typename...Types> void outln(T var1, Types...var2){cout << var1 << "\n"; outln(var2...);}
template<typename T> void out_(T var1){cout << var1 << " ";}

bool comps(const pii&p1, const pii&p2){return (p1.s<p2.s);} //sort and search with special pair conditions & compare int-pair
struct intpairf{bool operator()(const pii&a, const int&b){return(a.f<b);} bool operator()(const int&a, const pii&b){return(a<b.f);}};
struct intpairs{bool operator()(const pii&a, const int&b){return(a.s<b);} bool operator()(const int&a, const pii&b){return(a<b.s);}};

struct DSU{ //from 0 to n
	vi e; void init(int n) { e = vi(n,-1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) { // union-by-rank
		x = get(x), y = get(y); if (x == y) return 0;
		if (e[x] > e[y]) swap(x,y);
		e[x] += e[y]; e[y] = x; return 1;
	}
	int compnum(){ //return the number of components
		int ret=1;
		F0R(i,sz(e)-1) if(get(i)!=get(i+1)) ret++;
		return ret;
	}
};

template<class T> struct SEG{ //UPD literally updates!!
	const T orz=-10*big;
	char choice='s'; //'m' is min, 'M' is max, 's' is sum
	void choose(char ch){choice=ch;}
	T comb(T a, T b){
		if(a==orz){if(b==orz){return 0;} return b;}
		if(b==orz) return a;
		if(choice=='m') return min(a,b);
		if(choice=='s') return a+b;
		if(choice=='M') return max(a,b);
	}
	int n; vector<T> seg;
		void init(int _n) { n = _n; seg.assign(2*n,orz); }
		void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
		void upd(int p, T val) { // set val at position p
			seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
		T query(int l, int r) {	// query choice on interval [l, r]
			T ra = orz, rb = orz;
			for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
				if (l&1) ra = comb(ra,seg[l++]);
				if (r&1) rb = comb(seg[--r],rb);
			}
			return comb(ra,rb);
	}
};

char /*global*/ bevvlazy='s';
int IDENN=0;
template<class T> pair<T,T> operator+(const pair<T,T>& l, const pair<T,T>& r) {
	if(bevvlazy=='s') IDENN=0;
	if(bevvlazy=='m') IDENN=bigg;
	if(bevvlazy=='M') IDENN=-bigg;
	if(bevvlazy=='s') {return mp(l.f+r.f,l.s+r.s);}
	if (l.f != r.f){
		if(bevvlazy=='m') {return min(l,r);}
		if(bevvlazy=='M') {return max(l,r);}
	}
	return mp(l.f,l.s+r.s);
}
template<class T, int SZ> struct LSEG{ //updates by adding, 1 indexed
	pair<T,T> sum[2*SZ];
	T lazy[2*SZ];
	LSEG() {
		memset(sum,0,sizeof sum);
		memset(lazy,0,sizeof lazy);
	}
	void choose(char choice){bevvlazy=choice; /*m for min, M for max, s for sum*/}
	void push(int ind, int L, int R) { // modify values for current node
		sum[ind].f += lazy[ind];
		if (L != R) lazy[2*ind] += lazy[ind], lazy[2*ind+1] += lazy[ind];
		lazy[ind] = 0; // pushed lazy to children
	}
	void pull(int ind) { // recalc values for current node
		sum[ind] = sum[2*ind]+sum[2*ind+1]; }
	void build() {
		FOR(i,SZ,2*SZ) sum[i] = mp(0,1);
		FOR(i,1,SZ) pull(i);
	}
	void upd(int lo, int hi, int inc, int ind = 1, int L = 0, int R = SZ-1) {
		push(ind,L,R);
		if (hi < L || R < lo) return;
		if (lo <= L && R <= hi) {
			lazy[ind] = inc;
			push(ind,L,R); return;
		}
		int M = (L+R)/2;
		upd(lo,hi,inc,2*ind,L,M); upd(lo,hi,inc,2*ind+1,M+1,R);
		pull(ind);
	}
	pair<T,T> qsum(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
		push(ind,L,R);
		if (lo > R || L > hi) return mp(IDENN,0);
		if (lo <= L && R <= hi) return sum[ind];
		int M = (L+R)/2;
		return qsum(lo,hi,2*ind,L,M)+qsum(lo,hi,2*ind+1,M+1,R);
	}
	T query(int lo, int hi, int ind=1, int L=0, int R=SZ-1){
		return qsum(lo,hi,ind,L,R).f;
	}
};

#define PNAME ""

int main(){
	cin.tie(0)->sync_with_stdio(0); if(fopen(PNAME ".in","r")){freopen(PNAME ".in","r",stdin); freopen(PNAME ".out","w",stdout);}
	/*update_tree(1, 0, N-1, 0, 6, 5); // Increment range [0, 6] by 5
	update_tree(1, 0, N-1, 7, 10, 12); // Incremenet range [7, 10] by 12
	update_tree(1, 0, N-1, 10, N-1, 100); // Increment range [10, N-1] by 100*/
	LSEG<int,100> seg; seg.choose('s'); seg.upd(1,2,3); out(seg.query(1,2));
	return 0;
}