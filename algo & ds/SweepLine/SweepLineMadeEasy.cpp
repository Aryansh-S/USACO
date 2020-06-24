#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii; 
#define f first
#define s second
#define mp make_pair
#define ins insert
#define ers erase
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define sq(x) (x)*(x)
#define dist(a,b) sq((a).f-(b).f)+sq((a).s-(b).s)
#define ckmin(a,b) a=min(a,b)
inline void io(){cin.tie(0)->sync_with_stdio(0); cout.precision(2); cout.setf(ios::fixed,ios::floatfield);}
inline void ans(int a){cout << sqrt((double)a) << "\n";}
struct cmps{bool operator()(pii a, pii b){return (a.s==b.s)?(a.f<b.f):(a.s<b.s);}};

vector<pii> pts; 
inline void getpts(int n){while(n--){int x,y; cin >> x >> y; pts.pb(mp(x,y));}}

int n,d=INT_MAX; set<pii,cmps> act;

int main(){
    io();
    cin >> n; getpts(n); sort(begin(pts),end(pts));

    int l=0; //left ptr 
    for(int i=0;i<n;i++){ 
        pii curr=pts[i]; int x=curr.f,y=curr.s;
        while(x-pts[l].f>=d) act.ers(pts[l]),l++;
        auto L=act.lb(mp(x,y-ceil(sqrt(d)))),R=act.ub(mp(x,y+ceil(sqrt(d)))),it=L;
        while(it!=R) ckmin(d,dist(*it,curr)),++it;
        act.ins(curr);
    }

    ans(d);
    return 0;
}
