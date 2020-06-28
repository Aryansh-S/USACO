//Merge Sort Tree for Subarray Existence Queries
  //Can even be used with HLD for existence queries of a node/edge in a path

template<class T0> struct SEG { //merge sort tree
    using T = vector<T0>; //each node is a vector
    
    //#define DYNAMIC	
    const T ID = {}; T comb(T a, T b) { T ret; merge(all(a),all(b),back_inserter(ret)); return ret; }
    
    int n; 
    
    #ifndef DYNAMIC
        vector<T> seg;
    #else
        hmap<ll, T> seg; 
    #endif

    T get(int p) {
        #ifndef DYNAMIC
            return seg[p]; 
        #else
            return seg.find(p) == end(seg) ? ID : seg[p];
        #endif
    }

    void init(int n0) { 
        n = n0; 
        #ifndef DYNAMIC
            seg.assign(2 * n, ID); 
        #endif
    }

    #ifndef DYNAMIC    
	    template<typename it, typename = typename enable_if<is_iterator<it>::value>::type> 
	    void init(it bg, it nd) { init(distance(bg, nd)); move(bg, nd, begin(seg) + n); build(); }
    #endif

    void build() { int i = n - 1; do pull(i); while(--i); }

    inline int lc(int p) { return 2 * p; }
    inline int rc(int p) { return lc(p) + 1; }
    
    void pull(int p) { seg[p] = comb(get(lc(p)), get(rc(p))); }
    
    void upd(int p, T0 v) { //point update the value at index p to v
      seg[p += n] = (T){v};  
      for(p /= 2; p; p /= 2) pull(p);
    }
    bool qry(int l, int r, T0 x) { //query for the existence of x in [l,r]
      bool ret = 0; 
      for(l += n, r += n + 1; l < r; l /= 2, r /= 2) {
          if(l & 1) {
            auto L = get(l++); 
            ret = ret || binary_search(all(L),x); 
          }
          if(r & 1) {
            auto R = get(--r); 
            ret = ret || binary_search(all(R),x);
          }
      }
      return ret;
    }
};
