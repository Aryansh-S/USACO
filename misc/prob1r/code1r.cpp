#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

#define pb push_back

#define problemname "lineup"

struct two {int f; int s;};
map<string, int> m;
two p[9];
string c1,c2,waste,ans[8];
int n, used[8]; // 1<=n<=7

int main(){
	m["Beatrice"]=0; m["Belinda"]=1; m["Bella"]=2; m["Bessie"]=3; m["Betsy"]=4; m["Blue"]=5;
	m["Buttercup"]=6; m["Sue"]=7;
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);

	cin >> n;
	for(int i=0; i<n; i++){
		cin >> c1 >> waste >> waste >> waste >> waste >> c2;
		p[i].f=m[c1]; p[i].s=m[c2];
	}



	for(int i=0; i<8; i++){
		cout << ans[i] << "\n";
	}
	return 0;
}
