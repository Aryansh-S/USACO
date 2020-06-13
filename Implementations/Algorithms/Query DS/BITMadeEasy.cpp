#include <bits/stdc++.h>
using namespace std;
//BIT is very easy to implement!

template<class T> struct BIT { //1-indexed!
    //operation
    const T ID = 0;
    T comb(T a, T b) { return a + b; }
    T inv_comb(T a, T b) { return a - b; }

    //init things
    int N; vector<T> bit; 
    void init(int n){bit.assign(n, ID); N=--n;}

    //actual bit
    void upd(int x, T v){for(;x<=N;x+=x&-x) bit[x]=comb(bit[x],v);}
    T qry(int r){T res = ID; for(;r;r-=r&-r) res=comb(res,bit[r]); return res;}
    T qry(int l, int r){return inv_comb(qry(r),qry(l-1));}
    
    //extension
    T get(int x){return qry(x,x);}
    void put(int x, int v){upd(x,inv_comb(v, get(x)));} //put/assignment update example
};

BIT<int> tree; 

int main(){
    tree.init(3);
    tree.upd(1,10); 
    tree.upd(2,20);
    cout << tree.qry(2) << "\n";
}
