#include <bits/stdc++.h>
using namespace std;

using ll = long long; 

template<class T> class is_iterator { //check if iterator or pointer (taken from my template)
  static T makeT();
  typedef void * twoptrs[2];  
  static twoptrs & test(...); 
  template<class R> static typename R::iterator_category * test(R); // Iterator
  template<class R> static void * test(R *); // Pointer
  public: static const bool value = sizeof(test(makeT())) == sizeof(void *); 
};

template<class T> struct RSEG { //reverse segtree: range update, point query
  //comb must work independent of order, otherwise use lazy
  
  const T ID = 0; T comb(T a, T b) { return a + b; } 
  
  int n; vector<T> seg;
  void init(int _n) { n = _n; seg.assign(2*n, ID); } 
  template<typename it, typename = typename enable_if<is_iterator<it>::value>::type> 
  void init(it bg, it nd) {init(distance(bg,nd)); move(bg, nd, begin(seg) + n); build();}
  void build() { 
    for (int i = 1; i < n; ++i) 
    seg[2*i] = comb(seg[2*i],seg[i]), seg[2*i + 1] = comb(seg[2*i + 1],seg[i]), seg[i] = ID;
  }
  T qry(int p) { // qry val at position p
    T res = ID; 
    for (p += n; p; p /= 2) res = comb(res,seg[p]); 
    return res;
  }
  void upd(int l, int r, T val) { //upd by comb on interval [l, r]
    for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
      if (l&1) seg[l] = comb(seg[l],val), ++l;
      if (r&1) seg[r-1] = comb(seg[r-1],val), --r;
    } 
  }
};

RSEG<ll> s; vector<int> v = {0}; 

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n,q; cin >> n >> q; while(n--) { int x; cin >> x; v.emplace_back(x); }
  s.init(begin(v),end(v)); 
  while(q--) {
    int t; cin >> t; 
    if(t == 1) { int a,b,u; cin >> a >> b >> u; s.upd(a,b,u); }
    else { int k; cin >> k; cout << s.qry(k) << "\n"; }
  }
}
