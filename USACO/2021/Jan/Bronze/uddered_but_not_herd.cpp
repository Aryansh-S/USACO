#include <bits/stdc++.h>
using namespace std; 

char pos[26]; // pos[i] gives the cowphabet position of the letter with index i
string s; 
int ans = 1; // start the cowphabet off once

inline int idx(char letter) {
	return letter - 'a'; 
	// converts letter to index from 0...25 
}

int main() {
	cin.tie(0)->sync_with_stdio(0); 

	for (int i = 0; i < 26; ++i) {
		char letter; 
		cin >> letter; 
		pos[idx(letter)] = i;
	}
	cin >> s; 

	int last_pos = 0;
	for (char letter: s) {
		ans += (pos[idx(letter)] <= last_pos); // restart cowphabet if new pos not after last pos
		last_pos = pos[idx(letter)];
	}

	cout << ans << "\n";
}
