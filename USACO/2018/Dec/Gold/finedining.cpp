#include <bits/stdc++.h>
using namespace std; 

using ll = long long; using pii = pair<int,int>; using vi = vector<int>;

#define mp make_pair
#define f first
#define s second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define ef emplace_front
#define emp emplace
#define ins insert
#define ers erase
#define lb lower_bound
#define ub upper_bound 
#define sz(x) (int)(x).size()
#define all(x) begin(x),end(x)

#define trav(a,...) for(auto&a:__VA_ARGS__)
#define FOR(i,a,b) for(auto i = (a); i < (b); ++i)
#define ROF(i,a,b) for(auto i = (b)-1; i >= (a); --i)
#define F0R(i,a) FOR(i,0,a)
#define R0F(i,a) ROF(i,0,a)

template<class T> bool ckmin(T& a, const T b) { return a > b ? a = b, 1 : 0; } 
template<class T> bool ckmax(T& a, const T b) { return a < b ? a = b, 1 : 0; } 

#define dbg(...) { cerr << "[Line " << __LINE__ << "] " << #__VA_ARGS__ << " is "; de(__VA_ARGS__); } 
#define m1(x) template<class T, class... U> void x(T&& a, U&&... b)
#define m2(x) (int[]){(x forward<U>(b), 0)...}

m1(de) { cerr << forward<T>(a); m2(cerr << " " <<); cerr << endl; }
m1(pr) { cout << forward<T>(a); m2(cout << " " <<); cout << "\n"; }
m1(re) { cin >> forward<T>(a); m2(cin >>); }

template<class T> void in(T a, T b) { assert(a != b); while(b - a) re(*a), ++a; }
template<class T> void out(T a, T b) { assert(a != b); while(b - a - 1) cout << *a << " ", ++a; pr(*--b); }

const int _ = 2e5 + 5, MOD = 1e9 + 7, INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;

int n,m,k;
template<class T> using minpq = priority_queue<T,vector<T>,greater<T>>; 

struct D {
  vector<pair<ll,int>> adj[_]; ll dist[_];
  void upd(int start) {
    F0R(i,_) dist[i]=(i!=start)?INF:0;
    minpq<pair<ll,int> > q;
    q.emp(0,start);
    while(!q.empty()){
      auto curr=q.top(); q.pop();
      if(curr.f != dist[curr.s]) continue;
      trav(v,adj[curr.s]){
        if(dist[v.s]>dist[curr.s]+v.f){
          dist[v.s]=dist[curr.s]+v.f;
          q.emp(dist[v.s],v.s);
        }
      }
    }
  }
} d1, d2; 
// d1 = normal dijk from n
// d2 = normal dijk except only directed edges to haybales from n (with d1.dist[h] - yh)

int main() { 
	cin.tie(0)->sync_with_stdio(0);
	if(fopen("dining.in","r")) freopen("dining.in","r",stdin), freopen("dining.out","w",stdout);
	re(n,m,k); 
	F0R(i,m) { 
		int a,b; ll t; 
		re(a,b,t),--a,--b; 
		d1.adj[a].eb(t,b), d1.adj[b].eb(t,a); 
		d2.adj[a].eb(t,b), d2.adj[b].eb(t,a);
	}
	d1.upd(n-1); 
	// use n to account for the fact that you can revisit n
	F0R(i,k) {
		int a,x; re(a,x),--a;
		d2.adj[n].eb(d1.dist[a]-x, a); // directed edge from n-1 to a of length d1.dist[a] - x
		//d2.adj[a].eb(d1.dist[a]-x, n-1);
	}
	d2.upd(n);
	F0R(i,n-1) pr(d2.dist[i] <= d1.dist[i]);
}

