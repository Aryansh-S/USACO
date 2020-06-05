#include <bits/stdc++.h>
using namespace std;
//BIT is very easy to implement!

struct BIT {
    int n; vector<int> bit; 
    void init(int _n){n = _n; bit.assign(n);}
    void init(int* a, int _n){init(_n); move(a,a+n,begin(bit));}
    void init(vector<int>& v){init(v.size()); move(begin(v),end(v),begin(bit));}
    void upd(int x, int v){for(;x<=100;x+=x&-x) bit[x]+=v;}
    int sum(int r){int res=0; for(;r;r-=r&-r) res+=bit[r]; return res;}
    int sum(int l, int r){return sum(r)-sum(l-1);}
    void upd_a(int x, int v){upd(x,val-sum(x,x));} //assignment update example
} tree; 

int main(){
    tree.upd(1,10); 
    tree.upd(2,20);
    cout << tree.sum(2) << "\n";
    return 0;
}
