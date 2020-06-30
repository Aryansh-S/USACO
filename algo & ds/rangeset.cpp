#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> //hset, hmap
using namespace std; using namespace __gnu_pbds; 

//Range Set Data Structure: query for element existence (bool) in ranges
//Also useful for HLD (see my online milkvisits sol for an example)

template<class T, class U, class chash = hash<T>> using hmap = gp_hash_table<T, U, chash>; 

template<class T> struct rngset { //log n "exist?" queries
    #define DYNAMIC 

    #ifndef DYNAMIC
        vector<set<int>> colors; 
        rngset(T maxel) : colors(maxel + 1) { }
    #else 
        hmap<T, set<int>> colors; 
    #endif

    void upd(int i, int v, bool put = 1) { //put val v at idx i
        if(put) colors[v].insert(i); else colors[v].erase(i);
    }
    bool qry(int i, int j, int v) { //check if v in [i,j]
        bool res = 0; 
        auto it = colors[v].lower_bound(i);
        if(it != end(colors[v]) && *it <= j) res = 1; 
        return res; 
    }
};

#ifndef DYNAMIC 
    rngset<int> s(100); //construct w/ max element
#else
    rngset<int> s; 
#endif

int main() {
    s.upd(0,10); 
    s.upd(1,20);
    assert(s.qry(0,1,10) && s.qry(0,1,20) && !s.qry(0,1,15));
    s.upd(0,10,0);
    assert(!s.qry(0,1,10));
}
