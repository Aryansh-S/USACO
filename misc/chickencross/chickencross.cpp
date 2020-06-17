#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define f first
#define s second

#define problemname "helpcross"

multiset<int> chickens;
vector< pair<int, int> > cows;
int c, n, total, x, y;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);
	cin >> c >> n;
	for (int i=0; i<c; i++) {cin >> x; chickens.insert(x);}
	for (int i=0; i<n; i++) {cin >> x >> y; cows.pb(mp(y,x));}
	sort(cows.begin(), cows.end());
	for(int i=0; i<n; i++){
		auto chicken=chickens.lower_bound(cows[i].second);
		if(chicken!=chickens.end() && *chicken<=cows[i].first){total++; chickens.erase(chicken);}
	}
	cout << total << "\n";
	return 0;
}
