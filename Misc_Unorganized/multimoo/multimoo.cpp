#include <iostream>
#include <cstdio>
#include <vector>
#include <array>
#include <set>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define f first
#define s second

#define problemname "multimoo"
#define maxn 25

int a[maxn][maxn], n, ans1, ans2, maxcow;
set<int> launch;

void dfs(vector<int> v, array<array<bool,maxn>,maxn> visit, int px, int py, int currans, int currvisit){
	if(!visit[px][py]){
		visit[px][py]=1; currvisit++;
		bool b=0;
		for(int i=0; i<v.size(); i++){
			if(a[px+1][py]==v[i] || a[px-1][py]==v[i] || a[px][py+1]==v[i] || a[px][py-1]==v[i]) b=1;
		}
		if(v.size()==1 && b) if(a[px][py]==v[0]) currans++;
		if(v.size()==2 && b) if(a[px][py]==v[0] || a[px][py]==v[1]) currans++;
		if(px!=0) dfs(v,visit,px-1,py,currans,currvisit);
		if(px!=n-1) dfs(v,visit,px+1,py,currans,currvisit);
		if(py!=0) dfs(v,visit,px,py-1,currans,currvisit);
		if(py!=n-1) dfs(v,visit,px,py+1,currans,currvisit);

	}
	else if(currvisit==n*n){
		if(v.size()==1) ans1=max(ans1,currans);
		else ans2=max(ans2,currans);
		return;
	}
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);

	cin >> n;
	array<array<bool,maxn>, maxn> visitor={0};
	for(int i=0; i<n; i++) for(int j=0; j<n; j++) {cin >> a[i][j]; launch.insert(a[i][j]);}
	for(auto i:launch) {
		vector<int> temp; temp.pb(i);
		dfs(temp,visitor,0,0,0,0);
	}
	for(auto i:launch) for(auto j:launch) if(i!=j){
		vector<int> temp; temp.pb(i); temp.pb(j);
		dfs(temp,visitor,0,0,0,0);
	}
	cout << ans1 << "\n" << ans2 << "\n";

	return 0;
}
