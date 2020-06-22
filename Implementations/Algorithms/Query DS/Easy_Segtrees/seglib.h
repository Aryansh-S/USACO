//Iterative Segment Tree Library

template<class T> struct SEG {
    const T ID = 0; T comb(T a, T b) { return a + b; } 

    int n; vector<T> seg; 

    void init(int n0) { n = n0; seg.assign(2 * n, ID); }    
    template<typename it, typename = typename enable_if<is_iterator<it>::value>::type> 
    void init(it bg, it nd) { init(distance(bg, nd)); move(bg, nd, begin(seg) + n); build(); }

    void build() { int i = n - 1; do pull(i); while(--i); }

    inline int lc(int p) { return 2 * p; }
    inline int rc(int p) { return lc(p) + 1; }
    void pull(int p) { seg[p] = comb(seg[lc(p)], seg[rc(p)]); }

    void upd(int p, T v) {
        seg[p += n] = v; 
        for(p /= 2; p; p /= 2) pull(p);
    }
    T qry(int l, int r) {
        T ra = ID, rb = ID; 
        for(l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if(l & 1) ra = comb(ra, seg[l++]); 
            if(r & 1) rb = comb(seg[--r], rb);
        }
        return comb(ra, rb); 
    }
};


  //Reverse Iterative Generic Segment Tree: Range Update, Point Query (0 - Indexing Allowed), Exactly 2N Memory (Not 4N)
  //Suggested to use N as power of 2 if doing binary search, order statistics, etc. (perfect binary tree)

  template<class T> struct RSEG { //reverse segtree: range update, point query
    //comb must work independent of order, otherwise use lazy

    const T ID = 1; T comb(T a, T b) { return a * b; } 

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
    
