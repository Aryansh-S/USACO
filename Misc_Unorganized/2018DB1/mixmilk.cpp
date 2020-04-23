#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define f first
#define s second

#define problemname "mixmilk"

struct bucket{int m, c;};
bucket b[3];

void pour(bucket &x, bucket &y){
	if(x.m<y.c-y.m){
		y.m+=x.m;
		x.m=0;
	}
	else{
		x.m-=y.c-y.m;
		y.m=y.c;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);

	for(int i=0; i<3; i++){
		cin >> b[i].m >> b[i].c;
	}

	for(int i=0; i<33; i++){
		pour(b[0], b[1]);
		pour(b[1], b[2]);
		pour(b[2], b[0]);
	}
	pour(b[0], b[1]);

	for(int i=0; i<3; i++){cout << b[i].m << "\n";}
	return 0;
}
