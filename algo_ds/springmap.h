// Add a pair (a,b) in log n. 
// For any x, query the maximum value of b over all pairs satisfying a >= x in log n. 

template<class T> struct smap {
  map<T,T> m;  
  void ins(T a, T b) { 
    auto it = m.lb(a); 
    if(it != end(m) && it->s >= b) return; 
    it = m.ins(it,{a,b}); 
    it->s = b;
    while(it != begin(m) && prev(it)->s <= b) m.ers(prev(it));
  }
  T qry(T x) {
    auto it = m.lb(x);
    return it == end(m) ? 0 : it->s;
    //it = end(m) means that no pair satisfies a >= x
  }
};
