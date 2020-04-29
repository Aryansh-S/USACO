#include <bits/stdc++.h>
using namespace std;
//level: mid gold

//objective: use Prim/Jarnik's algorithm to generate an MST

typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define INF 0x3f3f3f3f
#define FOR(i,a,b) for(__typeof(b)i=(a)-((a)>(b));i!=(b)-((a)>(b));i+=((a)>(b))?-1:1) //go from i=lb to i=ub-1
#define F0R(i,b) FOR(i,0,b)

template <class T> using minpq = priority_queue<T,vector<T>,greater<T> >;

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
};

Prim<double,10> g;

int main(){
    g.add(0,1,3);
    g.add(0,2,2);
    g.add(1,2,1);
    g.add(1,3,4);
    g.add(2,4,1);
    g.add(3,4,2);
    g.upd();
    
    auto a=g.dirMST();
    F0R(i,10){ if(a[i].size()!=0) cout << i << " has children \n"; 
    for(auto x:a[i]){  cout << x << " ";
    }if(a[i].size()!=0) cout << "\n\n";}

    return 0;
}
