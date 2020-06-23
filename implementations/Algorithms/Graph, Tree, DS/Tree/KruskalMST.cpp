#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii; 
typedef vector<int> vi; 
#define f first
#define s second
#define FOR(i,a,b) for(__typeof(b)i=(a)-((a)>(b));i!=(b)-((a)>(b));i+=((a)>(b))?-1:1) //go from i=lb to i=ub-1
#define F0R(i,b) FOR(i,0,b)
#define pb push_back
#define sz(x) (x).size()
#define ins insert
#define mp make_pair

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

Krus<int,100> k;

int main(){
    k.add(1,2,1);
    k.add(2,3,2);
    k.add(3,4,5);
    k.add(1,3,4);
    k.upd();
    cout << k.sum() << "\n";
    return 0;
}
