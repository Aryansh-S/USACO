#include <bits/stdc++.h>
using namespace std; 

// im being a brick >:(

set<int> reading; 

void solve(array<int, 2> tank, array<vector<int>, 2> bucket, int day) {
	if (day == 4) { // beyond Friday
		reading.emplace(tank[0]);
		return; 
	}
	if (day % 2) { // first barn
		for (int i = 0; i < size(bucket[0]); ++i) {
			// take bucket[0][i]
			auto new_tank = array { tank[0] - bucket[0][i], tank[1] + bucket[0][i] };

			auto new_bucket_0 = bucket[0], new_bucket_1 = bucket[1]; 
			new_bucket_0.erase(begin(new_bucket_0) + i);
			new_bucket_1.emplace_back(bucket[0][i]);
			auto new_bucket = array { new_bucket_0, new_bucket_1 };

			auto new_day = day + 1; 
			solve(new_tank, new_bucket, new_day);
		}
	}
	else { // second barn
		for (int i = 0; i < size(bucket[1]); ++i) {
			// take bucket[1][i]
			auto new_tank = array { tank[0] + bucket[1][i], tank[1] - bucket[1][i] };

			auto new_bucket_0 = bucket[0], new_bucket_1 = bucket[1]; 
			new_bucket_0.emplace_back(bucket[1][i]); 
			new_bucket_1.erase(begin(new_bucket_1) + i); 
			auto new_bucket = array { new_bucket_0, new_bucket_1 }; 

			auto new_day = day + 1; 
			solve(new_tank, new_bucket, new_day);
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0); 
	freopen("backforth.in", "r", stdin); 
	freopen("backforth.out", "w", stdout);
	
	vector<int> b1(10), b2(10); 
	for (int &t: b1) cin >> t; 
	for (int &t: b2) cin >> t; 

	solve({1000, 1000}, {b1, b2}, 0);
	cout << size(reading) << "\n";
}
