#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi; 
#define pb push_back
#define sz(x) (x).size()
#define trav(a,x) for(auto&(a):(x))
#define FOR(i,a,b) for(__typeof(b)i=(a)-((a)>(b));i!=(b)-((a)>(b));i+=((a)>(b))?-1:1) //go from i=lb to i=ub-1
#define F0R(i,b) FOR(i,0,b)
#define ckmax(a,b) a=max(a,b)

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

TopSort<1000000> t; //testing for memory efficiency 

int main(){
    t.add_(0,1);
    t.add_(1,2);
    t.add_(2,3);
    t.sort(4);
    if(!t.cyc()) trav(i,t.get()) cout << i << "\n";
    else cout<<-1; 
    return 0;
}
