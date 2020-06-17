#include <iostream>
#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

#define problemname "moop"

int n,ids[100000],ans=1; pair<int,int> p[100000];
bool visited[100000];

void dfs(int v, int id){
  if(!visited[v]){
    visited[v]=1;
    ids[v]=id;
    for(int i=0; i<n; i++){
      if((p[v].first<=p[i].first && p[v].second<=p[i].second) || (p[v].first>=p[i].first && p[v].second>=p[i].second)) dfs(i,id);
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);
  cin >> n;
  for(int i=0; i<n; i++) cin >> p[i].first >> p[i].second;
  for(int i=0; i<n; i++) dfs(i,i);
  sort(ids,ids+n);
  for(int i=1; i<n; i++) if(ids[i-1]!=ids[i]) ans++;
  cout << ans << "\n";
  return 0;
}
