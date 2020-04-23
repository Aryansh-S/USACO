#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define f first
#define s second

#define problemname "gymnastics"

map<int,int> a[12];
int ans, n, k, num;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);

	cin >> k >> n;
	for(int i=0; i<k; i++){
		for(int j=0; j<n; j++){
			cin >> num;
			a[i][num]=j;
		}
	}

	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(i!=j){
				bool b=1;
				for(int l=0; l<k; l++){
					if(a[l][i]<=a[l][j]) {b=0;}
				}
				if(b) {ans++;}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
