#include <bits/stdc++.h>
using namespace std;
//level: silver 

bool works(int m) { 
    //write a <= or >= equality to return bool
}

int bs(int l, int r, bool tp, int inval = -1) { 
    //search works() in [l,r]
    //tp = 0 for find min, tp = 1 for find max
    int lo = l, hi = r, ans = tp ? r : l; 
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2; 
        if(works(mid)) ans = mid, tp ? lo = mid + 1 : hi = mid - 1;
        else tp ? hi = mid - 1 : lo = mid + 1; 
    }
    return works(ans) ? ans : inval;
        //returns inval if invalid
}

//footnote: (hi + low) can overflow, so do hi + (hi - lo) / 2 instead of (hi + lo) / 2
