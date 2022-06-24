#include <bits/stdc++.h>
using namespace std; 

int N;
string cow[] { "Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue" };
vector<pair<string, string>> match;

bool adj(string cow1, string cow2) {
	int i, j; 
	for (i = 0; i < 8; ++i) if(cow[i] == cow1) break;
	for (j = 0; j < 8; ++j) if(cow[j] == cow2) break;
	return abs(i - j) == 1;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("lineup.in", "r", stdin); 
	freopen("lineup.out", "w", stdout);

	cin >> N; 
	for (int i = 0; i < N; ++i) {
		string cow1, cow2; 
		cin >> cow1; 
		for (int j = 0; j < 5; ++j) cin >> cow2; 
		match.emplace_back(cow1, cow2);
	}

	sort(begin(cow), end(cow)); 
	do {
		bool works = 1; // assume it works at first
		for (auto p: match) if (!adj(p.first, p.second)) works = 0; // challenge assumption 
		if (works) {
			for (auto s: cow) cout << s << "\n";
			exit(0);
		}
	} while (next_permutation(begin(cow), end(cow)));
}
