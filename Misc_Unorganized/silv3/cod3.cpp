#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <cmath>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define f first
#define s second

#define problemname "milkvisits"

int n, m;
string type, ans;
vector<int> adj[100001];
bool visited[100001];
char an='0';

void dfs(int u, int dest, bool sat, char c){
	if(!visited[u]){
		visited[u]=1;
		bool b=0;
		if(sat==1) {b=1;}
		else{if(type[u]==c){b=1;}}
		if(u==dest && b==1) {an='1';}
		for(auto el:adj[u]){dfs(el, dest, b, c);}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);
	cin >> n >> m;
	cin >> type;
	for(int i=0; i<n-1; i++){
		int x,y;
		cin >> x >> y;
		adj[x-1].pb(y-1);
		adj[y-1].pb(x-1);
	}
	for(int i=0; i<m; i++){
		int A,B; char c;
		cin >> A >> B >> c;
		dfs(A-1, B-1, 0, c);
		ans+=an;
		for(int x=0; x<n; x++){
			visited[x]=0;
		}
		an='0';
	}
	cout << ans << "\n";
	return 0;
}
