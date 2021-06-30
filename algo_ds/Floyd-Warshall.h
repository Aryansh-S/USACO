//get all shortest paths, O(n^2) space and O(n^3) time

template<class T, int SZ> struct Floyd {
  T dist[SZ][SZ];
  Floyd(){F0R(i,SZ) F0R(j,SZ) dist[i][j]=INF;}
  void add(int a, int b, T w){dist[a][b]=dist[b][a]=w;}
  void add_(int a, int b, T w){dist[a][b]=w;}
  void upd(){
    F0R(k,SZ) F0R(i,SZ) F0R(j,SZ) ckmin(dist[i][j],dist[i][k]+dist[k][j]);
  }
  T qry(int a, int b){return dist[a][b];}
  bool negcyc(){F0R(i,SZ) if(dist[i][i]<0) return 1; return 0;}
};
