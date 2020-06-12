#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std; using namespace __gnu_pbds;

using ll = long long; 
const ll INFLL = LLONG_MAX;

#define TIME \
  chrono::duration<double, milli>(chrono::steady_clock::now()-CLK).count()

#define TICK \
  CLK = chrono::steady_clock::now()

template<class T, class U, class chash = hash<T>> using hmap = gp_hash_table<T, U, chash>; 

//task: coordinate compress information benchmarks -- what to use for sparsely mapped info?
  //we will make this test as dense as possible for the sake of boundary checks

/* 
approx runtime (ms):
map: 1010.88
unordered_map: 912.901
gp_hash_table: 410.223
*/

/*
approx memory ratios: 
map: 48
unordered_map: 56
gp_hash_table: 104
*/

//result: use gp_hash_table for most cases (it kills more memory but gives an edge in performance)
//maps work if memory is sensitive/bottleneck (very rare in contests)

map<ll,ll> m; unordered_map<ll,ll> um; hmap<ll,ll> hm; auto TICK; 

int main() {
  cin.tie(0)->sync_with_stdio(0); cout << "RUNTIME:\n";
  
  TICK; //reset timer
  
  for(int i = 1; i <= 1e6; ++i) m[INFLL/i] = INFLL/i; ////
  
  cout << "map: " << TIME << '\n';
  
  TICK; //reset timer
  
  for(int i = 1; i <= 1e6; ++i) um[INFLL/i] = INFLL/i; ////
  
  cout << "unordered_map: " << TIME << '\n';
  
  TICK; //reset timer
  
  for(int i = 1; i <= 1e6; ++i) hm[INFLL/i] = INFLL/i; ////
  
  cout << "gp_hash_table: " << TIME << '\n';
  
  cout << "\nMEMORY USAGE:\n";
  
  cout << "map: "<< sizeof(m) << '\n';
  cout << "unordered_map: " << sizeof(um) << '\n';
  cout << "gp_hash_table: " << sizeof(hm) << '\n';
}
