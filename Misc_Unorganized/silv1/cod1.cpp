#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <cmath>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define f first
#define s second

#define problemname "moobuzz"

int n, cnt; double k;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);
	cin >> n;
	k=floor(n*15.0/8.0);
	for(int i=k-15; i<=k+15; i++){
		cnt=i-(i/3+i/5-i/15);
		if(cnt==n){cout << i << "\n"; break;}
	}
	return 0;
}


