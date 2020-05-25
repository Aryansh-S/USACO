#include <bits/stdc++.h>
using namespace std;

//a simple, efficient segment tree to support point update, range query for min, max, sum, etc.

template<class T> struct SEG{ //UPD literally updates!!
	const T orz=-10*big;
	char choice='s'; //'m' is min, 'M' is max, 's' is sum
	void choose(char ch){choice=ch;}
	T comb(T a, T b){
		if(a==orz){if(b==orz){return 0;} return b;}
		if(b==orz) return a;
		if(choice=='m') return min(a,b);
		if(choice=='s') return a+b;
		if(choice=='M') return max(a,b);
	}
	int n; vector<T> seg;
		void init(int _n) { n = _n; seg.assign(4*n+1,orz); }
		void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
		void upd(int p, T val) { // set val at position p
			seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
		T query(int l, int r) {	// query choice on interval [l, r]
			T ra = orz, rb = orz;
			for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
				if (l&1) ra = comb(ra,seg[l++]);
				if (r&1) rb = comb(seg[--r],rb);
			}
			return comb(ra,rb);
	}
};

SEG<int> test; 

int main(){
  
  test.init(10); 
  test.upd(1,10); test.upd(1,12); test.upd(2,12); cout << test.query(1,2) << "\n";
  
  return 0;
}
