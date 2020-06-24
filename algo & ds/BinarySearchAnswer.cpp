#include <bits/stdc++.h>
using namespace std;
//level: silver 

bool works(int m){
 //check if works
 //make this an inequality that can be true over a search space monotonically instead of a flat equation 
 //otherwise won't work
}


#ifdef increasing //from not works to works as var increases (want min val that works in lo...hi)

int main() {
  int lo = 0, hi = N - 1, ans = lo;
  while(lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if(works(mid)) ans = mid, hi = mid - 1;
    else lo = mid + 1;
  } 
}

#endif

#ifdef decreasing //from works to not works as var increases (want max val that works in lo...hi)

int main() {
    int lo = 0, hi = N - 1, ans = hi; 
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2; 
        if(works(mid)) ans = mid, lo = mid + 1
        else hi = mid - 1; 
    }
}

#endif

//footnote: (hi + low) can overflow, so do hi + (hi - lo) / 2 instead of (hi + lo) / 2
