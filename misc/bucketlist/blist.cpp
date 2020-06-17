#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define f first
#define s second

#define problemname "blist"

int n, buckets, scow, ecow;
bool st,en;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);

	cin >> n;
	int s[n], t[n], b[n];
	for(int i=0; i<n; i++) cin >> s[i] >> t[i] >> b[i];

	for(int i=1; i<=1000; i++){
		for(int j=0; j<n; j++){
			if(s[j]==i) {st=1; scow=j;}
			if(t[j]==i) {en=1; ecow=j;}
		}
		if(en){
			buckets+=b[ecow];
		}
		if(st){
			if(buckets>=b[scow]) buckets-=b[scow];
			if(buckets<b[scow]) buckets=0;
		}
		st=0; en=0;
	}
	cout << buckets << "\n";
	return 0;
}
