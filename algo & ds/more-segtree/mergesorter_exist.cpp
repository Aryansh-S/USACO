//Merge Sort Tree for Subarray Existence Queries
  //Can even be used with HLD for existence queries of a node/edge in a tree path

template<class T0> struct SEG { //merge sort tree
    using T = vector<T0>; //each node is a vector
    
    //#define DYNAMIC	
    const T0 ID = 0; 
    const T IDv = {}; T combv(T a, T b) { T ret; merge(all(a),all(b),back_inserter(ret)); return ret; }
    T0 comb(T0 a, T0 b) { return a || b; }
	
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
            return seg.find(p) == end(seg) ? IDv : seg[p];
        #endif
    }

    void init(int n0) { 
        n = n0; 
        #ifndef DYNAMIC
            seg.assign(2 * n, IDv); 
        #endif
    }

    #ifndef DYNAMIC    
	    template<typename it, typename = typename enable_if<is_iterator<it>::value>::type> 
	    void init(it bg, it nd) { init(distance(bg, nd)); move(bg, nd, begin(seg) + n); build(); }
    #endif

    void build() { int i = n - 1; do pull(i); while(--i); }

    inline int lc(int p) { return 2 * p; }
    inline int rc(int p) { return lc(p) + 1; }
    
    void pull(int p) { seg[p] = combv(get(lc(p)), get(rc(p))); }
    
    void upd(int p, T0 v) { //point update the value at index p to v
      seg[p += n] = (T){v};  
      for(p /= 2; p; p /= 2) pull(p);
    }
    T0 qry(int l, int r, T0 x) { //query for the existence of x in [l,r]
      T0 ret = 0; 
      for(l += n, r += n + 1; l < r; l /= 2, r /= 2) {
          if(l & 1) {
            auto L = get(l++); 
            ret = comb(ret,binary_search(all(L),x)); 
          }
          if(r & 1) {
            auto R = get(--r); 
            ret = comb(ret,binary_search(all(R),x));
          }
      }
      return ret;
    }
};

/*
int main() {
	SEG<int> s; s.init(4); s.upd(0,10); s.upd(1,5);
	assert(s.qry(0,1,10)==1); assert(s.qry(0,1,5)==1); 
	assert(s.qry(0,1,15)==0); 
	s.upd(0,15); assert(s.qry(0,1,15)==1); 
}
*/
