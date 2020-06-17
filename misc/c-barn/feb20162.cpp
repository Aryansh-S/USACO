#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define f first
#define s second

#define problemname "cbarn"

int f(int x, int y){
	if(x==y) return y;
	return x%y;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);
	int n;
	cin >> n;
	int r[n+1];
	for(int i=1; i<=n; i++) cin >> r[i];
	vector <int> dist;
	for(int i=1; i<=n; i++){
		int sum=0;
		for(int j=0; j<n; j++) sum+=r[f(i+j,n)]*j;
		dist.pb(sum);
	}
	sort(dist.begin(), dist.end());
	cout << dist[0] << "\n";
	return 0;
}
