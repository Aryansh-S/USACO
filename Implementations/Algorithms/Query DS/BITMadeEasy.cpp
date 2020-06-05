#include <bits/stdc++.h>
using namespace std;
//BIT is very easy to implement!

struct BIT { //1-indexed!
    //init things
    int N; vector<int> bit; 
    void init(int n){bit.resize(n); N=--n;}
    void init(int* a, int n){init(n); move(a,a+n,begin(bit));}
    void init(vector<int>& v){init(v.size()); move(begin(v),end(v),begin(bit));}
    
    //actual bit
    void upd(int x, int v){for(;x<=N;x+=x&-x) bit[x]+=v;}
    int sum(int r){int res=0; for(;r;r-=r&-r) res+=bit[r]; return res;}
    int sum(int l, int r){return sum(r)-sum(l-1);}
    
    //extension
    int get(int x){return sum(x,x);}
    void upd_a(int x, int v){upd(x,v-get(x));} //assignment update example
} tree; 

int main(){
    tree.init(3);
    tree.upd(1,10); 
    tree.upd(2,20);
    cout << tree.sum(2) << "\n";
    return 0;
}
