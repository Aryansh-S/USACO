#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

/*
Output of segment tree range queries are modelled as elements of a monoid.
Updates on the segment tree are functions on the monoid.
A Monoid is a class implementing the following methods:
* Monoid();  // constructor: identity element of monoid
* Monoid(const Monoid&, const Monoid&);  // constructor: element created by combining 2 elements
A Function is a class implementing the following methods:
* Function();  // constructor: identity function
* Function(const Function& f1, const Function& f2);  // constructor: function composition (f1.f2)
* bool is_identity() const;  // whether this function is the identity function
* Monoid operator()(const Monoid&);  // function definition
*/

namespace SegmentTree {
    namespace query_monoids { //M
        //be careful: all initialized to identity by default
        template<typename T> class qryadd {
            public:
                using tp = T; 
                T _sum; 
                qryadd(T s) : _sum(s) {}
                qryadd(): _sum(0) {} //additive identity
                qryadd(const qryadd& L, const qryadd& R):
                    _sum(L._sum + R._sum) {} //element created by combination
                T get() const {return _sum;}
        };
        template<typename T> class qrymult {
            public:
                using tp = T;
                T _prod; 
                qrymult(T p) : _prod(p) {}
                qrymult(): _prod(1) {} //multiplicative identity
                qrymult(const qrymult& L, const qrymult& R):
                    _prod(L._prod * R._prod) {} //element created by combination
                T get() const {return _prod;}
        };
        template<typename T> class qryxor {
            public:
                using tp = T;
                T _xor; 
                qryxor(T x) : _xor(x) {}
                qryxor(): _xor(0) {} //xor identity
                qryxor(const qryxor& L, const qryxor& R):
                    _xor(L._xor ^ R._xor) {} //element created by combination
                T get() const {return _xor;}
        };
        template<typename T> class qrymin { 
            public:
                using tp = T;
                T _min; 
                qrymin(T m) : _min(m) {}
                qrymin(): _min(INF) {} //min identity
                qrymin(const qrymin& L, const qrymin& R):
                    _min(min(L._min, R._min)) {} //element created by combination
                T get() const {return _min;}
        };
        template<typename T> class qrymax {
            public:
                using tp = T;
                T _max; 
                qrymax(T m) : _max(m) {}
                qrymax(): _max(-INF) {} //max identity
                qrymax(const qrymax& L, const qrymax& R):
                    _max(max(L._max, R._max)) {} //element created by combination
                T get() const {return _max;}
        };
    }
    using namespace query_monoids; 

    namespace update_functions { //F
        template<typename T> class updadd {
            public:
                using tp = T; 
                T _tot;
                updadd(): _tot(0) {} //identity function constructor
                updadd(const updadd& a, const updadd& b): 
                   _tot(a._tot + b._tot) {} //addition composition
                bool is_identity() const { //see if identity 
                    return !_tot;
                }
                qryadd<T> operator()(const qryadd<T>& x){
                    return qryadd<T>(_tot + x.get()); 
                }
                qrymult<T> operator()(const qrymult<T>& x){
                    return qrymult<T>(_tot + x.get());
                }
                qryxor<T> operator()(const qryxor<T>& x) {
                    return qryxor<T>(_tot + x.get());
                }
                qrymin<T> operator()(const qrymin<T>& x){
                    return qrymin<T>(_tot + x.get());
                }
                qrymax<T> operator()(const qrymax<T>& x){
                    return qrymax<T>(_tot + x.get());
                }
                explicit updadd(T __tot): _tot(__tot) {}
        };
        template<typename T> class updxor {
            public:
                using tp = T; 
                T _tot;
                updxor(): _tot(0) {} //identity function constructor
                updxor(const updxor& a, const updxor& b): 
                   _tot(a._tot ^ b._tot) {} //addition composition
                bool is_identity() const { //see if identity 
                    return !_tot;
                }
                qryadd<T> operator()(const qryadd<T>& x){
                    return qryadd<T>(_tot ^ x.get()); 
                }
                qrymult<T> operator()(const qrymult<T>& x){
                    return qrymult<T>(_tot ^ x.get());
                }
                qryxor<T> operator()(const qryxor<T>& x) {
                    return qryxor<T>(_tot ^ x.get());
                }
                qrymin<T> operator()(const qrymin<T>& x){
                    return qrymin<T>(_tot ^ x.get());
                }
                qrymax<T> operator()(const qrymax<T>& x){
                    return qrymax<T>(_tot ^ x.get());
                }
                explicit updxor(T __tot): _tot(__tot) {}
        };
        template<typename T> class updid { //think of it as *0+1
            public:
                using tp = T; 
                T _tot;
                updid(): _tot(INF) {} //identity function constructor
                updid(const updid& a, const updid& b): 
                   _tot(a._tot) {} //addition composition
                bool is_identity() const { //see if identity 
                    return _tot == INF; //always identity
                }
                qryadd<T> operator()(const qryadd<T>& x){
                    return qryadd<T>(_tot); 
                }
                qrymult<T> operator()(const qrymult<T>& x){
                    return qrymult<T>(_tot);
                }
                qryxor<T> operator()(const qryxor<T>& x) {
                    return qryxor<T>(_tot);
                }
                qrymin<T> operator()(const qrymin<T>& x){
                    return qrymin<T>(_tot);
                }
                qrymax<T> operator()(const qrymax<T>& x){
                    return qrymax<T>(_tot);
                }
                explicit updid(T __tot): _tot(__tot) {}
        };
    }
    using namespace update_functions;

    int segtree_size(int n) { // 2^(ceil(lg(n)) + 1) - 1
                if((n != 0) && ((n & (n - 1)) == 0)) ++n;
                n -= 1;
                n |= n >> 1;
                n |= n >> 2;
                n |= n >> 4;
                n |= n >> 8;
                n |= n >> 16;
                return 2 * n + 1;
    }

    template<class M, class F> class SegTree {
        // M is a monoid -- for queries
        // F is a function -- for updates
        public:
            typedef M value_type;
            typedef F func_type;

            static void identity_check() {
                if(!F().is_identity()) {
                    cout << "SegTree: function's default constructor is not identity\n";
                    exit(1);
                }
            }

        private:
            int n;
            vector<M> values;
            vector<F> pends;

        public:
            explicit SegTree(int _n):
                n(_n), values(segtree_size(n)), pends(values.size()) {identity_check();}
            explicit SegTree(int _n, const M& x):
                n(_n), values(segtree_size(n)), pends(values.size()) {identity_check(); assign(x);}
            explicit SegTree(int _n, const M* a):
                n(_n), values(segtree_size(n)), pends(values.size()) {identity_check(); assign(a);}
            explicit SegTree(const vector<M>& v):
                n(v.size()), values(segtree_size(v.size())), pends(values.size()) {identity_check(); assign(v);}

        private:
            void assign_values(int root, int first, int last, const M* a) {
                // root has the node number, first and last have the array indices.
                if(first == last) {
                    values[root] = a[first];
                }
                else {
                    int left = 2 * root + 1;
                    int mid = (first + last) / 2;
                    assign_values(left, first, mid, a);
                    assign_values(left+1, mid+1, last, a);
                    values[root] = M(values[left], values[left+1]);
                }
            }

            void assign_values(int root, int first, int last, const M& x) {
                // root has the node number, first and last have the array indices.
                if(first == last) {
                    values[root] = x;
                }
                else {
                    int left = 2 * root + 1;
                    int mid = (first + last) / 2;
                    assign_values(left, first, mid, x);
                    assign_values(left+1, mid+1, last, x);
                    values[root] = M(values[left], values[left+1]);
                }
            }

        public:
            void assign(const M* a) {
                pends.assign(values.size(), F());
                assign_values(0, 0, n-1, a);
            }

            void assign(const M& x) {
                pends.assign(values.size(), F());
                assign_values(0, 0, n-1, x);
            }

            void assign(const vector<M>& v) {
                if(v.size() < n) {
                    cout << "SegTree: vector input to assign is too short\n"; 
                    exit(3);
                }
                assign(v.data());
            }

        private:
            void propagate(int root, int first, int last) {
                if(!pends[root].is_identity()) {
                    values[root] = pends[root](values[root]);
                    if(first != last)
                    {
                        int left = 2 * root + 1;
                        pends[left] = F(pends[root], pends[left]);
                        pends[left+1] = F(pends[root], pends[left+1]);
                    }
                    pends[root] = F();
                }
            }

            M query(int root, int first, int last, int i, int j) {
                if(i>last || j<first) {
                    return M();
                }
                propagate(root, first, last);
                if(i<=first && last<=j) {
                    return values[root];
                }
                else {
                    int left = 2 * root + 1;
                    int mid = (first + last) / 2;
                    return M(query(left, first, mid, i, j), query(left+1, mid+1, last, i, j));
                }
            }

        public:
            M query(int i, int j) {
                if(!i) { cout << "FAILED: DO NOT 0-INDEX!\n"; exit(10); }
                return query(0, 0, n-1, i, j);
            }
            #define qry(x,y) query((x),(y)).get()

        private:
            void update(int root, int first, int last, int i, int j, const F& f) {
                if(i>last || j<first) {
                    propagate(root, first, last);
                }
                else if(i<=first && last<=j) {
                    pends[root] = F(f, pends[root]);
                    propagate(root, first, last);
                }
                else {
                    propagate(root, first, last);
                    int left = 2 * root + 1;
                    int mid = (first + last)/2;
                    update(left, first, mid, i, j, f);
                    update(left+1, mid+1, last, i, j, f);
                    values[root] = M(values[left], values[left+1]);
                }
            }

        public:
            void update(int i, int j, const F& f) {
                if(!i) { cout << "FAILED: DO NOT 0-INDEX!\n"; exit(10); }
                update(0, 0, n-1, i, j, f);
            }
            void upd(int i, int j, typename F::tp a) {
                update(i,j, F (a));
            }
    };

    template<typename T, template<typename> class A, template<typename> class B> using SEG = SegTree<A<T>,B<T>>; 
}
using namespace SegmentTree;

vector<qryadd<int>> v{0,1,2,3}; //maintain 1-indexing by prefixing with a 0

SEG<int, qryadd, updid> s(v);

int main(){
    cout << s.qry(1,3) << '\n';
    s.upd(1,3,1);
    cout << s.qry(1,3) << '\n';
}
