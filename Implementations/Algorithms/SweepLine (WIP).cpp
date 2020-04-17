#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi; 
typedef pair<int,int> pii; 
#define FOR(i,a,b) for(__typeof(b)i=(a)-((a)>(b));i!=(b)-((a)>(b));i+=((a)>(b))?-1:1) //go from i=lb to i=ub-1
#define F0R(i,b) FOR(i,0,b)
#define pb push_back
#define mp make_pair
#define all(x) begin(x),end(x)
#define trav(a,x) for(auto&(a):(x))
#define f first
#define s second
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define bigg (int)(1e9+7)

struct comps{
  bool operator()(const pii&p1, const pii&p2){return (p1.s!=p2.s)?(p1.s<p2.s):(p1.f<p2.f);}
};

/*
objective: design a line sweep (plane sweep) algorithm to find the closest pair of Cartesian points in a discrete locus 
defined by way of input in O(n log n) or less -- defeats obvious O(n^2) brute force

background: line sweep is infamous as one of the hardest to implement algorithms at the intermediate level, but here, I will
attempt to show you that this algorithm is actually quite simple 
*/

int n; vector<pii> pts; 
pair<pii,pii> curr_closest; //maintain the closest pair of points found so far
int curr_dist=bigg; //maintain the distance d between the above pair of points
set<pii, comps> active; //maintain an active set distance d left of the current point as we sweep (sort by y)

int main(){
  cin.tie(0)->sync_with_stdio(0); 
  cin >> n; F0R(i,n){int x,y; cin >> x >> y; pts.pb(mp(x,y));} //store the points as pairs
  sort(all(pts)); //sort the points by x-coordinate
  
  int j=0; //used as the left pointer in the two pointer method described later
  F0R(i,n){
    pii curr = pts[i]; active.ins(curr); //add current point to active set
    while(curr.f-pts[j].f >= curr_dist){ //loop over all unsatisfactory points
      active.erase(pts[j]); //erase the unsatisfactory point
      j++; //move the left pointer forward
    }
    auto ylow = lb(all(s),mp(curr.f,curr.s-dist)); 
    auto yhi = ub(all(s),mp(curr.f,curr.s+dist));
    set<pts> //design set still
    for(auto it=ylow; it!=yhi; it++){ //bounded by a maximum constant (avoids increase in runtime degree)
      int dx=curr.f-*it.f;
      int dy=curr.s-*it.s;
      if(sqrt(dx*dx+dy*dy)<=);
    }
  }
  
  cout << curr_closest.f.f << curr_closest.f.s << "\n";
  cout << curr_closest.s.f << curr_closest.s.s << "\n";
  return 0;
}
