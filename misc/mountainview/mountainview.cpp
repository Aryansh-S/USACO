#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define f first
#define s second

#define problemname "mountains"
#define maxn 100000

struct pt{int x,y,c1,c2;}; pt mpt(int x, int y, int c1, int c2){pt ret; ret.x=x;ret.y=y;;ret.c1=c1;ret.c2=c2; return ret;}
int n,id[maxn]; pt pts[maxn];
bool comp(int a, int b){
	if(pts[a].c2==pts[b].c2) return pts[a].c1 > pts[b].c1;
	return pts[a].c2 < pts[b].c2;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);
	cin >> n;
	for(int i=0; i<n; i++){int x,y; cin >> x >> y; pts[i]=mpt(x,y,x+y,x-y); id[i]=i;}
	sort(id,id+n,comp);
	int mxpos = -1;
	int ans = 0;
	for(int i=0;i<n;i++)
		{
			if(pts[id[i]].c1 > mxpos)
			{
				ans++;
				mxpos = pts[id[i]].c1;
			}
		}
	cout << ans << "\n";
	return 0;
}
