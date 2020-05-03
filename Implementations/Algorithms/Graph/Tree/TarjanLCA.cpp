#include <bits/stdc++.h>
using namespace std;
//level: advanced gold
//objective: use Tarjan's offline LCA algorithm with DSU to find O(Q) lowest common ancestors in linear time

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

template <int SZ> struct TLCA{ //offline tarjan LCA with in-built DSU 
    struct query{int x,y,lca;}; vector<query> queries;
    struct node{int mom,ancestor; bool seen; vi adj,qs;} nodes[SZ]; 
    //DSU
    int get(int x){return nodes[x].mom=(nodes[x].mom!=x)?get(nodes[x].mom):x;}
    void unite(int x, int y){nodes[get(x)].mom=get(y);}
    TLCA(){F0R(i,SZ) nodes[i].mom=nodes[i].ancestor=i;} 
    //add edges and queries
    void add(int a, int b){nodes[a].adj.pb(b); nodes[b].adj.pb(a);}
    void add_(int a, int b){nodes[a].adj.pb(b);}
    void addq(int x, int y){
        nodes[x].qs.pb(sz(queries)); nodes[y].qs.pb(sz(queries)); 
        query q; q.x=x,q.y=y,q.lca=-1; queries.pb(q);
    }
    //find lca recursive
    void findlca(int curr, int prev){
        trav(i,nodes[curr].adj) if(i!=prev){
            findlca(i,curr); unite(i,curr); nodes[get(curr)].ancestor=curr;
        }
        nodes[curr].seen=1; trav(i,nodes[curr].qs){
            int other_endpt=queries[i].x==curr?queries[i].y:queries[i].x;
            if(nodes[other_endpt].seen) queries[i].lca=get(other_endpt);
        }
    }
    void upd(int rt){findlca(rt,-1);}
    int lca(int qry){return queries[qry].lca;}
};

TLCA<5> t;

int main(){
	cin.tie(0)->sync_with_stdio(0); if(fopen(PNAME ".in","r")){freopen(PNAME ".in","r",stdin); freopen(PNAME ".out","w",stdout);}

    t.add(0,1); t.add(0,2); t.add(1,3); t.add(1,4);
    t.addq(0,1);
    t.upd(0); out(t.lca(0));

	return 0;
}
