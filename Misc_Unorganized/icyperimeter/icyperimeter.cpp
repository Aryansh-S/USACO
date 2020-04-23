#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define f first
#define s second

#define problemname "perimeter"

int N,R, region[1002][1002], area[1000000], perimeter[1000000]; char grid[1002][1002];
typedef pair<int,int> pii;

void visit(int i, int j, int r)
{
  stack<pii> to_visit;
  to_visit.push(make_pair(i,j));
  while (!to_visit.empty()) {
    pii current = to_visit.top();
    to_visit.pop();
    i = current.first; j = current.second;
    if (region[i][j]!=0 || grid[i][j]=='.') continue;
    region[i][j]=R;
    area[R]++;
    to_visit.push(mp(i-1,j));
    to_visit.push(make_pair(i+1,j));
    to_visit.push(make_pair(i,j-1));
    to_visit.push(make_pair(i,j+1));
  }
}

void find_perimeters(void){
  for (int i=1; i<=N; i++)
    for (int j=1; j<=N; j++) {
      int r = region[i][j];
      if (r == 0) continue;
      if (region[i-1][j]==0) perimeter[r]++;
      if (region[i+1][j]==0) perimeter[r]++;
      if (region[i][j-1]==0) perimeter[r]++;
      if (region[i][j+1]==0) perimeter[r]++;
    }
}

int main(){
	freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);
  cin >> N;
  string s;
  for(int i=0; i<N+2; i++) grid[0][i] = grid[N+1][i] = '.';
  for(int i=1; i<=N; i++) {
    grid[i][0] = grid[i][N+1] = '.';
    cin >> s;
    for(int j=1; j<=N; j++) grid[i][j] = s[j-1];
  }
  for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) if (grid[i][j] == '#' && region[i][j] == 0) visit(i,j,++R);
  find_perimeters();
  int best_a=0,best_p=0;
  for (int i=1; i<=R; i++)
    if(area[i] > best_a || (area[i] == best_a && perimeter[i] < best_p)) {
      best_a = area[i];
      best_p = perimeter[i];
    }
  cout << best_a << " " << best_p << "\n";
  return 0;
}
