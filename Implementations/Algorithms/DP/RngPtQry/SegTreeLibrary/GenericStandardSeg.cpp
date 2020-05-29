#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

namespace SegmentTree { //define any operator as a functional expression with an identity constant
    template<class T> class opadd {public: const T ID = 0; T comb(T a, T b){return a + b;}};
    template<class T> class opmult {public: const T ID = 1; T comb(T a, T b){return a * b;}};
    template<class T> class opxor {public: const T ID = 0; T comb(T a, T b){return a ^ b;}};
    template<class T> class opmin {public: const T ID = -INF; T comb(T a, T b){return min(a, b);}};
    template<class T> class opmax {public: const T ID = INF; T comb(T a, T b){return max(a, b);}};
    template<class T> void upd_(T&a, T&b, string tp = "id"){ //define update type
        if(tp == "id") a = b; 
        if(tp == "add") a += b;
    }

    template<class T = int, class U = opadd<T>> struct SegTree {
        int n; vector<T> seg; U oper; string tp = "id"; 
        void init(int _n) { n = _n; seg.assign(2*n,oper.ID); }
        void initv(int _n, int val = 0){ n = _n; seg.assign(2*n, val); }
        void pull(int p) { seg[p] = oper.comb(seg[2*p],seg[2*p+1]); }
        void upd(int p, T val) { // upd position p to val
            upd_<T>(seg[p += n],val,tp); for (p /= 2; p; p /= 2) pull(p);
        }
        void chupd(string s){tp = s;}
        T query(int l, int r) {	// sum on interval [l, r]
            T ra = oper.ID, rb = oper.ID; 
            for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
                if (l&1) ra = oper.comb(ra,seg[l++]);
                if (r&1) rb = oper.comb(seg[--r],rb);
            }
            return oper.comb(ra,rb);
        }
    };
    
    template<typename U = int, template<typename> class T = opadd> using SEG = SegTree<U, T<U>>;
}
using namespace SegmentTree;

SEG<int, opmult> s1; 
//example: integer segment tree that supports multiplication queries

int main(){
    s1.init(2);
    s1.upd(1,4); s1.upd(2,5); s1.chupd("add"); s1.upd(2,6); cout << s1.query(1,2) << '\n';
    //yields 4(5 + 6) = 44 because update type changed from id (literal assignment) to add 
}
