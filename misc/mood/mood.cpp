#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define f first
#define s second

#define problemname "mood"

#define MAXN 100000
int n, k, comp[MAXN+2], numincomp[MAXN+2], moodsum[MAXN+2];
bool mood[MAXN+2]; //holds actual 0/1 value
/*
make happy=1, sad=-1
comp gives the sibling component of a cow
numincomp gives the number of cows in a sibling component
moodsum gives the sum of all moods for a sibling component
*/

vector<int> adj[MAXN+2]; bool visited[MAXN+2]; int nxt; //floodfill

void dfs(int u, int fill){
	if(!visited[u]){
		visited[u]=1;
		comp[u]=fill; numincomp[fill]++;
		nxt=fill+1;
		for(auto el:adj[u]) dfs(el, fill);
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);

	cin >> n >> k;
	for(int i=0; i<n; i++) cin >> mood[i];
	for(int i=0; i<k; i++){
		int a,b;
		cin >> a >> b;
		adj[a-1].pb(b-1); adj[b-1].pb(a-1);
	}

	for(int i=0; i<n; i++) dfs(i, nxt);
	for(int i=0; i<n; i++) moodsum[comp[i]]+=(mood[i]?1:-1);

	for(

	bool b=1; //check if already repeat
	for(int i=0; i<nxt; i++) if(moodsum[i]!=numincomp[i] && moodsum[i]!=-numincomp[i]) b=0;
	if(b){cout << "...\n"; return 0;}

	for(int m=1; m<=59; m++){
		for(int i=0; i<n; i++){
			if(numincomp[comp[i]]!=1){
				if(moodsum[comp[i]]-(mood[i]?1:-1)>=0) mood[i]=1;
				else mood[i]=0;
			}
		}
		for(int i=0; i<nxt; i++) moodsum[i]=0;
		for(int i=0; i<n; i++) moodsum[comp[i]]+=(mood[i]?1:-1);
		bool b=1;
		for(int i=0; i<nxt; i++) if(moodsum[i]!=numincomp[i] && moodsum[i]!=-numincomp[i]) b=0;
		for(int i=0; i<n; i++) cout << mood[i] << " ";
		cout << "\n";
		if(b){cout << "...\n"; break;}
	}

	return 0;
}
