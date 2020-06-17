#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define f first
#define s second

#define problemname "planting"

#define maxn 100000
int n,ans; vector<int> adj[maxn]; bool visit[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);

	cin >> n;
	for(int i=0; i<n-1; i++){int a,b; cin >> a >> b; adj[a-1].pb(b-1); adj[b-1].pb(a-1);}
	for(int i=0; i<n; i++) ans=(ans>adj[i].size())?ans:adj[i].size();
	ans++;
	cout << ans << "\n";
	//for(int i=0; i<n; i++) cout << grass[i] << "\n";
	return 0;
}
