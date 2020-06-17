#include <iostream>
#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define f first
#define s second

#define problemname "socdist"
#define maxn 100000
#define maxm 100000

int n,m,d; pii loc[maxm];

struct comp{
	bool operator()(const pii&a, const int &b){return (a.s < b);}
	bool operator()(const int&a,const pii&b){return (a < b.s);}
};

bool test(int mid){ //try placing with minimum distance mid
	int pos=loc[0].f, ctr=1;
	while(ctr!=n){ //we need to place m cows
		if(lower_bound(loc,loc+m,pos+mid,comp())-loc!=m){
			if((*lower_bound(loc,loc+m,pos+mid,comp())).f>pos+mid) pos=(*lower_bound(loc,loc+m,pos+mid,comp())).f;
			else pos=pos+mid;
		}
		else return 0;
		ctr++;
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);

	cin >> n >> m;
	for(int i=0; i<m; i++){int a,b; cin >> a >> b; loc[i]=mp(a,b);}
	sort(loc,loc+m); //binary search for d
	int left=loc[0].f,right=loc[m-1].s;
	while(left<right){
		int mid=(left+right)/2;
		if(test(mid)){d=max(d,mid); left=mid+1;}
		else right=mid;
	}
	cout << d << "\n";

	return 0;
}
