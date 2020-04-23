#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) begin(x),end(x)
#define gint greater<int> //use with sort(all(), gint()) or set<int,gint> for backwards sort
#define trav(a,x) for(auto&(a):(x))
#define FOR(i,a,b) for(__typeof(b)i=(a)-((a)>(b));i!=(b)-((a)>(b));i+=((a)>(b))?-1:1) //go from i=lb to i=ub-1
#define FOR_(i,a,b,d) for(__typeof(b)i=(a)-((a)>(b));(a>b)?(i>b-1):(i<b);i+=(((a)>(b))?-1:1)*abs(d)) //go from i=lb to i=ub-1 by size d increments
#define F0R(i,b) FOR(i,0,b)
#define F0R_(i,b,d) FOR_(i,0,b,d)
#define what(x) out((#x),"is",(x))
#define big (int)1e5
#define bigg (int)(1e9+7)

void in(){} void out(){cout << "\n";} void outln(){} void out_(){cout << "\n";}
template<typename T, typename...Types> void in(T& var1, Types&...var2){cin >> var1; in(var2...);}
template<typename T, typename...Types> void out(T var1, Types...var2){cout << var1 << " "; out(var2...);}
template<typename T, typename...Types> void outln(T var1, Types...var2){cout << var1 << "\n"; outln(var2...);}
template<typename T> void out_(T var1){cout << var1 << " ";}

#define PNAME "socdist1"
vi occ,ans; int n;
int main(){
	cin.tie(0)->sync_with_stdio(0); if(fopen(PNAME ".in","r")){freopen(PNAME ".in","r",stdin); freopen(PNAME ".out","w",stdout);}
	in(n); F0R(i,n){bool x; in(x); if(x) occ.pb(i);} // ans.pb(min(abs(i-*lb(all(occ),i)),abs(i-*(lb(all(occ),i))-1)));
	F0R(i,n){
		int k1=abs(i-*lb(all(occ),i)),k2=abs(i-*(lb(all(occ),i))-1);
		if(k1) ans.pb(min(k1,k2));
	}
	sort(all(ans),gint()); out(ans[1]);
	return 0;
}
