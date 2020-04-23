#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define f first
#define s second

#define problemname "paint"

int a,b,c,d,ans;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);

	cin >> a >> b >> c >> d;
	if(a<c && d<b) {ans=b-a;}
	if(a>c && b<d) {ans=d-c;}
	if(c>a && c<b && d>b) {ans=d-a;}
	if(a>c && a<d && b>d) {ans=b-c;}
	if(b<c) {ans=b-a+d-c;}
	if(d<a) {ans=b-a+d-c;}
	if(b==c) {ans=d-a;}
	if(d==a) {ans=b-c;}

	if(a==c && b<d) {ans=d-c;}
	if(a==c && b>d) {ans=d-b;}

	if(b==d && c>a) {ans=d-a;}
	if(b==d && c<a) {ans=d-c;}

	if(a==c && b==d) {ans=b-a;}
	cout << ans << "\n";
	return 0;
}
