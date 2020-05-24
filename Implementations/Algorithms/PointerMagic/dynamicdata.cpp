//using pointers, we can maintain dynamic data
//for instance, suppose we want to support a "dynamically sorted arrayr" without having to deal with erase and insert into a 
set every single time

#include <bits/stdc++.h>
using namespace std;

int a[]={3,1,2};
auto cmp = [](int*a,int*b){return *a<*b};
set<int*,decltype(cmp)> s(cmp);

int main(){

  for(auto& k:a) s.insert(&k); 
  
  for(auto k:s) cout << *k << "\n";
  
  a[0]=6; 
  
  for(auto k:s) cout << *k << "\n";
  
  return 0;

}
