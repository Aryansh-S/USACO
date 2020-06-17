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

#define PNAME "haircut"

ll n,a[big],ans[big],inv,invel[big]; //invel is inv of any given element
BIT<ll,big> bit;

int main(){
	cin.tie(0)->sync_with_stdio(0); if(fopen(PNAME ".in","r")){freopen(PNAME ".in","r",stdin); freopen(PNAME ".out","w",stdout);}
	in(n); F0R(i,n) {in(a[i]); a[i]+=2;} //2 to n+1
	//figure out total inv in O(n log n), and then update BIT over j=n-1 to j=0 (backprocess)
	//inversions can be found thru right-left scan
	FOR(i,n,0){ //1...n-1
		inv+=bit.query(1,a[i]-1);
		invel[a[i]]+=bit.query(1,a[i]-1);
		bit.upd(a[i],1); //each val in BIT is either 0 or 1; BIT stores whether an element has showed up or not
	}
	FOR(j,n,0){
		//make all strands greater than j equal to j -> how does this change inv?
		//upd inv in real time
		//inv should get smaller and smaller
		//binary search for lower bound of j that's present -> all >=j should be j
		//we need to make any val greater than j 0 in BIT -> how does this change INV
		inv-=invel[j+2]; //0 to n-1 becomes 2 to n+1
		ans[j]=inv;
	}
	ans[0]=0;
	F0R(j,n) out(ans[j]);
	return 0;
}