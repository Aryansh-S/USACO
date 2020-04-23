#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;
#define pb push_back

map<ll, vector<ll>> adj;
vector<ll> ver, ord;
map<ll, bool> visited;

void dfs(ll u){
	if(!visited[u]){
		visited[u]=1;
		ord.pb(u);
		for(auto el:adj[u]) dfs(el);
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n;
	cin >> n;
	ver.resize(n);
	for(int i=0; i<n; i++){
		cin >> ver[i];
		adj[ver[i]]={};
		visited[ver[i]]=0;
	}
	for(auto i:ver){
		for(auto j:ver){
			if((!(i%3) && j==i/3) || j==2*i) adj[i].pb(j);
		}
	}
	for(auto i:ver){
		dfs(i);
		if(ord.size()==n){
			for(auto j:ord) cout << j << " ";
			cout << "\n";
			break;
		}
		for(auto &j:visited) visited.second=0;
		ord.clear();
	}
	return 0;
}
