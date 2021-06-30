#include <bits/stdc++.h>
using namespace std; 

// Features reading, outputting, and debugging streamable types and containers of streamable types

#define all(x) begin(x),end(x)

namespace io {
  // define re, pr, de (used with the dbg macro)
  template<class T, class... U> void re(T&& a, U&&... b) {
    cin >> forward<T>(a); 
    (int[]){(cin >> forward<U>(b), 0)...};
  }
  template<class T, class... U> void pr(T&& a, U&&... b) {
    cout << forward<T>(a); 
    (int[]){(cout << " " << forward<U>(b), 0)...};
    cout << "\n";
  }
  template<class T, class... U> void de(T&& a, U&&... b) {
    cerr << forward<T>(a); 
    (int[]){(cerr << " " << forward<U>(b), 0)...};
    cerr << "\n";
  }
  
  // concise iterator "concept" (also includes pointers)
  template<class T> using is_it = typename enable_if<is_convertible<class iterator_traits<T>::iterator_category, input_iterator_tag>::value>::type;
  
  // iterator specializations 
  template<class T, class = is_it<T>> void re(T a, T b) {
    for_each(a, b, [&](decltype(*a) x) { cin >> x; }); 
  }
  template<class T, class = is_it<T>> void pr(T a, T b) {
    bool f = 1; 
    for_each(a, b, [&](decltype(*a) x) { cout << (f ? "" : " ") << x, f = 0; }); 
    cout << "\n";
  }
  template<class T, class = is_it<T>> void de(T a, T b) {
    bool f = 1; 
    for_each(a, b, [&](decltype(*a) x) { cerr << (f ? "" : " ") << x, f = 0; }); 
    cerr << "\n";
  }
}

#define dbg(...) { cerr << "[Line " << __LINE__ << "] " << #__VA_ARGS__ << " is "; io::de(__VA_ARGS__); }

// io examples
vector<int> v(3);
int a[4];
set<int> s {2, 5, 7};
int n,k;

int main() {
  using namespace io;
  cin.tie(0)->sync_with_stdio(0);
  // some examples of flexibility:
  re(all(v)); 
  pr(all(v)); 
  dbg(all(v)); 

  re(a,a+3);
  pr(all(a));
  dbg(all(a));

  pr(all(s));
  dbg(all(s));
  
  re(n,k); 
  pr(n,k); 
  dbg(n,k);
}
