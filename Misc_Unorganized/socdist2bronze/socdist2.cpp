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
#define F0R(i,b) FOR(i,0,b)
#define what(x) out((#x),"is",(x))
#define big (int)1e5
#define bigg (int)(1e9+7)

void in(){} void out(){cout << "\n";} void outln(){}
template<typename T, typename...Types> void in(T& var1, Types&...var2){cin >> var1; in(var2...);}
template<typename T, typename...Types> void out(T var1, Types...var2){cout << var1 << " "; out(var2...);}
template<typename T, typename...Types> void outln(T var1, Types...var2){cout << var1 << "\n"; outln(var2...);}

#define PNAME "socdist2"
#define maxn 1000
int n,r=bigg,ans; pair<int,bool> cows[maxn];

int main(){
	cin.tie(0)->sync_with_stdio(0); if(fopen(PNAME ".in","r")){freopen(PNAME ".in","r",stdin); freopen(PNAME ".out","w",stdout);}
	in(n); F0R(i,n) in(cows[i].f,cows[i].s);
	//determine max what r can't be
	F0R(i,n) if(cows[i].s) F0R(j,n) if(!cows[j].s) r=min(r,abs(cows[i].f-cows[j].f));
	r--;
	F0R(i,n) if(cows[i].s) F0R(j,n) if(i!=j&&abs(cows[i].f-cows[j].f)<=r) {cows[j].s=0;}
	F0R(i,n) if(cows[i].s) ans++;
	out(ans);
	return 0;
}





