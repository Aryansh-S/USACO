#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define f first
#define s second

#define problemname "lemonade"
#define maxn 100000

int n, a[maxn], ans;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);

	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i];
	sort(a,a+n,greater<int>());
	for(int i=0; i<n; i++){
		if(a[i]>=ans) ans++;
		else break;
	}
	cout << ans << "\n";

	return 0;
}
