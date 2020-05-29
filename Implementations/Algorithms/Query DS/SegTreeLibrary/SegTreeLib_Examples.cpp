#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

namespace SegmentTree { //define any operator as a functional expression with an identity constant
    template<class T> class opadd {public: const T ID = 0; T comb(T a, T b){return a + b;}};
    template<class T> class opmult {public: const T ID = 1; T comb(T a, T b){return a * b;}};
    template<class T> class opxor {public: const T ID = 0; T comb(T a, T b){return a ^ b;}};
    template<class T> class opmin {public: const T ID = INF; T comb(T a, T b){return min(a, b);}};
    template<class T> class opmax {public: const T ID = -INF; T comb(T a, T b){return max(a, b);}};
    template<class T> void upd_(T&a, T&b, string tp = "id"){ //define update type
        if(tp == "id") { a = b; }
        if(tp == "add") { a += b; }
        if(tp == "xor") { a ^= b; }
        if(tp == "mult") { a *= b; }
    }
    template<class T> T getID(T a, string tp = "id") { //ID of update type required for lazy propagation 
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
            upd_<T>(seg[p += n],val,tp); for (p /= 2; p; p /= 2) pull(p);
        }
        void chupd(string s){tp = s;} //change update type
        T query(int l, int r) {	// sum on interval [l, r]
            T ra = oper.ID, rb = oper.ID; 
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
                if(L != R) lazy[2*ind+1] = oper.comb(lazy[2*ind+1],lazy[ind]), lazy[2*ind+2] = oper.comb(lazy[2*ind+2],lazy[ind]);
                lazy[ind] = getID<T>(lazy[ind],tp);
            }
        }
        void upd(int lo, int hi, T inc, int ind = 1, int L = 0, int R = n - 1) {
            if(hi < L || R < lo) {push(ind, L, R); return;}
	    if(lo <= L && R <= hi) {
		    upd_(lazy[ind],inc,tp);
		    push(ind,L,R); return;
	    }
            int M = (L+R)/2;
		    upd(lo,hi,inc,2*ind+1,L,M); upd(lo,hi,inc,2*ind+2,M+1,R);
		    pull(ind);
        }
        T query(int lo, int hi, int ind = 1, int L = 0, int R = n - 1) {
            if(lo > R || L > hi) return oper.ID;
            push(ind, L, R);
            if (lo <= L && R <= hi) return seg[ind];
	    int M = (L+R)/2;
	    return oper.comb(query(lo,hi,2*ind+1,L,M),query(lo,hi,2*ind+2,M+1,R));
        }
    };
    
    template<typename U = int, template<typename> class T = opadd> using SEG = SegTree<U, T<U>>;
    template<int sz, typename U = int, template<typename> class T = opadd> using LSEG = LazySegTree<sz, U, T<U>>;
}; 
using namespace SegmentTree;

SEG<int, opmult> s1; 
//example: integer standard segment tree that supports multiplication queries

LSEG<2 + 1, int, opxor> s2; //initialize for n = 2 (safety increment 1)
//example: integer lazy propagation segment tree that supports xor queries

int main(){
    s1.init(2 + 1); //initialize for n = 2 (safety increment 1)
    s1.upd(0,4); s1.upd(1,5); 
    s1.chupd("add"); //change to addition updates
    s1.upd(1,6); 
    cout << "standard query: " << s1.query(0,1) << '\n';
    //yields 4(5 + 6) = 44 because update type changed from id (literal assignment) to add 
    s2.chupd("mult"); //change to multiplication updates
    s2.initv(1); s2.upd(0,1,3); s2.upd(0,1,18); 
    cout << "lazy query: " << s2.query(0,1) << '\n';
    //yields (1*3*18) xor (1*3*18) = 0
}

// watch for indexing -- it's a good idea to make the size a little bigger (at least +1 or +2) than necessary
