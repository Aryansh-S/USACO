//Lazy Merge Sort Segment Tree (Multiset Nodes)
  //Each leaf is a multiset and begins as 0
  //Range updates modify these leaves
  //Range queries merge leaves in requested range and return multiset (which can then be binary searched, etc.)

//Good for "existence" queries (i.e., in HLD, querying along path/subtree for existence of node/edge of certain val)

struct LSEG {
	using R = array<int, 2>; 
		// Range type -- begin, end indices; always the form [begin,end)
	using L = int; 
		// Lazy type -- type you want to update with 
	using Q = multiset<int>; 		
		// Query type -- type you want to query for

	L lop(const L &lazy, const R &r0, const L &x, const R &r1) {
		return x;
	} 
		// how does a lazy operation in range r1 "add" with one in range r0? r1 always contains r0

	Q qop(const Q &lval, const R &r0, const Q &rval, const R &r1) {
		Q ret; merge(begin(lval),end(lval),begin(rval),end(rval),inserter(ret,begin(ret))); return ret; 
	} 
		// what is the query operation between lval and rval? always r0[1] == r1[0]

	Q aop(const Q &val, const R &r0, const L &x, const R &r1) {
		Q ret; for(int i = 0; i < val.size(); ++i) ret.insert(x); return ret; 
	} 
		// how does the lazy operation apply over a range? r1 always contains r0

	const pair<L, Q> id = {0, {}}; 
		//ids of lazy and query types

	Q init(const int &p) { return {0}; } 
		//how to initialize all queries 

	vector<int> roots; int n, h;
	vector<R> range; vector<L> lazy; 
	vector<Q> val; 
		//this is equivalent of seg, last n are leaves

	template<typename it>
	LSEG(it bg, it nd): n(distance(bg, nd)), h(__lg(n) + 1), range(2 * n), lazy(2 * n, id.first), val(n, id.second) {
		init_range();
		val.insert(end(val), bg, nd);
		build(0, n);
	}
	LSEG(int n): n(n), h(__lg(n) + 1), range(2 * n), lazy(2 * n, id.first), val(2 * n) {
		init_range();
		for(int i = n; i < 2 * n; ++i) val[i] = init(i - n);
		build(0, n);
	}

	inline int lc(int p) { return 2 * p; }
	inline int rc(int p) { return lc(p) + 1; }

	void init_roots() {
		vector<int> roots_r;
		for(auto l = n, r = 2 * n; l < r; l /= 2, r /= 2) {
			if(l & 1) roots.push_back(l++);
			if(r & 1) roots_r.push_back(--r);
		}
		roots.insert(end(roots), begin(roots_r), end(roots_r));
	}
	void init_range() {
		for(int i = n; i < 2 * n; ++i) range[i] = {i - n, i - n + 1};
		for(int i = n - 1; i > 0; --i) range[i] = {range[lc(i)][0], range[rc(i)][1]};
	}

	void refresh(int p) {
		if(p < n) val[p] = qop(val[lc(p)], range[lc(p)], val[rc(p)], range[rc(p)]);
		if(lazy[p] != id.first) val[p] = aop(val[p], range[p], lazy[p], range[p]);
	}
	void build(int l, int r) {
		for(l += n, r += n - 1; l > 1; ) {
			l /= 2, r /= 2;
			for(int i = r; i >= l; --i) refresh(i);
		}
	}

	void push(int l, int r) {
		int s = h;
		for(l += n, r += n - 1; s > 0; --s) {
			for(int i = l >> s; i <= r >> s; ++i) if(lazy[i] != id.first) {
				val[lc(i)] = aop(val[lc(i)], range[lc(i)], lazy[i], range[i]);
				lazy[lc(i)] = lop(lazy[lc(i)], range[lc(i)], lazy[i], range[i]);
				val[rc(i)] = aop(val[rc(i)], range[rc(i)], lazy[i], range[i]);
				lazy[rc(i)] = lop(lazy[rc(i)], range[rc(i)], lazy[i], range[i]);
				lazy[i] = id.first;
			}
		}
	}

	void upd(int l, int r, L x) {
    		++r; //for the sake of inclusivity on right bound
		if(l >= r) return;
		const R update_range{l, r};
		push(l, l + 1), push(r - 1, r);
		bool cl = 0, cr = 0;
		for(l += n, r += n; l < r; l /= 2, r /= 2) {
			if(cl) refresh(l - 1);
			if(cr) refresh(r);
			if(l & 1) {
				val[l] = aop(val[l], range[l], x, update_range);
				if(l < n) lazy[l] = lop(lazy[l], range[l], x, update_range);
				++l;
				cl = 1;
			}
			if(r & 1) {
				--r;
				val[r] = aop(val[r], range[r], x, update_range);
				if(r < n) lazy[r] = lop(lazy[r], range[r], x, update_range);
				cr = 1;
			}
		}
		for(--l; r > 0; l /= 2, r /= 2) {
			if(cl) refresh(l);
			if(cr && (!cl || l != r)) refresh(r);
		}
	}
	Q qry(int l, int r) {
    		++r; //for the sake of inclusivity on right bound
		push(l, l + 1);
		push(r - 1, r);
		Q resl = id.second, resr = id.second;
		R l_range{l, l}, r_range{r, r};
		for(l += n, r += n; l < r; l /= 2, r /= 2) {
			if(l & 1) resl = qop(resl, l_range, val[l], range[l]), l_range[1] = range[l][1], ++l;
			if(r & 1) --r, resr = qop(val[r], range[r], resr, r_range), r_range[0] = range[r][0];
		}
		return qop(resl, l_range, resr, r_range);
	}
	/*
	void print() {
		for(int u = 0; u < 2 * n; ++u){
			cout << u << "-th node represents [" << range[u][0] << ", " << range[u][1] 
			<< "], val = " << val[u] << ", lazy = " << lazy[u] << "\n";
		}
	}
	*/
};
