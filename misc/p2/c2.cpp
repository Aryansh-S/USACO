#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define f first
#define s second

#define problemname "whereami"

string s;
int n; set<string> subs;

int main(){
	freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);

	cin >> n >> s;
	for(int i=1; i<=n; i++){
		for(int j=0; j<n; j++){
			if(j<=n-i){subs.insert(s.substr(j,i));}
		}
		if(subs.size()==n-i+1){cout << i << "\n"; break;}
		subs.clear();
	}
	return 0;
}
