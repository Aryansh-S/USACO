#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define f first
#define s second

#define problemname "promote"

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);

	int a1, a2, b1, b2, c1, c2, d1, d2;
	cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2 >> d1 >> d2;
	int silver_pro, gold_pro, plat_pro;
	plat_pro=d2-d1;
	gold_pro=plat_pro+c2-c1;
	silver_pro=gold_pro+b2-b1;
	cout << silver_pro << "\n" << gold_pro << "\n" << plat_pro << "\n";

	return 0;
}
