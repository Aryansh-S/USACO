#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define f first
#define s second

#define problemname "balancing"

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);
	int N,B;
	cin >> N >> B;
	int arr[N][2];
	for(int i=0; i<N; i++) cin >> arr[i][0] >> arr[i][1];
	vector <int> maxvec;

	for (int a=0; a<=B+1; a++){
		for(int b=0; b<=B+1; b++){
			int quad[]={0,0,0,0};
			for(int i=0; i<N; i++){
				if(arr[i][0]>a){
					if(arr[i][1]<b) quad[3]++;
					if(arr[i][1]>b) quad[0]++;
				}
				else{
					if(arr[i][1]>b) quad[1]++;
					if(arr[i][1]<b) quad[2]++;
				}
			}
			sort(quad, quad+4);
			maxvec.pb(quad[3]);
		}
	}
	sort(maxvec.begin(), maxvec.end());
	cout << maxvec[0] << "\n";
	return 0;
}

