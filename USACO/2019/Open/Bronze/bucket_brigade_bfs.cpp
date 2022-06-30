#include <bits/stdc++.h>
using namespace std; 

// bfs is overkill but straightforward. screw casework

char g[10][10];
bool vis[10][10];

bool can_visit(int i, int j) {
	if (i < 0 || i >= 10 || j < 0 || j >= 10) return 0; 
	return !vis[i][j] && g[i][j] != 'R';
}

int main() {
	cin.tie(0)->sync_with_stdio(0); 
	freopen("buckets.in", "r", stdin); 
	freopen("buckets.out", "w", stdout); 

	int i0, j0; // start pos for bfs
	for (int i = 0; i < 10; ++i) for (int j = 0; j < 10; ++j) {
		cin >> g[i][j]; 
		if (g[i][j] == 'L') i0 = i, j0 = j;
	}

	queue<array<int, 3>> bfs; // i, j, dist
	bfs.push(array{i0, j0, 0}); 
	while(size(bfs)) {
		auto cell = bfs.front(); 
		bfs.pop(); 
		vis[cell[0]][cell[1]] = 1; 
		if (g[cell[0]][cell[1]] == 'B') {
			cout << cell[2] - 1 << "\n"; // subtract 1 because shortest distance is 1 more than # of cows needed
			exit(0); 
		}
		for (int di: {-1, 0, 1}) for (int dj: {-1, 0, 1}) if (abs(di + dj) == 1)
			if (can_visit(cell[0] + di, cell[1] + dj))
				bfs.push(array{cell[0] + di, cell[1] + dj, cell[2] + 1});
	}
}
