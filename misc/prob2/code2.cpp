#include <iostream>
#include <cstdio>
#include <string>
#include <set>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define f first
#define s second

#define problemname "whereami"

string s;
int n;
set<string> subs;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);

	cin >> n >> s;

	//there are n-i+1 i-letter substrings
	for(int i=1; i<=n; i++){ //sizes of substrings
		for(int j=0; j<n; j++){ //goes over characters
			if(j<=n-i){subs.insert(s.substr(j,i));}
		}
		if(subs.size()==n-i+1){cout << i << "\n"; break;}
		subs.clear();
	}
	return 0;
}
