//helper function if needed to balance the tree for binary search, etc.
//use to quickly & efficiently balance n for use in init iterative segtree

ll POW(ll a, ll b) { //log (from template)
	ll res = 1; while(b) res *= (b & 1)? a : 1, a*=a, b>>=1;
	return res;
}

int nxtp2(int v) { //next power 2
    int ret = POW(2,__builtin_clz(v)); 
    return v > ret ? ret<<1 : ret;
}
