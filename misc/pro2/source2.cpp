#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define f first
#define s second

#define problemname "swap"
#define MAXN 100000
#define MAXM 100
#define MAXK 1000000000

int n,m,k;

struct step{int a, b;};
step mover[MAXM];
int act[MAXN];
int ans[MAXN];


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);

	cin >> n >> m >> k;

	for(int i=0; i<m; i++){
		cin >> mover[i].a >> mover[i].b;
		mover[i].a--; mover[i].b--;
	}

	for(int i=0; i<n; i++){
		int i1=i;
		for(int j=0; j<m; j++){
			if(i1>=mover[j].a && i1<=mover[j].b){
				i1=abs(mover[j].a+mover[j].b-i1);
			}
		}
		act[i]=i1;
	}

	for(int i=0; i<n; i++){
		int i1=i; int k1=k;
		for(int j=1; j<=k1; j++){
			i1=act[i1];
			if(i1==i) {k1=j+k1%j;}
		}
		//cout << i1+1 << "\n";
		ans[i1]=i+1;

	}
	for (int i=0; i<n; i++) cout << ans[i] << "\n";
	return 0;
}
