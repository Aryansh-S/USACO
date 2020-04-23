#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define f first
#define s second

#define problemname "berries"

int n,k,ans;
vector<int> picks;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);

	cin >> n >> k;
	for(int i=0; i<n; i++) {int t; cin >> t; picks.pb(t);}
	sort(picks.begin(), picks.end(), greater<int> ());
	picks.erase(picks.begin()+k, picks.end());
	while(1){
		bool b=1;
		for(int i=0; i<picks.size(); i++){
			if(min(picks[i]/2,picks[i]-picks[i]/2)>*(picks.end()-1)){
				picks.erase(picks.end()-1);
				picks.pb(picks[i]/2); picks.pb(picks[i]-picks[i]/2);
				picks.erase(picks.begin()+i);
				sort(picks.begin(), picks.end()); b=0;
			}
		}
		if(b) break;
	}

	for(int i=0; i<k/2; i++) ans+=picks[i];
	cout << ans << "\n";

	return 0;
}
