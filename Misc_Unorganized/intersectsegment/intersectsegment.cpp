#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
using namespace std;

#define pb push_back
typedef long long ll;

double x; //sweeper x coord

struct pt{ll x,y; int idx;}; pt mpt(ll x, ll y, int idx){pt r; r.x=x; r.y=y; r.idx=idx; return r;}
bool operator<(const pt&p1, const pt&p2){return (p1.x==p2.x)?(p1.y<p2.y):(p1.x<p2.x);}
struct seg{pt s,e; int idx;}; seg mseg(pt s, pt e, int idx){seg r; r.s=s; r.e=e; r.idx=idx; return r;}
double eval(seg s) {
  if (s.s.x == s.e.x) return s.s.y;
  return s.s.y + (s.e.y-s.s.y) * (x-s.s.x) / (s.e.x-s.s.x);
}
bool operator<(const seg&s1, const seg&s2){return s1.idx!=s2.idx&&eval(s1)<eval(s2);}
bool operator==(const seg&s1, const seg&s2){return s1.idx==s2.idx;}

//intersection testing
int sign(ll x){return (x==0)?0:((x<0)?-1:1);}
int operator*(pt p1, pt p2){return sign(p1.x * p2.y - p1.y * p2.x);}
pt operator-(pt p1, pt p2){return mpt(p1.x-p2.x,p1.y-p2.y,0);}
bool isect(seg&s1, seg&s2){
  pt&p1 = s1.s, &q1 = s1.e, &p2 = s2.s, &q2 = s2.e;
  return ((q2-p1)*(q1-p1)) * ((q1-p1)*(p2-p1)) >= 0 && ((q1-p2)*(q2-p2)) * ((q2-p2)*(p1-p2)) >= 0;
}

//vars (along with x from before)
int n; //n segments
vector<seg> segs; vector<pt> pts; set<seg> active; //segs, pts, active BST
vector<pair<int,int>> ans; //answers, pairs of two segments that intersect

int main(){
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for(int i=0; i<n; i++){int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2; segs.pb(mseg(mpt(x1,y1,i),mpt(x2,y2,i),i)); pts.pb(mpt(x1,y1,i)); pts.pb(mpt(x2,y2,i));}
	sort(pts.begin(),pts.end());

	for(int i=0; i<2*n; i++){

	}

	return 0;
}
