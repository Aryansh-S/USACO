#include <bits/stdc++.h>
using namespace std;
//level: gold
//objective: create a single-source shortest path algo that can handle negative edges and detect negative cycles
//worst case runtime is Bellman-Ford O(EV), but average is estimated to be O(E) experimentally
//this is not the traditional implementation of SPFA in research discipline; we maintain a double-ended queue (deque) to 
//speed up the process

typedef vector<int> vi; 
typedef pair<int,int> pii; 
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define FOR(i,a,b) for(__typeof(b)i=(a)-((a)>(b));i!=(b)-((a)>(b));i+=((a)>(b))?-1:1) //go from i=lb to i=ub-1
#define F0R(i,b) FOR(i,0,b)
#define trav(a,x) for(auto&(a):(x))
#define INF 0x3f3f3f3f
#define all(v) begin(v),end(v)

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
        reverse(all(ret)); return
    }
    vector<pii> path_(int st, int v){upd(st); return path(v);}
    bool negcyc(){return negcycbad;}
};

SPFA<int,5> s;

int main(){
    s.add_(0,1,-1);
    s.add_(1,2,-2);
    s.add_(0,2,0);
    s.upd(0);
    auto a=s.path(2);
    trav(t,a) cout << t.f << " " << t.s << "\n";
    return 0;
}
