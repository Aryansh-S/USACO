#include <bits/stdc++.h>
using namespace std; 

//slow but intuitive 

template<class T> struct node {
  node *left, *right; int l, r; T val; 
  
  node(int a, int b) {
    l = a, r = b; 
    if(l == r) return; 
    int m = (l + r) / 2; 
    left = new node(l, m), right = new node(m + 1, r); 
  }
  
  const T ID = 0x3f3f3f3f; 
  T comb(T a, T b) { return min(a,b); }
 
  void upd(int x, T v) {
    if(x < l || x > r) return; 
    if(l == r) { val = v; return; }
    left->upd(x,v), right->upd(x,v); 
    val = comb(left->val, right->val); 
  }
  T qry(int a, int b) {
    if(a > r || b < l) return ID; 
    if(a <= l && b >= r) return val;
    return comb(left->qry(a,b), right->qry(a,b)); 
  }
};

node<int> seg(0,2); 

int main() {
  seg.upd(0,1), seg.upd(1, 2), seg.upd(2,3); 
  printf("%d\n", seg.qry(0,2)); 
}
