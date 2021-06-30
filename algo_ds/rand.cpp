inline namespace rand_ {
		mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
		inline int RAND(int l = -INF, int r = INF) { uniform_int_distribution<int> unifd(l,r); return unifd(mt); }
}
