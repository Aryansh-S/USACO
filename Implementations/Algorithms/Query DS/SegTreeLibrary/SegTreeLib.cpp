#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
using ll = long long;

namespace SegmentTree {
    namespace query_monoids { 
        //base monoid class (M)
        template<typename T, T ID> class monoid { public: 
            T _res; monoid(T r) : _res(r) {} 
            monoid(): _res(ID) {} //identity (default init)
            operator T() const {return _res;}
            friend ostream& operator<<(ostream& os, monoid& a) {return os << a._res;}
            friend istream& operator>>(istream& is, monoid& a) {return is >> a._res;}
        }; 
        //premade monoids: inherited from base monoid
        template<typename T> class qryadd : public monoid<T,0> { public: using monoid<T,0>::monoid; 
            qryadd(const qryadd& l, const qryadd& r): monoid<T,0>(l._res + r._res) {}
        };
        template<typename T> class qrymult : public monoid<T,1> { public: using monoid<T,1>::monoid; 
            qrymult(const qrymult& l, const qrymult& r): monoid<T,1>(l._res * r._res) {}
        };
        template<typename T> class qryxor : public monoid<T,0> { public: using monoid<T,0>::monoid; 
            qryxor(const qryxor& l, const qryxor& r): monoid<T,0>(l._res ^ r._res) {}
        };
        template<typename T> class qrymin : public monoid<T,INF> { public: using monoid<T,INF>::monoid; 
            qrymin(const qrymin& l, const qrymin& r): monoid<T,INF>(min(l._res, r._res)) {}
        };
        template<typename T> class qrymax : public monoid<T,-INF> { public: using monoid<T,-INF>::monoid; 
            qrymax(const qrymax& l, const qrymax& r): monoid<T,-INF>(max(l._res, r._res)) {}
        };        
    } 
    using namespace query_monoids; 

    namespace update_functions { 
        //base update endomorphism class (F)
        template<typename T, T ID> class endof { public: using type_T = T; 
            T _tot; endof(): _tot(ID) {}
            endof(T u): _tot(u) {} 
            bool is_identity() const {return _tot == ID;}
        };
        //premade updates: inherited from base endomorphism
        template<typename T, class U> class updadd : public endof<T,0> { public: using endof<T,0>::endof;
            updadd(const updadd& l, const updadd& r): endof<T,0>(l._tot + r._tot) {}
            U operator()(const U& x){return U(this->_tot + x);}
        };
        template<typename T, class U> class updxor : public endof<T,0> { public: using endof<T,0>::endof;
            updxor(const updxor& l, const updxor& r): endof<T,0>(l._tot ^ r._tot) {}
            U operator()(const U& x){return U(this->_tot ^ x);}
        };
        template<typename T, class U> class updid : public endof<T,INF> { public: using endof<T,INF>::endof;
            updid(const updid& l, const updid& r): endof<T,INF>(l._tot) {}
            U operator()(const U& x){return U(this->_tot);}
        };
    }
    using namespace update_functions;
    
    bool failuresize(int x) { 
      return (x != 0) && ((x & (x - 1)) == 0); 
    }

    int segtree_size(int n) { // 2^(ceil(lg(n)) + 1) - 1
                if(failuresize(n)) {cout << "FAILED: DO NOT USE A POWER OF 2 FOR N\n"; exit(10);}
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

            int n;
            vector<M> values;
            vector<F> pends;

            explicit SegTree(int _n):
                n(_n), values(segtree_size(n)), pends(values.size()) {identity_check();}
            explicit SegTree(int _n, const M& x):
                n(_n), values(segtree_size(n)), pends(values.size()) {identity_check(); assign(x);}
            explicit SegTree(int _n, const M* a):
                n(_n), values(segtree_size(n)), pends(values.size()) {identity_check(); assign(a);}
            explicit SegTree(const vector<M>& v):
                n(v.size()), values(segtree_size(v.size())), pends(values.size()) {
                  identity_check(); assign(v);
                }

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
            M qry(int i, int j) {
                if(!i) { cout << "FAILED: DO NOT 0-INDEX!\n"; exit(10); }
                return query(0, 0, n-1, i, j);
            }

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
            void upd(int i, int j, typename F::type_T a) {
                update(i,j,F(a));
            }
    };

    template<typename T, template<typename> class A, template<typename, class> class B> using SEG = SegTree<A<T>,B<T,A<T>>>; 
    //please 1-index and avoid powers of 2 for n at all cost 
    //leaf nodes are indices N-1 to 2N-2 (starting from 0), inclusive
    //for instance 0-4 first branches into a leaf node of 2 for index sz-1 = 5-1 = 4
    //pass qry type obj if using array/vector
}
using namespace SegmentTree;

vector<qryadd<int>> v {0,2,3}; //prefixed with 0 
SEG<int,qryadd,updid> s(v);

int main(){
    cout << s.qry(1,2) << '\n';
}
