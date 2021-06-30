template<class T, typename fnc> T bsearch(T l, T r, fnc&& works, T inval = -1, int tp = 3) { 
    // search works() in [l,r], where works() is an inequality bool >= or <= 
    // tp = 0 for find min, tp = 1 for find max (inferred unless forced)
    // returns inval if invalid
    if(tp != 0 && tp != 1) tp = works(l); // check if forced
    T lo = l, hi = r, ans = tp ? r : l;
    while(lo <= hi) {
      T mid = lo + (hi - lo) / 2; 
      if(works(mid)) ans = mid, tp ? lo = mid + 1 : hi = mid - 1;
      else tp ? hi = mid - 1 : lo = mid + 1; 
    }
    return works(ans) ? ans : inval; 
}
