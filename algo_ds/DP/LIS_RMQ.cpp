#include <bits/stdc++.h>
using namespace std;

struct RMQ {
	int n; vector<int> seg;
	const int ID = 0; // at minimum, the length of a subsequence is 0 (-INF won't work here for example)
	void init(int n0) { n = n0; seg.assign(2 * n, ID); }
	void upd(int p, int v) {
		seg[p += n] = v;
		for(p /= 2; p; p /= 2) seg[p] = max(seg[2 * p], seg[2 * p + 1]);
	}
	int qry(int l, int r) {
		int ql = ID, qr = ID;
		for(l += n, r += n + 1; l < r; l /= 2, r /= 2) {
			if(l & 1) ql = max(ql, seg[l++]);
			if(r & 1) qr = max(seg[--r], qr);
		}
		return max(ql, qr);
	}
} dp;

int n;
vector<int> v, cmp;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n; v.resize(n);
	for(int i = 0; i < n; ++i) cin >> v[i];

	// define coordinate compression //
	cmp = v;
	sort(begin(cmp), end(cmp));
	cmp.erase(unique(begin(cmp), end(cmp)), end(cmp));
	auto cid = [&](int x) { return lower_bound(begin(cmp), end(cmp), x) - begin(cmp); };
	// cid gives compressed id //

	dp.init(size(cmp));
	dp.upd(cid(v[0]), 1); // base case: a[0] has LIS 1
	for(int i = 1; i < n; ++i) dp.upd(cid(v[i]), dp.qry(0, cid(v[i]) - 1) + 1);
	cout << dp.qry(0, size(cmp) - 1) << "\n";
}
