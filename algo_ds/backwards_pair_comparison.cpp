struct CPS { 
  template<class T, class U> 
  bool operator() (const pair<T,U> &a, const pair<T,U> &b) { return mp(a.s,a.f) < mp(b.s,b.f); } 
};
