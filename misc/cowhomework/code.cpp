#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define f first
#define s second

#define problemname "homework"

#define MAXN 100000
int n, a[MAXN+2]; //prefix sums 1-n
float score[MAXN+2];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);

	cin >> n;
	for(int i=1; i<=n; i++) {cin >> a[i]; a[i]+=a[i-1];}

	for(int k=1; k<=n-2; k++){
		int mini=a[k+1]-a[k];
		for(int i=k+1; i<=n; i++) mini=min(mini, a[i]-a[i-1]);
		score[k]=((float)a[n]-a[k]-mini)/((float)n-k-1);
	}

	float maxi=0;
	for(int k=1; k<=n-2; k++) maxi=(maxi>score[k])?maxi:score[k];
	for(int k=1; k<=n-2; k++) if(score[k]==maxi) cout << k << "\n";

	return 0;
}
