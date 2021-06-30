//O(sz) init, almost const time unite/get (technically O(alpha(n)) 
//good for connected comps, checking cycle, offline dyna con, etc. 

struct DSU { //from 0 to n-1
    vi e; void init(int n) { e = vi(n,-1); }
    bool cycfind; 
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -e[get(x)]; } //also use to check connected
    DSU(int SZ = 0) { init(SZ); } 
    bool unite(int x, int y) { // union-by-rank
      x = get(x), y = get(y);
      if(x==y){
        cycfind=1; return 0;
      }
      if (e[x] > e[y]) swap(x,y);
      e[x] += e[y]; e[y] = x; return 1;
    }
    int compnum(){ //return the number of components -- if want to check connected, don't use
        //you can also just count the number of negatives 
    int ret=1;
    F0R(i,sz(e)-1) if(get(i)!=get(i+1)) ret++;
    return ret;
  }
  bool cyc(){return cycfind;}
};
