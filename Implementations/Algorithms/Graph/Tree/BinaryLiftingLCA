#include <bits/stdc++.h>
using namespace std;
//level: gold
//objective: design a clean LCA method for any tree/DAG using binary lifting

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

template <int SZ> struct BLCA{ //lca with binary lifting
    vi adj[SZ]; const static int lg=32-__builtin_clz(SZ);
    int dp[SZ][lg],lvl[SZ]; BLCA(){F0R(i,SZ) memset(dp[i],-1,sizeof(dp[i]));}
    void add(int a, int b){adj[a].pb(b); adj[b].pb(a);}
    void add_(int a, int b){adj[a].pb(b);}
    void dfs(int u, int p){
        dp[u][0]=p; for(int i=1; i<lg; i++) dp[u][i]=dp[dp[u][i-1]][i-1];
        trav(v,adj[u]) if(v!=p) lvl[v]=lvl[u]+1,dfs(v,u);
    }
    int lca(int a, int b){
        if(lvl[a]<lvl[b]) swap(a,b);
        for(int i=lg-1; i>=0; i--) if(lvl[a]-pow(2,i)>=lvl[b]) a=dp[a][i];
        if(a==b) return a; for(int i=lg-1; i>=0; i--) if(dp[a][i]!=dp[b][i]) a=dp[a][i],b=dp[b][i]; return dp[a][0];
    }
    void upd(int rt=0){dfs(rt,0);}
    int dist(int a, int b){ //# of edges between a and b
        return lvl[a]+lvl[b]-2*lvl[lca(a,b)];
    }
};

BLCA<5> b;

int main(){
    
    b.add(0,1); b.add(0,2); b.add(1,3); b.add(1,4); 
    b.upd(); what(b.lca(3,4)),what(b.dist(2,3)); 

	return 0;
}
