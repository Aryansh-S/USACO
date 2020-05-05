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

struct DSU{ //from 0 to n-1
	vi e; void init(int n) { e = vi(n,-1); }
    bool rollback; vector<pair<pii,pii> > mod;
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
    DSU(int SZ=0){init(SZ);}
	bool unite(int x, int y) { // union-by-rank
		x = get(x), y = get(y);
        if(x==y){
            if(rollback) mod.pb(mp(mp(bigg,bigg),mp(bigg,bigg)));
            return 0;
        }
		if (e[x] > e[y]) swap(x,y);
        if(rollback) mod.pb(mp(mp(x,y),mp(e[x],e[y])));
		e[x] += e[y]; e[y] = x; return 1;
	}
    void setpar(int a, int b){e[b]=-1; if(e[a]<0) e[a]=b; else e[e[a]]=b;}
    void setrb(){rollback=1;}
    void rb(){
        auto a = mod.back(); mod.pop_back();
		if (a.f.f!= bigg) e[a.f.f]=a.s.f, e[a.f.s]= a.s.s;
    }
	int compnum(){ //return the number of components
		int ret=1;
		F0R(i,sz(e)-1) if(get(i)!=get(i+1)) ret++;
		return ret;
	}
};


struct StaticRMQ{ //uses DSU, offline avg O(1) w/o sparse table
    DSU d; stack<int> s; struct query{int l,r,idx;};
    vi v,ans; vector<vector<query> > cont;
    StaticRMQ(vi _v){v=_v; cont.rsz(sz(v)); d.init(sz(v));}
    void addq(int l, int r){
        int idx=sz(ans); query q; q.l=l,q.r=r,q.idx=idx;
        cont[q.r].pb(q); ans.pb(0);
    } 
    void upd(){
        F0R(i,sz(v)){
            while(!s.empty()&&v[s.top()]>v[i]) {d.setpar(s.top(),i);s.pop();}
            s.push(i); trav(q,cont[i]) ans[q.idx]=v[d.get(q.l)]; 
        }
    }
    int rmq(int id){return ans[id];}
};

vi v={-11111,4,3,2,5};
StaticRMQ r(v);

int main(){
	cin.tie(0)->sync_with_stdio(0); if(fopen(PNAME ".in","r")){freopen(PNAME ".in","r",stdin); freopen(PNAME ".out","w",stdout);}

    

    r.addq(1,2); r.upd(); out(r.rmq(0));

	return 0;
}
