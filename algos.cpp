/*
 * Aryansh Shrivastava 
 * USACO Algorithm Template (Reference & Structs)
 * Last Updated: 5/26/20 (mild cleanup)
 * ignore "ignore_this_macro_stuff" 
 */

#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std; using namespace __gnu_pbds;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - 

namespace ignore_this_macro_stuff {
	typedef long long ll;
	typedef pair<int,int> pii;
	typedef pair<ll,ll> pll;
	typedef vector<int> vi;
	template<class T> using minpq = priority_queue<T, vector<T>, greater<T> >;
	template<class T> using maxpq = priority_queue<T>;
	template <class T> using OST = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
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
}

using namespace ignore_this_macro_stuff;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - 

struct radix{const int bit;radix(int off):bit(off){}bool operator()(int val)const{return (bit==31)?(val<0):(!(val&(1<<bit)));}}; //concise linear radix sort
void rsort(int*l,int*r,int msb=31){
    if(l!=r&&msb>=0){int*m=partition(l,r,radix(msb)); msb--;rsort(l,m,msb),rsort(m,r,msb);}
}void rsort(vi::iterator l, vi::iterator r, int msb=31){
    if(l!=r&&msb>=0){vi::iterator m=partition(l,r,radix(msb)); msb--;rsort(l,m,msb),rsort(m,r,msb);}
}

struct DSU{ //from 0 to n-1
	vi e; void init(int n) { e = vi(n,-1); }
    bool cycfind; 
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
  DSU(int SZ=0){init(SZ);}
	bool unite(int x, int y) { // union-by-rank
		x = get(x), y = get(y);
    if(x==y){
        cycfind=1; return 0;
    }
		if (e[x] > e[y]) swap(x,y);
		e[x] += e[y]; e[y] = x; return 1;
	}
    void setpar(int a, int b){e[b]=-1; if(e[a]<0) e[a]=b; else e[e[a]]=b;} //make b parent of a
	int compnum(){ //return the number of components
		int ret=1;
		F0R(i,sz(e)-1) if(get(i)!=get(i+1)) ret++;
		return ret;
	}
	bool cyc(){return cycfind;}
};

struct DSURB{ //from 0 to n-1 -> make sure to set rollback if needed
	vi e; void init(int n) { e = vi(n,-1); }
    bool rollback,cycfind; vector<pair<pii,pii> > mod;
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
    DSU(int SZ=0){init(SZ);}
	bool unite(int x, int y) { // union-by-rank
		x = get(x), y = get(y);
        if(x==y){
            if(rollback) mod.pb(mp(mp(bigg,bigg),mp(bigg,bigg)));
            cycfind=1; return 0;
        }
		if (e[x] > e[y]) swap(x,y);
        if(rollback) mod.pb(mp(mp(x,y),mp(e[x],e[y])));
		e[x] += e[y]; e[y] = x; return 1;
	}
    void setpar(int a, int b){e[b]=-1; if(e[a]<0) e[a]=b; else e[e[a]]=b;} //make b parent of a
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
	bool cyc(){return cycfind;}
};

namespace SHORTEST_PATH {
	template <class T, int SZ> struct Dijk{ //class T is the type of weight being used, works in O(E log V)
		vector<pair<T,int> > adj[SZ]; T dist[SZ]; bool vis[SZ];
	    int mom[SZ];
		void add(int a, int b, T w){adj[a].pb(mp(w,b)); adj[b].pb(mp(w,a));}
		void add_(int a, int b, T w){adj[a].pb(mp(w,b));} //if edge is directed
		void upd(int start){
			F0R(i,SZ) dist[i]=(i!=start)?INF:0, vis[i]=0, mom[i]=i;
			minpq<pair<T,int> > q;
			q.push(mp(0,start));
			while(!q.empty()){
				auto curr=q.top(); q.pop(); vis[curr.s]=1;
				trav(v,adj[curr.s]){
					if(vis[v.s]) continue;
					if(dist[v.s]>dist[curr.s]+v.f){
					   dist[v.s]=dist[curr.s]+v.f;
			   mom[v.s]=curr.s;
					   q.push(mp(dist[v.s],v.s));
					}
				}
			}
		}
		T query(int v){return dist[v];}
		T query_(int st, int v){upd(st); return query(v);}
	    vector<pii> path(int st, int v){
		vector<pii> ret; int i=v;
		while(mom[i]!=i){ret.pb(mp(mom[i],i)),i=mom[i];}
		reverse(all(ret)); return ret;
	    }
	    vector<pii> path_(int st, int v){
		upd(st); return path(st,v);
	    }
	};

	template <class T, int SZ> struct Floyd{
		T dist[SZ][SZ];
		Floyd(){F0R(i,SZ) F0R(j,SZ) dist[i][j]=INF;}
		void add(int a, int b, T w){dist[a][b]=dist[b][a]=w;}
		void add_(int a, int b, T w){dist[a][b]=w;}
		void upd(){
			F0R(k,SZ) F0R(i,SZ) F0R(j,SZ) ckmin(dist[i][j],dist[i][k]+dist[k][j]);
		}
		T query(int a, int b){return dist[a][b];}
		bool negcyc(){F0R(i,SZ) if(dist[i][i]<0) return 1; return 0;}
	};

	template <class T, int SZ> struct SPFA{ //average O(E), wc bell-ford, check for negcyc
	    vector<pair<T,int> > adj[SZ]; int mom[SZ],r[SZ]; T dist[SZ]; bool negcycbad;
	    bool inq[SZ];
	    void add(int a, int b, T w){
		adj[a].pb(mp(w,b)); adj[b].pb(mp(w,a));
	    }
	    void add_(int a, int b, T w){adj[a].pb(mp(w,b));}
	    void upd(int start=0){
		F0R(i,SZ) dist[i]=(i!=start)?INF:0, mom[i]=i, inq[i]=0;
		deque<int> q; q.pb(start); inq[start]=1;
		while(!q.empty()){
		    int curr=q.front(); q.pop_front(); inq[curr]=0;
		    trav(v,adj[curr]){
			if(dist[v.s]>dist[curr]+v.f){
			    dist[v.s]=dist[curr]+v.f; mom[v.s]=curr; r[v.s]++;
			    if(r[v.s]==SZ){negcycbad=1; break;} //can't relax so much
			    if(!inq[v.s]){
				if(q.empty()) q.pb(v.s);
				if(dist[q.front()]>dist[v.s]) q.push_front(v.s);
				else q.pb(v.s);
			    }
			}
		    }
		}
	    }
	    T query(int v){return dist[v];}
	    T query_(int st, int v){upd(st); return query(v);}
	    vector<pii> path(int v){
		vector<pii> ret; int i=v; 
		while(mom[i]!=i){ret.pb(mp(mom[i],i)); i=mom[i];}
		reverse(all(ret)); return ret;
	    }
	    vector<pii> path_(int st, int v){upd(st); return path(v);}
	    bool negcyc(){return negcycbad;}
	};
}
using namespace SHORTEST_PATH;

namespace MST {
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

	template<class T, int SZ> struct Krus{ //also get DSU
	    DSU d; T weight; Krus(){d.init(SZ);}
	    vector<pair<T,pii> > edge,MST;
	    void add(int a, int b, T w){
		edge.pb(mp(w,mp(a,b)));
		edge.pb(mp(w,mp(b,a)));
	    }
	    void add_(int a, int b, T w){
		edge.pb(mp(w,mp(a,b)));
	    }
	    void upd(){
		sort(begin(edge),end(edge));
		F0R(i,edge.size()){
		    int urep=d.get(edge[i].s.f),
		    vrep=d.get(edge[i].s.s);
		    if(urep!=vrep){
			MST.pb(edge[i]); d.unite(edge[i].s.f,edge[i].s.s); weight+=edge[i].f;
		    }
		}
	    }
	    T sum(){return weight;}
	    vector<pair<T,pii> > getMST(){return MST;}
	};
}
using namespace MST;

template <int SZ> struct BLCA{ //lca with binary lifting -- O(log n) query with O(n) preprocess
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
    void addq(int x, int y){ //push in queries before next linear upd
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
    int lca(int qry){return queries[qry].lca;} //find LCA query by query number
};

template<int SZ> struct TopSort{ //works for DAG
    //pls 0 index
    //topological sort and detect cycles
    vi adj[SZ], res; int sto[SZ], n=SZ,mx;
    //void add(int a, int b){adj[a].pb(b); adj[b].pb(a);}
    void add_(int a, int b){adj[a].pb(b); sto[b]++;}
    void sort(int _n=SZ){ //sort from 0..n-1 (#el)
        n=_n; queue<int> q;
        F0R(i,n) if(!sto[i]) q.push(i);
        while(!q.empty()){
            int v=q.front(); q.pop(); res.pb(v);
            trav(i,adj[v]) if(!--sto[i]) q.push(i);
        }
    }
    vi get(){return res;}
    bool cyc(){return (sz(res)!=n);} //sort first
};

template <int SZ> struct Euler{ //tree euler tour
    vi adj[SZ]; bool vis[SZ]; vi tour; //2SZ-1
    Euler(){tour.rsz(2*SZ-1);}
    void add(int a, int b){adj[a].pb(b); adj[b].pb(a);}
    void add_(int a, int b){adj[a].pb(b);}
    void dfs(int curr, int &idx){
        vis[curr]=1,tour[idx++]=curr;
        trav(v,adj[curr]) if(!vis[v]) dfs(v,idx),tour[idx++]=curr;
    }
    void upd(int rt){
        F0R(i,SZ) vis[i]=0;
        int idx=0; dfs(rt,idx);
    }
    vi query(){return tour;}
    vector<pii> edges(){
        vector<pii> ret; 
        F0R(i,2*SZ-2) ret.pb(mp(tour[i],tour[i+1]));
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

namespace SegmentTree {
    template<class T> class opadd {public: const T ID = 0; T comb(T a, T b){return a + b;}};
    template<class T> class opmult {public: const T ID = 1; T comb(T a, T b){return a * b;}};
    template<class T> class opxor {public: const T ID = 0; T comb(T a, T b){return a ^ b;}};
    template<class T> class opmin {public: const T ID = -INF; T comb(T a, T b){return min(a, b);}};
    template<class T> class opmax {public: const T ID = INF; T comb(T a, T b){return max(a, b);}};
    template<class T> void upd_(T&a, T&b, string tp = "id"){
        if(tp == "id") a = b; 
        if(tp == "add") a += b;
    }

    template<class T = int, class U = opadd<T>> struct SegTree {
        int n; vector<T> seg; U oper; string tp = "id"; 
        void init(int _n) { n = _n; seg.assign(2*n,oper.ID); }
        void initv(int _n, int val = 0){ n = _n; seg.assign(2*n, val); }
        void pull(int p) { seg[p] = oper.comb(seg[2*p],seg[2*p+1]); }
        void upd(int p, T val) { // set val at position p
            upd_<T>(seg[p += n],val,tp); for (p /= 2; p; p /= 2) pull(p);
        }
        void change_upd(string s){tp = s;}
        T query(int l, int r) {	// sum on interval [l, r]
            T ra = oper.ID, rb = oper.ID; 
            for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
                if (l&1) ra = oper.comb(ra,seg[l++]);
                if (r&1) rb = oper.comb(seg[--r],rb);
            }
            return oper.comb(ra,rb);
        }
    };

    template<typename U = int, template<typename> class T = opadd> using SEG = SegTree<U, T<U>>;
    // i.e. SEG<int, opadd> a; 
}
using namespace SegmentTree;

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
template <const int maxN> struct OSTSlow{ //slower OST with Fenwick
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

int main() {
	//code
}