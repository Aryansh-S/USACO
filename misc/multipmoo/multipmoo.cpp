#include<bits/stdc++.h>
using namespace std;

int N, B[1001][1001], cellid[1001][1001], global_regid;
#define problemname "multimoo"

struct Graph{
  map<int,set<int>> out_edges;
  map<int,int> nodesize, regid;
  map<int,int> regsize;
};

typedef pair<int,int> pii;
map<int, Graph> G1;
map<pii, Graph> G2;

int visit(Graph &G, int nodeid, int regid){
  if (G.regid.count(nodeid) > 0) return 0;
  G.regid[nodeid] = regid;
  int a = G.nodesize[nodeid];
  for (int nbrid : G.out_edges[nodeid])
    a += visit(G, nbrid, regid);
  G.regsize[regid] = a;
  return a;
}

int largest_region(Graph &G){
  int m = 0;
  for (auto &p : G.out_edges) m = max(m, visit(G, p.first, ++global_regid));
  return m;
}

void add_edge(Graph &G, int node1, int node2){
  G.out_edges[node1].insert(node2);
  G.out_edges[node2].insert(node1);
  G.nodesize[node1] = G.nodesize[node2] = 1;
}

void add_G2_edge(int i1, int j1, int i2, int j2){
  int b1 = B[i1][j1], b2 = B[i2][j2], c1 = cellid[i1][j1], c2 = cellid[i2][j2];
  if (b1 > b2) {swap (b1,b2); swap(c1,c2);}
  int r1 = G1[b1].regid[c1], r2 = G1[b2].regid[c2];
  pii p = make_pair(b1, b2);
  add_edge(G2[p], r1, r2);
  G2[p].nodesize[r1] = G1[b1].regsize[r1];
  G2[p].nodesize[r2] = G1[b2].regsize[r2];
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);

  cin >> N;
  for (int i=1; i<=N; i++)
    for (int j=1; j<=N; j++) {
      cin >> B[i][j];
      cellid[i][j] = i*N+j;
    }
  for (int i=1; i<=N; i++)
    for (int j=1; j<=N; j++) {
      add_edge(G1[B[i][j]],cellid[i][j],cellid[i][j]);
      if (i<N && B[i+1][j] == B[i][j]) add_edge(G1[B[i][j]], cellid[i][j], cellid[i+1][j]);
      if (j<N && B[i][j+1] == B[i][j]) add_edge(G1[B[i][j]], cellid[i][j], cellid[i][j+1]);
    }

  int answer1 = 0;
  for (auto &p : G1) answer1 = max(answer1,largest_region(p.second));
  for (int i=1; i<=N; i++)
    for (int j=1; j<=N; j++) {
      if (i<N && B[i+1][j] != B[i][j]) add_G2_edge(i,j,i+1,j);
      if (j<N && B[i][j+1] != B[i][j]) add_G2_edge(i,j,i,j+1);
    }
  int answer2 = 0;
  for (auto &p : G2) answer2 = max(answer2, largest_region(p.second));

  cout << answer1 << "\n" << answer2 << "\n";
  return 0;
}


