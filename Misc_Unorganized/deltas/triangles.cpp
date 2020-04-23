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
#define sz(x) (x).size()
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
bool compy(const pii&p1, const pii&p2){return (p1.s<p2.s);}
#define PNAME "triangles" //each triangle uniquely determined by bottom left point (x,y) with (x,a), (b,y) combo
//let's say we want to sum all areas for a certain bottom-left point
struct lf{bool operator()(const int&a, const pii&b){return(a<b.f);} bool operator()(const pii&a, const int&b){return(a.f<b);}};
struct ls{bool operator()(const int&a, const pii&b){return(a<b.s);} bool operator()(const pii&a, const int&b){return(a.s<b);}};
int n,ans; vector<pii> pts,ptsx,ptsy,prefx,prefy; //we should keep prefix sums of x and y in that order
int main(){
	cin.tie(0)->sync_with_stdio(0); if(fopen(PNAME ".in","r")){freopen(PNAME ".in","r",stdin); freopen(PNAME ".out","w",stdout);}
	in(n); F0R(i,n){int x,y; in(x,y); pts.pb(mp(x,y));} pts=ptsx=ptsy; sort(all(ptsx)); sort(all(ptsy),compy);
	prefx=ptsx; prefy=ptsy;
	F0R(i,sz(prefx)-1) prefx[i+1].s+=prefx[i].s; //prefx is prefix sums for y
	F0R(i,sz(prefy)-1) prefy[i+1].f+=prefy[i].f; //prefy is prefix sums for x
	F0R(i,n){ //number of elements from A to B is B-A+1 or B+1-A
		//binary search for same x coords and same y coords
		int x=pts[i].f,y=pts[i].s;
		int xlb=lb(all(ptsx),x,lf())-begin(ptsx), xub=ub(all(ptsx),x,lf())-begin(ptsx); //from =xlb to <xub
		int ylb=lb(all(ptsy),y,ls())-begin(ptsy), yub=ub(all(ptsy),y,ls())-begin(ptsy); //from =ylb to <yub
		//(binary search in a binary search for x and y) (diffxfromybs-x)(diffyfromxbs-y)
	   //use prefix sums -- gives sum of all y from a to b for a certain x
		//(sum of all delta x)*(sum of all delta y)
		ans+=abs(x*(yub-ylb)-(prefy[yub].f-prefy[ylb].f))*abs(y*(xub-xlb)-(prefx[xub].s-prefx[xlb].s))/2;
	}
	out(ans);
	return 0;
}
