#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

template<class T> class is_iterator { //check if iterator or pointer (taken from my template for the sake of simplicity)
  static T makeT();
  typedef void * twoptrs[2];  
  static twoptrs & test(...); 
  template<class R> static typename R::iterator_category * test(R); // Iterator
  template<class R> static void * test(R *); // Pointer
  public: static const bool value = sizeof(test(makeT())) == sizeof(void *); 
};

template<class T> struct SEG { // comb(ID,b) = b, 0-indexing works, any associative operation. 
  //seg[1] = qry(0,n-1) 
  
  const T ID = INF; T comb(T a, T b) { return min(a,b); } 
  
  int n; vector<T> seg;
  void init(int _n) { n = _n; seg.assign(2*n, ID); } 
  template<typename it, typename = typename enable_if<is_iterator<it>::value>::type> 
  void init(it bg, it nd) {init(distance(bg,nd)); move(bg, nd, begin(seg) + n); build();}
  void build() { for(int i = n - 1; i > 0; --i) pull(i); }
  void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
  void upd(int p, T val) { // set val at position p
    seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); 
  }
  T qry(int l, int r) {	// comb on interval [l, r]
    T ra = ID, rb = ID; 
    for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
      if (l&1) ra = comb(ra,seg[l++]);
      if (r&1) rb = comb(seg[--r],rb);
    }
    return comb(ra,rb);
  }
}; //this is our data structure D, a range min query segment tree

int n, b; vector<int> v; SEG<int> D; 

int qry(int curr, int b) { //our binary search query function
  if(curr >= n) return curr < 2 * n && D.seg[curr] <= b ? curr-n : -1;
  int lc = 2 * curr, rc = lc + 1; 
  if(lc >= n && lc < 2 * n) if(D.seg[lc] <= b) return qry(lc,b);
  return qry(rc,b);
}

int nxtpw2(int v) {
  if((bool)v & !(v & (v - 1))) return v; //v is already a power of 2
  int x = 1; while(x < v) x<<=1; return x; //otherwise, round up in O(log v)
}

int main() {
  cin.tie(0)->sync_with_stdio(0); 
  
  cin >> n >> b; 
  v.assign(nxtpw2(n),INF); //pad to ensure we obtain a perfect binary tree
  for(int i = 0; i < n; ++i) cin >> v[i]; 
  D.init(begin(v),end(v));
  
  cout << qry(1,b) << "\n";
}
