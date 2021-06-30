// mo's offline sqrt decomp made easy and intuitive (see https://cp-algorithms.com/data_structures/sqrt_decomposition.html for algo)
// to use, simply emplace_back queries into qrys; create your ds and write the init_ds, ins, ers, and curr_ans functions; and call solve

// O(sqrt(N) * (N + Q) * DS), where O(DS) is the complexity for ins/del in the data structure

#include <bits/stdc++.h>
using namespace std; 

const int block = 316; // approx sqrt(1e5), best to declare as a const int

struct qry {
	int l, r, i, f, s; 
	qry(int l0, int r0, int i0) : l(l0), r(r0), i(i0), f(l / block), s(f & 1 ? -r : r) {}
	bool operator<(qry q) const { return pair(f, s) < pair(q.f, q.s); }
};
vector<qry> qrys;

auto solve(auto init_ds, auto ins, auto ers, auto curr_ans) {
	vector<int> ans(size(qrys));
	sort(begin(qrys), end(qrys));
	init_ds();
	int l = 0, r = -1; 
	for(qry q: qrys) {
		while(l > q.l) ins(--l); 
		while(r < q.r) ins(++r); 
		while(l < q.l) ers(l++); 
		while(r > q.r) ers(r--); 
		ans[q.i] = curr_ans();
	}
	return ans;
}

// for demonstration, consider the very simple example of range sum; for this, our data structure is a single int, which stores the sum
int sum; 

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, q; cin >> n >> q;
	vector<int> v(n); 
	for(int &t: v) cin >> t; 
	
	// fill in queries and write functions
	for(int i = 0; i < q; ++i) { int l, r; cin >> l >> r; qrys.emplace_back(l, r, i); }
	auto init_ds = [&]() {}; // don't need to do anything here (already initialized to 0, as desired)
	auto ins = [&](int i) { sum += v[i]; }; // update if inserting the element at the i-th index of v
	auto ers = [&](int i) { sum -= v[i]; }; // update if erasing the element at the i-th index of v
	auto curr_ans = [&]() { return sum; }; // give what the current answer is
	
	// answer and print queries
	auto ans = solve(init_ds, ins, ers, curr_ans); 
	for(int t: ans) cout << t << "\n";
}
