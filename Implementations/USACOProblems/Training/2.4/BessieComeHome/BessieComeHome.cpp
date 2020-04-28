#include <bits/stdc++.h>
using namespace std;
//see dijkstra struct in long template

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
template<class T> using minpq = priority_queue<T, vector<T>, greater<T> >;
template<class T> using maxpq = priority_queue<T>;
#define pb push_back
#define ins insert
#define mp make_pair
#define f first
#define s second
#define sz(x) (int)(x).size()
#define rsz resize
#define lb lower_bound
#define ub upper_bound
#define all(x) begin(x),end(x)
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
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-8
#define ckmin(a,b) a=min(a,b)
#define ckmax(a,b) a=max(a,b)

void in(){} void outln(){} void out_(){cout << "\n";} //for fast, easy IO
template<typename T, typename...Types> void in(T& var1, Types&...var2){cin >> var1; in(var2...);}
template<typename T> void out(T var1){cout << var1 << "\n";}
template<typename T, typename...Types> void out(T var1, Types...var2){cout << var1 << " "; out(var2...);}
template<typename T, typename...Types> void outln(T var1, Types...var2){cout << var1 << "\n"; outln(var2...);}
template<typename T> void out_(T var1){cout << var1 << " ";}

bool comps(const pii&p1, const pii&p2){return (p1.s!=p2.s)?(p1.s<p2.s):(p1.f<p2.f);} //sort and search with special pair conditions & compare int-pair
struct intpairf{bool operator()(const pii&a, const int&b){return(a.f!=b)?(a.f<b):(a.s<b);}
bool operator()(const int&a, const pii&b){return(a!=b.f)?(a<b.f):(a<b.s);}};
struct intpairs{bool operator()(const pii&a, const int&b){return(a.s!=b)?(a.s<b):(a.f<b);}
bool operator()(const int&a, const pii&b){return(a!=b.s)?(a<b.s):(a<b.f);}};

#define PNAME ""

template <class T, int SZ> struct Dijk{ //class T is the type of weight being used, works in O(E log V)
	vector<pair<T,int> > adj[SZ]; T dist[SZ]; bool vis[SZ];
	void add(int a, int b, T w){adj[a].pb(mp(w,b)); adj[b].pb(mp(w,a));}
	void add_(int a, int b, T w){adj[a].pb(mp(w,b));} //if edge is directed
	void upd(int start){
		F0R(i,SZ) dist[i]=(i!=start)?INF:0, vis[i]=0;
		minpq<pair<T,int> > q;
		q.push(mp(0,start));
		while(!q.empty()){
			auto curr=q.top(); q.pop(); vis[curr.s]=1;
			trav(v,adj[curr.s]){
				if(vis[v.s]) continue;
				if(dist[v.s]>dist[curr.s]+v.f){
				   dist[v.s]=dist[curr.s]+v.f;
				   q.push(mp(dist[v.s],v.s));
				}
			}
		}
	}
	T query(int v){return dist[v];}
	T query_(int st, int v){upd(st); return query(v);}
};

bool cap(char a){return (a<'a');}
int ctoi(char a){return (int)a-60;}
int p, ans=INF, ans2, edge[100][100]; char anschr; Dijk<int,110> d; set<int> cow;

int main(){
	cin.tie(0)->sync_with_stdio(0); if(fopen(PNAME ".in","r")){freopen(PNAME ".in","r",stdin); freopen(PNAME ".out","w",stdout);}
	F0R(i,100) F0R(j,100) edge[i][j]=INF;
	in(p); F0R(i,p){
	    char a,b; int c; in(a,b,c); if(cap(a) && a!='Z') cow.ins(ctoi(a));
	    if(cap(b) && b!='Z') cow.ins(ctoi(b)); 
	    ckmin(edge[ctoi(a)][ctoi(b)],c); ckmin(edge[ctoi(b)][ctoi(a)],c); 
	}
	F0R(i,100) F0R(j,100) d.add_(i,j,edge[i][j]);
	d.upd(ctoi('Z'));
	trav(i,cow) ckmin(ans,d.query(i));
	trav(i,cow) if(d.query(i)==ans) ans2=i;
	anschr=(char)(ans2+60);
	out(anschr,ans);
	return 0;
}
