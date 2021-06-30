// 2D range tree with fractional cascading 
// log n queries and n log n preprocess 
// removes extra log factor, ideal for HLD
// construct with vector of pnts (X, Y)

// Credit: 
// https://en.wikipedia.org/wiki/Fractional_cascading
// https://www.cs.princeton.edu/~chazelle/pubs/FilteringSearch.pdf
// http://blog.ezyang.com/2012/03/you-could-have-invented-fractional-cascading/
// https://github.com/kaba2/pastel/tree/eefb90e13d24b53ac3a73425b287ca0d9ec7b407/pastel/geometry/rangetree

// wavelet is preferable due to less memory use, but this demonstrates the power of fractional cascading to collapse a sequence of binary searches

template<class X> struct rngtree { //X is value type, Y is idx type (int)
  using Y = int; //idx type
  vector<X> xs; vector<array<vector<X>,2>> link; vector<pair<X,Y>>& pnts; vector<vector<pair<X,Y>>> tree; 
  rngtree(vector<pair<X,Y>>& pnts) : pnts(pnts), tree(4 * pnts.size()), link(4 * pnts.size()) { build(); }
  static bool cmpy(const pair<X,Y>& a, const pair<X,Y>& b) { return mp(a.s,a.f) < mp(b.s, b.f); }
  int init(int node, int left, int right) {
      if (right - left == 1) {
          auto it = lb(begin(pnts), end(pnts), mp(xs[left], -INF));
          for (; it != end(pnts) && it->f == xs[left]; ++it) tree[node].pb(*it);
          return tree[node].size();
      }
      int mid = left + (right - left) / 2, cl = 2 * node + 1, cr = cl + 1, 
      szl = init(cl, left, mid), 
      szr = init(cr, mid, right);
      tree[node].reserve(szl + szr); link[node][0].reserve(szl + szr + 1); link[node][1].reserve(szl + szr + 1);
      int l = 0, r = 0, llink = 0, rlink = 0;
      while (l < szl || r < szr) {
          pair<X,Y> last;
          if(r == szr || (l < szl && cmpy(tree[cl][l], tree[cr][r]))) tree[node].pb(last = tree[cl][l++]);
          else tree[node].push_back(last = tree[cr][r++]); 
          while(llink < szl && cmpy(tree[cl][llink], last)) llink++;
          while(rlink < szr && cmpy(tree[cr][rlink], last)) rlink++;
          link[node][0].pb(llink), link[node][1].pb(rlink);
      }
      link[node][0].pb(szl); link[node][1].pb(szr);
      return tree[node].size();
  }
  void build() {
      sort(begin(pnts),end(pnts));
      for(int i = 0; i < pnts.size(); ++i) xs.pb(pnts[i].f);
      xs.erase(unique(begin(xs),end(xs)),end(xs));
      init(0, 0, xs.size());
  }
  // query # with val in [valL, valR] and idx in [idxL, idxR]
  int qry(X valL, X valR, Y idxL, Y idxR) { return qry(0, 0, xs.size(), valL, valR, idxL, idxR); }
  int qry(int node, int l, int r, X a, X b, Y c, Y d, int posl = -1, int posr = -1) {
      if (node == 0) {
          posl = lb(begin(tree[0]), end(tree[0]), mp(a,c), cmpy) - begin(tree[0]),
          posr = ub(begin(tree[0]), end(tree[0]), mp(b,d), cmpy) - begin(tree[0]);
      }
      if (posl == posr) return 0;
      if (a <= xs[l] && xs[r-1] <= b) return posr - posl;
      if (b < xs[l] || a > xs[r-1]) return 0;
      int m = l + (r - l) / 2, ret = 0;
      if (a < xs[m]) ret += qry(2 * node + 1, l, m, a, b, c, d, link[node][0][posl], link[node][0][posr]);
      if (xs[m] <= b) ret += qry(2 * node + 2, m, r, a, b, c, d, link[node][1][posl], link[node][1][posr]);
      return ret;
  }
};
