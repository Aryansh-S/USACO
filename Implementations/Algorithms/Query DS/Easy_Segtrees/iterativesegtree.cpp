//Iterative Generic Segment Tree: Point Update, Range Query (0 - Indexing Allowed), Exactly 2N Memory (Not 4N)
//Source: https://codeforces.com/blog/entry/18051 & Modified
//Suggested to use N as power of 2 if doing binary search, order statistics, etc. (perfect binary tree)
//, but not necessarily required

#define INF 0x3f3f3f3f

template<class T> struct SEG { // comb(ID,b) = b, 0-indexing works, any associative operation. 
	//seg[1] = qry(0,n-1) 
	const T ID = -INF; T comb(T a, T b) { return max(a,b); } 
	int n; vector<T> seg;
	void init(int _n) { n = _n; seg.assign(2*n, ID); } 
    	void init(vector<T>& v) { init(v.size()); copy(begin(v), end(v), begin(seg) + n); build(); }
    	void init(T* a, int _n) { init(_n); copy(a, a + n, begin(seg) + n); build(); }
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
};

