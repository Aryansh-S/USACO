// Range Set Data Structure: query for element count (int) or existence (bool) in ranges
// Also useful for HLD (see my online milkvisits sol for an example)

// wavelet tree for more advanced version (2D in same complexity, great for hld)

template<class T> struct rngset { //log n count queries
    OST<pair<T,int>> ds; 

    void upd(int i, T v, bool put = 1) { //put val v at idx i
        if(put) ds.ins(mp(v,i)); else ds.ers(mp(v,i)); 
    }
    int qry(int i, int j, T v) { //count if v in [i,j]
        return ds.ook(mp(v,j+1)) - ds.ook(mp(v,i));
    }
};
