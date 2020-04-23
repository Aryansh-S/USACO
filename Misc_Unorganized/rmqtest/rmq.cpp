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
	char choice; //'m' is min, 'M' is max, 's' is sum
	void choose(char ch){choice=ch;}
	T comb(T a, T b) {return (a==orz)?((b==orz)?0:b):((b==orz)?a:(choice=='m')?min(a,b):(choice=='s')?a+b:max(a,b));}
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

template<int SZ> struct SEG_r{ // declare globally
	template<class T> bool ckmax(T& a, const T& b) {
		return a < b ? a = b, 1 : 0; }
	int N, mx[2*SZ][2], maxCnt[2*SZ];
	ll sum[2*SZ];
	void pull(int ind) {
		F0R(i,2) mx[ind][i] = max(mx[2*ind][i],mx[2*ind+1][i]);
		maxCnt[ind] = 0;
		F0R(i,2) {
			if (mx[2*ind+i][0] == mx[ind][0])
				maxCnt[ind] += maxCnt[2*ind+i];
			else ckmax(mx[ind][1],mx[2*ind+i][0]);
		}
		sum[ind] = sum[2*ind]+sum[2*ind+1];
	}
	void build(vi& a, int ind = 1, int L = 0, int R = -1) {
		if (R == -1) { R = (N = sz(a))-1; }
		if (L == R) {
			mx[ind][0] = sum[ind] = a[L];
			maxCnt[ind] = 1; mx[ind][1] = -1;
			return;
		}
		int M = (L+R)/2;
		build(a,2*ind,L,M); build(a,2*ind+1,M+1,R); pull(ind);
	}
	void push(int ind, int L, int R) {
		if (L == R) return;
		F0R(i,2) if (mx[2*ind^i][0] > mx[ind][0]) {
			sum[2*ind^i] -= (ll)maxCnt[2*ind^i]*
							(mx[2*ind^i][0]-mx[ind][0]);
			mx[2*ind^i][0] = mx[ind][0];
		}
	}
	void upd(int x, int y, int t, int ind=1, int L=0, int R=-1) {
		if (R == -1) R += N;
		if (R < x || y < L || mx[ind][0] <= t) return;
		push(ind,L,R);
		if (x <= L && R <= y && mx[ind][1] < t) {
			sum[ind] -= (ll)maxCnt[ind]*(mx[ind][0]-t);
			mx[ind][0] = t;
			return;
		}
		if (L == R) return;
		int M = (L+R)/2;
		upd(x,y,t,2*ind,L,M); upd(x,y,t,2*ind+1,M+1,R); pull(ind);
	}
	ll qsum(int x, int y, int ind = 1, int L = 0, int R = -1) {
		if (R == -1) R += N;
		if (R < x || y < L) return 0;
		push(ind,L,R);
		if (x <= L && R <= y) return sum[ind];
		int M = (L+R)/2;
		return qsum(x,y,2*ind,L,M)+qsum(x,y,2*ind+1,M+1,R);
	}
	int qmax(int x, int y, int ind = 1, int L = 0, int R = -1) {
		if (R == -1) R += N;
		if (R < x || y < L) return -1;
		push(ind,L,R);
		if (x <= L && R <= y) return mx[ind][0];
		int M = (L+R)/2;
		return max(qmax(x,y,2*ind,L,M),qmax(x,y,2*ind+1,M+1,R));
	}
};

template <class T, int ...Ns> struct BIT{ //UPD only adds!!
	//general Fenwick BIT struct with range sum queries and point updates for D dimensions
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
template<class T, int SZ> struct BIT_r{ //range update, range query
	BIT<T,SZ> bit[2]; // piecewise linear functions
	// let cum[x] = sum_{i=1}^{x}a[i]
	void upd(int hi, T val) { // add val to a[1..hi]
		// if x <= hi, cum[x] += val*x
		bit[1].upd(1,val), bit[1].upd(hi+1,-val);
		// if x > hi, cum[x] += val*hi
		bit[0].upd(hi+1,hi*val);
	}
	void upd(int lo,int hi,T val){upd(lo-1,-val),upd(hi,val);}
	T sum(int x) { return bit[1].sum(x)*x+bit[0].sum(x); }
	T query(int x, int y) { return sum(y)-sum(x-1); }
};
template <const int maxN> struct OST{ //goal: alternative to R&B ordered statistic tree policy -- operations rank & find kth smallest
	BIT<int, maxN> tree;
	void ins(int x){if(!tree.query(x,x)) tree.upd(x,1);}
	void del(int x){if(tree.query(x,x)) tree.upd(x,-1);}
	int ofk(int x){return (tree.query(x,x))?(tree.sum(x)-1):tree.sum(x);} //order of key (small to large)
	int fbo(int k){ //find by order
		k++;
		int l = 0; //check to make sure this exists!!!
		int h = maxN;
		while(l<h){
		   int mid=(l+h)/2;
		   if(k<=tree.sum(mid)) h=mid;
		   else l = mid+1;
		}
		return l;
	} //coordinate compression is a good idea when possible!!
};

#define PNAME "rmqtest"

ll n,q; SEG<ll> seg;

int main(){
	cin.tie(0)->sync_with_stdio(0); if(fopen(PNAME ".in","r")){freopen(PNAME ".in","r",stdin); freopen(PNAME ".out","w",stdout);}
	/*update_tree(1, 0, N-1, 0, 6, 5); // Increment range [0, 6] by 5
	update_tree(1, 0, N-1, 7, 10, 12); // Incremenet range [7, 10] by 12
	update_tree(1, 0, N-1, 10, N-1, 100); // Increment range [10, N-1] by 100*/

	seg.choose('m');
	in(n,q); seg.init(n+5); F0R(i,n){ll x; in(x); seg.upd(i,x);}
	F0R(i,q){int x,y; in(x,y); out(seg.query(x-1,y-1));}

	return 0;
}
