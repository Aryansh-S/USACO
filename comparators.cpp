#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define f first
#define s second

struct CPS { 
	template<class T, class U> 
	bool operator() (const pair<T,U> &a, const pair<T,U> &b) const { return mp(a.s,a.f) < mp(b.s,b.f); } 
};

set<pair<int,int>, CPS>> example; 

int main() {
  example.emplace(1,2), example.emplace(2,1); 
  assert(begin(example)->f == 2); 
}
