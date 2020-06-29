
template<class T> struct operation { //for qry & upd
    const T ID = 0; 
    T comb(T a, T b) { return a + b; }
    T inv_comb(T a, T b) { return a - b; }
    T m_comb(T a, int L) { return a * L; } 
        //how does it compose with itself over a range
}; 

//point upd, range qry -- multiple dimensions
template <class T, int ...Ns> struct BIT { 
    operation<T> op; 

    T val = op.ID; 
    void upd(T v) { val = op.comb(val,v); } 
    T qry() { return val; } 
};
template <class T, int N, int... Ns> struct BIT<T, N, Ns...> { 
    BIT<T,Ns...> bit[N+1]; operation<T> op; 

    template<typename... Args> void upd(int pos, Args... args) { 
        for (; pos<=N; pos+=pos&-pos) bit[pos].upd(args...); 
    } 
    template<typename... Args> T sum(int r, Args... args) {
        T res = op.ID; for (;r;r-=r&-r) res = op.comb(res, bit[r].qry(args...)); 
        return res; 
    }
    template<typename... Args> T qry(int l, int r, Args...args) { 
        return op.inv_comb(sum(r, args...),sum(l - 1, args...)); 
    }
};

//range upd, range qry (lazy, same operation)
template<class T, int SZ> struct LBIT { 
    BIT<T,SZ> bit[2]; operation<T> op; 

    void upd(int l, int r, T val) {
        bit[0].upd(l, val); 
        bit[0].upd(r, op.inv_comb(op.ID, val));
        bit[1].upd(l, op.m_comb(val, l - 1));
        bit[1].upd(r, op.inv_comb(op.ID, op.m_comb(val, r)));
    }

    T sum(int x) { return op.inv_comb(op.m_comb(bit[0].sum(x),x), bit[1].sum(x)); }
    T qry(int x, int y) { return op.inv_comb(sum(y),sum(x-1)); }
}; 

//merge sort tree BIT
template<int SZ> struct MBIT { 
	OST<pii> val[SZ]; operation<T> op; 
    
	void upd(int x, int y, int t = 1) { 
		for(int X = x; X < SZ; X += X&-X) {
			if(t == 1) val[X].insert({y,x});
			else val[X].erase({y,x});
		}
	}
	int qry(int x, int y) { 
		int res = 0; 
        	for(; x; x -= x&-x) res += val[x].ook({y,MOD});
		return res;
	}
	int qry(int xl, int xr, int yl, int yr) { 
		return query(xr, yr) - query(xl-1, yr) - query(xr, yl-1) + query(xl-1, yl-1); 
    }
};

/*
LBIT<int, 3> b; 

int main() {
    b.upd(1,2,11);
    b.upd(1,1,5);
    assert(b.qry(1,2)==27);
}
*/
