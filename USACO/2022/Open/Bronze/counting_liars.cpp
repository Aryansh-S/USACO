#include <bits/stdc++.h>
using namespace std; 

int N; 
vector<pair<char, int>> cow;
vector<int> guess; 
int ans = 1000;

bool lying(int loc, pair<char, int> info) {
	if (info.first == 'L') return loc > info.second; 
	else return loc < info.second;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N; 
	for (int i = 0; i < N; ++i) {
		char dir; int loc; 
		cin >> dir >> loc; 
		cow.emplace_back(dir, loc);
		guess.emplace_back(loc);
	}
	for (int i: guess) {
		int tot = 0; 
		for (auto p: cow) tot += lying(i, p);
		ans = min(ans, tot);
	}
	cout << ans << "\n";
}
