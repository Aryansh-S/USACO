#include <bits/stdc++.h>
using namespace std;
//level: silver 

template<class T> bool works(T m) { 
    //write a <= or >= equality to return bool
}

template<class T> T bs(T l, T r, bool tp, T inval = -1) { 
    //search works() in [l,r]
    //tp = 0 for find min, tp = 1 for find max
    //returns inval if invalid
    
    auto lo = l, hi = r, ans = tp ? r : l; 
    while(lo <= hi) {
        auto mid = lo + (hi - lo) / 2; 
        if(works(mid)) ans = mid, tp ? lo = mid + 1 : hi = mid - 1;
        else tp ? hi = mid - 1 : lo = mid + 1; 
    }
    return works(ans) ? ans : inval;
}

//footnote: (hi + low) can overflow, so do hi + (hi - lo) / 2 instead of (hi + lo) / 2
