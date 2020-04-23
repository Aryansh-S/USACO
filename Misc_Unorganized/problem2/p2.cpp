#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define f first
#define s second

#define problemname "speeding"

int m,n, maxi;
vector < pair < int,int > > road, bessie;

int speedr(int mile){
	int sp=0;
	int miles=mile;
	for(int j=0; j<n; j++){
		miles-=road[j].f;
		if(miles<=0){sp=road[j].s; break;}
	}
	return sp;
}

int speedb(int mile){
	int sp=0;
	int miles=mile;
	for(int j=0; j<m; j++){
		miles-=bessie[j].f;
		if(miles<=0) {sp=bessie[j].s; break;}
	}
	return sp;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);
	cin >> m >> n;
	for(int i=0; i<n; i++) {int x,y; cin >> x >> y; road.pb(mp(x,y));}
	for(int i=0; i<m; i++) {int x,y; cin >> x >> y; bessie.pb(mp(x,y));}

	for(int i=1; i<=100; i++){
		maxi=max(maxi, speedb(i)-speedr(i));
		//cout << speedb(i)-speedr(i) << "\n";
	}
	cout << maxi << "\n";
	return 0;
}
