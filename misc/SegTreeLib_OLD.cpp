namespace SegmentTree { //define any operator as a functional expression with an identity constant
    template<class T> class opadd {public: const T ID = 0; T comb(T a, T b){return a + b;}};
    template<class T> class opmult {public: const T ID = 1; T comb(T a, T b){return a * b;}};
    template<class T> class opxor {public: const T ID = 0; T comb(T a, T b){return a ^ b;}};
    template<class T> class opmin {public: const T ID = INF; T comb(T a, T b){return min(a, b);}};
    template<class T> class opmax {public: const T ID = -INF; T comb(T a, T b){return max(a, b);}};
    template<class T> void upd_(T&a, T&b, string &tp){ //define update type
        if(tp == "id") { a = b; }
        if(tp == "add") { a += b; }
        if(tp == "xor") { a ^= b; }
        if(tp == "mult") { a *= b; }
    }
    template<class T> T getID(T a, string &tp) { //ID of update type required for lazy propagation 
        if(tp == "id") return a;
        if(tp == "add") return 0;
        if(tp == "xor") return 0;
        if(tp == "mult") return 1; 
        return 0;
    }

    template<class T = int, class U = opadd<T>> struct SegTree {
        // POINT UPDATE, RANGE QUERY
        int n; vector<T> seg; U oper; string tp = "id"; 
        void init(int _n) { n = _n; seg.assign(2*n,oper.ID); }
        void initv(int _n, int val = 0){ n = _n; seg.assign(2*n, val); }
        void pull(int p) { seg[p] = oper.comb(seg[2*p],seg[2*p+1]); }
        void upd(int p, T val) { // upd position p to val
	    if(p == 0){cout << "FAILURE: PLEASE 1-INDEX\n"; exit(1);}
            upd_<T>(seg[p += n],val,tp); for (p /= 2; p; p /= 2) pull(p);
        }
        void chupd(string s){tp = s;} //change update type
        T query(int l, int r) {	// sum on interval [l, r]
            T ra = oper.ID, rb = oper.ID; 
	    if(l == 0){cout << "FAILURE: PLEASE 1-INDEX\n"; exit(1);}
            for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
                if (l&1) ra = oper.comb(ra,seg[l++]);
                if (r&1) rb = oper.comb(seg[--r],rb);
            }
            return oper.comb(ra,rb);
        }
    };
    
    template<const int n, class T = int, class U = opadd<T>> struct LazySegTree {
	//RANGE UPDATE, RANGE QUERY
        vector<T> seg, lazy; U oper; string tp = "add"; //CHUPD BEFORE INIT
        int segtree_size(int x){
            if((x != 0) && ((x & (x - 1)) == 0)) {cout << "FAILURE: DO NOT USE A POWER OF 2\n"; exit(1);}
            x -= 1;
            x |= x >> 1;
            x |= x >> 2;
            x |= x >> 4;
            x |= x >> 8;
            x |= x >> 16;
            return 2 * x + 1;
        }
        void chupd(string s){tp = s;} //change update type
        void pull(int ind) {
            seg[ind] = oper.comb(seg[2*ind+1],seg[2*ind+2]);
        }
        void init(int _n = n) {seg.assign(segtree_size(n),0); lazy.assign(segtree_size(n),getID<T>(0,tp));}
        void initid(int _n = n) {seg.assign(segtree_size(n),oper.ID); lazy.assign(segtree_size(n),getID<T>(0,tp));}
        void initv(int val = 0, int _n = n) {seg.assign(segtree_size(n),val); lazy.assign(segtree_size(n),getID<T>(0,tp));}
        void push(int ind, int L, int R) {
            if(lazy[ind] != getID<T>(lazy[ind],tp)){
                upd_<T>(seg[ind], lazy[ind], tp);
                if(L != R) upd_<T>(lazy[2*ind+1],lazy[ind],tp), upd_<T>(lazy[2*ind+2],lazy[ind],tp);
                lazy[ind] = getID<T>(lazy[ind],tp);
            }
        }
        void upd(int lo, int hi, T inc, int ind = 0, int L = 0, int R = n - 1) {
	    if(lo == 0) {cout << "FAILURE: PLEASE 1-INDEX\n"; exit(1);}
	    push(ind, L, R);
            if(hi < L || R < lo) return;
            if(lo <= L && R <= hi) {
                upd_<T>(lazy[ind],inc,tp);
                return;
            }
            int M = (L+R)/2;
            upd(lo,hi,inc,2*ind+1,L,M); upd(lo,hi,inc,2*ind+2,M+1,R);
            pull(ind);
        }
        T query(int lo, int hi, int ind = 0, int L = 0, int R = n - 1) {
	    if(lo == 0) {cout << "FAILURE: PLEASE 1-INDEX\n"; exit(1);}
            if(lo > R || L > hi) return oper.ID;
            push(ind, L, R);
            if (lo <= L && R <= hi) return seg[ind];
	    int M = (L+R)/2;
	    return oper.comb(query(lo,hi,2*ind+1,L,M),query(lo,hi,2*ind+2,M+1,R));
        }
    };
    
    template<typename U = int, template<typename> class T = opadd> using SEG = SegTree<U, T<U>>;
    template<int sz, typename U = int, template<typename> class T = opadd> using LSEG = LazySegTree<sz, U, T<U>>;
    //1-index and never make size a power of 2
}; 
using namespace SegmentTree;
