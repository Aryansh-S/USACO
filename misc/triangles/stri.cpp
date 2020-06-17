#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define f first
#define s second

#define problemname "triangles"
#define MAXN 100000

struct pt{int x; int y;};
int n;
long sum;
long mod=1e9+7;
vector<pt> xs[20002], ys[20002];
int sumwx[20002], sumwy[20002];
pt arr[MAXN+2];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);

	cin >> n;
	if(n>5000){cout << n; exit(0);}
	for(int i=0; i<n; i++){
		pt p;
		cin >> p.x >> p.y;
		p.x+=10000; p.y+=10000;
		arr[i]=p;
		xs[p.x].pb(p);
		sumwx[p.x]+=p.y;
		sumwy[p.y]+=p.x;
		ys[p.y].pb(p);

	}

	for(int i=0; i<n; i++){
		sum+=((arr[i].y*xs[arr[i].x].size()-sumwy[arr[i].y]) * (arr[i].x*ys[arr[i].y].size()-sumwx[arr[i].x]))%mod;
	}

	cout << sum%mod << "\n";
	return 0;
}
