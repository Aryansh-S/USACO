#include <bits/stdc++.h>
using namespace std; 

int N; 
int pts1, pts2, pts3;
int has1[3], has2[3], has3[3];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("shell.in", "r", stdin); 
	freopen("shell.out", "w", stdout);
  
	has1[0] = 1, has2[1] = 1, has3[2] = 1; 
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int a, b, g; 
		cin >> a >> b >> g; 
		--a, --b, --g; // zero index
		swap(has1[a], has1[b]); 
		swap(has2[a], has2[b]); 
		swap(has3[a], has3[b]); 
		if(has1[g] == 1) ++pts1; 
		if(has2[g] == 1) ++pts2;
		if(has3[g] == 1) ++pts3;
	}
	cout << max({pts1, pts2, pts3}) << "\n";
}
