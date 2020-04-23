#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define f first
#define s second

#define problemname "leftout"

int n; bool a[1000][1000];

void fliprow(int r){for(int i=0; i<n; i++) a[r][i]=!a[r][i];}
void flipcol(int c){for(int i=0; i<n; i++) a[i][c]=!a[i][c];}
bool rowxor(int r1, int r2){
	bool comp=a[r1][0]^a[r1][0], yay=1;
	for(int i=0; i<n; i++) if(a[r1][i]^a[r2][i]!=comp) yay=0;
	return yay;
}
bool colxor(int c1, int c2){
	bool comp=a[c1][0]^a[c2][0], yay=1;
	for(int i=0; i<n; i++) if(a[i][c1]^a[i][c2]!=comp) yay=0;
	return yay;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);

	cin >> n;
	for(int i=0; i<n; i++) for(int j=0; j<n; j++) {char c; cin >> c; a[i][j]=(c=='R')?1:0;}


	return 0;
}
