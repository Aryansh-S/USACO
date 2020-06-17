#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define f first
#define s second

#define problemname "pails"

int x,y,m,ans;

//milkpails, c-barn

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);

	cin >> x >> y >> m;

	for(int ix=0; ix<=m/x; ix++){
		for(int iy=0; iy<=m/y; iy++){
			if(x*ix+y*iy<=m) ans=max(ans,x*ix+y*iy);
		}
	}

	cout << ans << "\n";
	return 0;
}
