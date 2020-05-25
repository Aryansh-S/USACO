#include <bits/stdc++.h>
using namespace std;

//an adaptive lazy segtree that supports any kind of query 

#define pb push_back
#define eb emplace_back
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

char /*global*/ bevvlazy='s'; //controls query type
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
	pair<T,T> sum[4*SZ+1];
	T lazy[4*SZ+1];
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
	pair<T,T> qsum(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) { //count # of min or # of max
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

LSEG<double,10> test; 

int main(){

  test.choose('s'); //choose query
  
  test.upd(1,2,10.2);
  test.upd(2,4,12.3);
  cout << test.query(1,4) << "\n";
	
  test.choose('M');
  cout << test.query(1,4) << "\n";

  return 0;
}
