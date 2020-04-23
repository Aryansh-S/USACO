#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define f first
#define s second

#define problemname "haybales"
#define maxn 100000
int n,q,loc[maxn],bale[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);

	cin >> n >> q;
	for(int i=0; i<n; i++) {cin >> loc[i]; bale[i]=i+1;}
	sort(loc,loc+n);

	for(int i=0; i<q; i++){
		int x,y; cin >> x >> y;
		int x1=upper_bound(loc,loc+n,x-1)-loc, y1=upper_bound(loc,loc+n,y)-loc;
		cout << bale[y1]-bale[x1] << "\n";
	}

	return 0;
}
