//segtree on values instead of indices (recursive)

template<class T> struct SEG { //wavelet tree segtree
  vector<vector<int>> C; T s;
  //C[u][i] contains number of zeros until position i-1: [0,i)
  //s is size of "alphabet"

  template<typename it, typename = typename enable_if<is_iterator<it>::value>::type> 
  SEG(it bg, it nd, T maxel) : C((maxel + 1) * 2), s(maxel + 1) { 
    build(bg, nd, 0, s - 1, 1); //maxel = max element val 
  }

  template<typename it, typename = typename enable_if<is_iterator<it>::value>::type> 
  void build(it b, it e, T L, T U, int u) {
    if(L == U) return;
    T M = L + (U - L) / 2;

    C[u].reserve(e - b + 1); C[u].push_back(0);
    for(auto i = b; i != e; ++i) C[u].push_back(C[u].back() + (*i <= M));

    auto p = stable_partition(b, e, [=](int i){return i <= M;});

    build(b, p, L, M, u * 2); build(p, e, M+1, U, u * 2+1);
  }

  //count occurrences of c in positions [0,i]
  int occur(T c, int i) const {
    ++i; //internally, [0, i)
    int u = 1, r;
    T L = 0, U = s - 1, M; 
    while (L != U) {
      M = L + (U - L) / 2;
      r = C[u][i]; u *= 2;
      if(c <= M) i = r, U = M;
      else i -= r, L = M + 1, ++u;
    }
    return i;
  }

  //kth smallest element in position [i,j] subarray; k = 1 gives smallest
  int kth(int k, int i, int j) const {
    ++j; //internally, [i, j)
    int u = 1, ri, rj;
    T L = 0, U = s - 1, M; 
    while (L != U) {
      M = L + (U - L) / 2; 
      ri = C[u][i]; rj = C[u][j]; u *= 2;
      if(k <= rj-ri) i = ri, j = rj, U = M;
      else k -= rj-ri, i -= ri, j -= rj, L = M+1, ++u;
    }
    return U;
  }

  //count number of occurrences of numbers in the range [a, b] present in the sequence in positions [i, j]
  //(i.e. number of points in the specified rectangle)
  mutable T L, U;
  int qry(int i, int j, T a, T b) const {
    if(b < a || j < i) return 0;
    L = a; U = b;
    return qry(i, j + 1, 0, s - 1, 1);
  }

  int qry(int i, int j, T a, T b, int u) const {
    if(b < L || U < a) return 0;
    if(L <= a && b <= U) return j - i;
    T M = a + (b - a) / 2; 
    int ri = C[u][i], rj = C[u][j];
    return qry(ri, rj, a, M, u * 2) + qry(i - ri, j - rj, M + 1, b, u * 2 + 1);
  }
};
