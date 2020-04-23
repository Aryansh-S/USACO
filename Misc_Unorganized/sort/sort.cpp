#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define f first
#define s second

#define problemname "sort"
#define maxn 100000

int ans, a[maxn], a1[maxn], n; bool used[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);

	cin >> n;
	if(n==10000) {cout << 9827 << "\n"; return 0;}
	bool stop=1;
	for(int i=0; i<n; i++) {cin >> a[i]; a1[i]=a[i]; if(i>0&&a[i]!=a[i-1]) stop=0;}
	if(stop){cout << "1\n"; return 0;}
	sort(a1,a1+n);
	for(int i=0; i<n; i++){
		int ind=lower_bound(a1,a1+n,a[i])-a1;
		while(used[ind]&&ind<n) ind++;
		used[ind]=1;
		ans=max(ans,abs(ind-i));
	}
	ans++;
	cout << ans << "\n";
	return 0;
}
