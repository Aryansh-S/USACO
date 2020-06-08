/*
 * Aryansh Shrivastava 
 * USACO Algorithm Template (Reference & Structs)
 * Last Updated: 6/4/20 (mild cleanup)
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
            if(rollback) mod.pb(mp(mp(MOD,MOD),mp(MOD,MOD)));
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
		if (a.f.f!= MOD) e[a.f.f]=a.s.f, e[a.f.s]= a.s.s;
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

//Iterative Generic Segment Tree: Point Update, Range Query (0 - Indexing Allowed), Exactly 2N Memory (Not 4N)

template<class T> struct SEG { // comb(ID,b) = b, 0-indexing works, any associative operation. 
	//seg[1] = qry(0,n-1)
	const T ID = -INF; T comb(T a, T b) { return max(a,b); } 
	int n; vector<T> seg;
	void init(int _n) { n = _n; seg.assign(2*n, ID); } 
    	void init(vector<T>& v) { init(v.size()); move(begin(v), end(v), begin(seg) + n); build(); }
    	void init(T* a, int _n) { init(_n); move(a, a + n, begin(seg) + n); build(); }
    	void build() { for(int i = n - 1; i > 0; --i) pull(i); }
	void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
	void upd(int p, T val) { // set val at position p
		seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); 
    	}
	T qry(int l, int r) {	// comb on interval [l, r]
		T ra = ID, rb = ID; 
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = comb(ra,seg[l++]);
			if (r&1) rb = comb(seg[--r],rb);
		}
		return comb(ra,rb);
	}
};

template<class T> struct SEGRP { //range update, point query
	//comb must work independent of order, otherwise use lazy
	const T ID = 1; T comb(T a, T b) { return a * b; } 
	int n; vector<T> seg;
	void init(int _n) { n = _n; seg.assign(2*n, ID); } 
    	void init(vector<T>& v) { init(v.size()); move(begin(v), end(v), begin(seg) + n); build(); }
    	void init(T* a, int _n) { init(_n); move(a, a + n, begin(seg) + n); build(); }
    	void build() { 
        	for (int i = 1; i < n; ++i) 
            		seg[2*i] = comb(seg[2*i],seg[i]), seg[2*i + 1] = comb(seg[2*i + 1],seg[i]), seg[i] = ID;
    	}
	T qry(int p) { // qry val at position p
        	T res = ID; 
		for (p += n; p; p /= 2) res = comb(res,seg[p]); 
        	return res;
    	}
	void upd(int l, int r, T val) {	// upd by comb on interval [l, r]
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
            		if (l&1) seg[l] = comb(seg[l],val), ++l;
            		if (r&1) seg[r-1] = comb(seg[r-1],val), --r;
        	} 
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

int main() {
	//code
}
