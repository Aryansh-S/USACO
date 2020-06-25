#include <bits/stdc++.h>
using namespace std;
//level: silver 

bool works(int m) { 
    //write a <= or >= equality to return bool
}

int bs(int l, int r, bool tp) { 
    //search works() in [l,r]
    //tp = 0 for find min, tp = 1 for find max
    int lo = l, hi = r, ans = -1; 
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2; 
        if(works(mid)) ans = mid, tp ? hi = mid - 1 : lo = mid + 1; 
        else tp ? lo = mid + 1 : hi = mid - 1; 
    }
    return ans; 
}

//footnote: (hi + low) can overflow, so do hi + (hi - lo) / 2 instead of (hi + lo) / 2
