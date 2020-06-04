//read iterative segtree impl for more info

#define INF 0x3f3f3f3f

template<class T> struct SEG1 { //comb must work independent of order, otherwise use lazy
	const T ID = -INF; T comb(T a, T b) { return a + b; } 
	int n; vector<T> seg;
	void init(int _n) { n = _n; seg.assign(2*n, ID); } 
    void init(vector<T>& v) { init(v.size()); copy(begin(v), end(v), begin(seg) + n); build(); }
    void init(T* a, int _n) { init(_n); copy(a, a + n, begin(seg) + n); build(); }
    void build() { for(int i = n - 1; i > 0; --i) pull(i); }
	void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
	T qry(int p) { // qry val at position p
    T res = ID; 
		for (p /= 2; p; p /= 2) res = comb(res,comb(seg[2*p],seg[2*p+1])); 
        return res;
    }
	void upd(int l, int r, T val) {	// upd by comb on interval [l, r]
		for (l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
        if (l&1) seg[l++] = comb(seg[l],val);
        if (r&1) seg[--r] = comb(seg[r],val);
    } 
	}
};
