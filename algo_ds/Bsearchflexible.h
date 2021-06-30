// first true
auto f1(auto lo, auto hi, auto&& f) {
	assert(f(hi) > f(lo)); // f must increase
	while(lo < hi) {
		auto mid = lo + (hi - lo) / 2; 
		f(mid) ? hi = mid : lo = mid + 1; 
	}
	return lo; 
}

// last true
auto l1(auto lo, auto hi, auto&& f) {
	assert(f(hi) < f(lo)); // f must decrease
	while(lo < hi) {
		auto mid = lo + (hi - lo + 1) / 2; 
		f(mid) ? lo = mid : hi = mid - 1; 
	}
	return lo; 
}


