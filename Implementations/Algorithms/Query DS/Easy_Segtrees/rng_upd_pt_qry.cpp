//range update, point query
//read iterative segtree impl for more info -- switch around qry and upd a bit, change build (removed pull)

#define INF 0x3f3f3f3f

template<class T> struct SEGRP { //range update, point query
	//comb must work independent of order, otherwise use lazy
	const T ID = 1; T comb(T a, T b) { return a * b; } 
	int n; vector<T> seg;
	void init(int _n) { n = _n; seg.assign(2*n, ID); } 
    	template<typename it, typename = typename enable_if<is_pointer<it>::value>::type> 
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
	void upd(int l, int r, T val) {	// upd by comb on interval [l, r]
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
            		if (l&1) seg[l] = comb(seg[l],val), ++l;
            		if (r&1) seg[r-1] = comb(seg[r-1],val), --r;
        	} 
	}
};
