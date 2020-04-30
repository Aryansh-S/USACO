#include <bits/stdc++.h>
using namespace std;

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

template<class T, int SZ> struct Prim{ // T is type weight
    minpq<pair<T,int> > temp; //key,vertex
    bool vis[SZ]; int mom[SZ]; T key[SZ];
    Prim(){F0R(i,SZ) mom[i]=-1;}
    vector<pair<T,int> > adj[SZ]; //store weight first
    void add(int a, int b, T w){
        adj[a].pb(mp(w,b)); adj[b].pb(mp(w,a));
    }
    void add_(int a, int b, T w){ //directed edge
        adj[a].pb(mp(w,b));
    }
    void upd(int rt=0){ //root the MST at rt
        mom[rt]=rt; //let the root be its own mom
        F0R(i,SZ) if(i!=rt) key[i]=INF;
        temp.push(mp(0,rt));
        F0R(i,SZ) if(i!=rt) temp.push(mp(INF,i));
        while(!temp.empty()){
            auto curr=temp.top(); temp.pop(); vis[curr.s]=1;
            for(auto v:adj[curr.s]){
                if(!vis[v.s] && key[v.s]>v.f){
                    key[v.s]=v.f; temp.push(mp(key[v.s],v.s));
                    mom[v.s]=curr.s;
                }
            }
        }
    }
    int par(int v){return mom[v];} //get parent
    array<vi,SZ> dirMST(){
        //want parent to contain all children
        array<vi,SZ> ret;
        F0R(i,SZ) if(mom[i]!=-1) ret[mom[i]].pb(i);  
        return ret; 
    }
    array<vi,SZ> undirMST(){
        array<vi,SZ> ret;
        F0R(i,SZ) if(mom[i]!=-1) {ret[mom[i]].pb(i); ret[mom[i]].pb(i);}
        return ret;
    }
    T sum(){T ret=0; F0R(i,SZ) if(vis[i] && key[i]!=INF) ret+=key[i]; return ret;}
};

const int mx=105;
int n,mat[mx][mx],ans; Prim<int,mx> p; //len of MST

int main(){
	cin.tie(0)->sync_with_stdio(0); if(fopen(PNAME ".in","r")){freopen(PNAME ".in","r",stdin); freopen(PNAME ".out","w",stdout);}
	
	in(n); F0R(i,n) F0R(j,n) in(mat[i][j]),p.add_(i,j,mat[i][j]);
	p.upd(); out(p.sum());
	/*auto a=p.dirMST();
	F0R(i,n) trav(j,a[i]) ans+=mat[i][j];
	out(ans);*/ we can also get the sum directly from the MST adj list 
	
	return 0;
}
