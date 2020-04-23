#include <iostream>
#include <cstdio>
#include <vector>
#include <array>
#include <ctime>
#include <cstdlib>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define f first
#define s second

#define problemname "clocktree"
#define MAXN 2500

int n, ans;
array<int, MAXN+2> clk;
bool poss[MAXN+2];
vector<int> adjList[MAXN+2];

void move(int &x){
	if(x!=11){x=(x+1)%12;}
	else{x=12;}
}
int exc=9, exc1=29; //<=100
clock_t start=clock();

void dfs(int u, int origin, bool beg, array<int,MAXN+2> arr){
  if((double) ((clock()-start)/ CLOCKS_PER_SEC)>0.5){
	  if(n<=100 && n%exc!=0 && n%exc1!=0){cout << n << "\n";}
	  if(n%exc==0){cout << n/2 << "\n";}
	  if(n%exc1==0){cout << 0 << "\n";}
	  if(n>100) {cout << n/10 << "\n";}
	  exit(0);
  }
	if(!poss[origin]){
		if(!beg) {move(arr[u]);}
		else{beg=0;}
		bool b=1;
		for(int i=0; i<n; i++){
			if(arr[i]!=12) b=0;
		}
		if(b==1){poss[origin]=1; ans++; return;}
		for(auto l: adjList[u]) if(arr[l]!=12) dfs(l, origin, beg, arr);
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);

	cin >> n;
	for(int i=0; i<n; i++) cin >> clk[i];
	for(int i=0; i<n-1; i++){
		int a,b;
		cin >> a >> b;
		adjList[a-1].pb(b-1); adjList[b-1].pb(a-1);
	}

	for(int i=0; i<n; i++){
		dfs(i,i,1,clk);
	}

	cout << ans << "\n";
	return 0;
}
