#include <iostream>
#include <cstdio>
#include <utility>
#include <set>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define f first
#define s second

#define problemname "cereal"
#define maxn 100000
#define maxm 100000

int n,m,ans[maxn]; bool cereal[maxm]; pii prefs[maxn]; //prefs[i] are the prefs of cow i
set<int> s; //0 there, 1 taken

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);

	cin >> n >> m;
	for(int i=0; i<n; i++) cin >> prefs[i].f >> prefs[i].s;
	for(int i=n-1; i>=0; i--){
		if(!cereal[prefs[i].f]){cereal[prefs[i].f]=1; s.insert(prefs[i].f);}
		else if(!cereal[prefs[i].s]){cereal[prefs[i].s]=1; s.insert(prefs[i].s);}
		ans[i]=s.size();
	}
	for(int i=0; i<n; i++) cout << ans[i] << "\n";

	return 0;
}
