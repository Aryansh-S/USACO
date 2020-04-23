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

#define problemname "pairup"

int n,ans; vector<int> v;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);

	cin >> n;
	for(int i=0; i<n; i++){int a,b; cin >> a >> b; for(int j=0; j<a; j++) v.pb(b);}
	sort(v.begin(), v.end());
	for(int i=0; i<v.size()/2; i++) ans=max(ans,v[i]+v[v.size()-1-i]);
	cout << ans << "\n";

	return 0;
}
