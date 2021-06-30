struct mi { // with ll for best results
  typedef decay<decltype(MOD)>::type T; T val; 
  explicit operator T() const { return val; }
  mi() { val = 0; }
  mi(ll v) { val = (-MOD <= v && v <= MOD) ? v : v % MOD; if (val < 0) val += MOD; }
  friend bool operator==(const mi& a, const mi& b) { return a.val == b.val; }
  friend bool operator!=(const mi& a, const mi& b) { return !(a == b); }
  friend bool operator<(const mi& a, const mi& b) { return a.val < b.val; }
  friend bool operator>(const mi& a, const mi& b) { return a.val > b.val; }
  friend istream& operator>>(istream& is, mi& a) { is >> a.val; a = mi(a.val); return is; }
  friend ostream& operator<<(ostream& os, const mi& a) { return os << a.val; }
  mi operator-() const { return mi(-val); }
  mi& operator+=(const mi& m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
  mi& operator-=(const mi& m) { if ((val -= m.val) < 0) val += MOD; return *this; }
  mi& operator++() { return *this += 1; }
  mi& operator--() { return *this -= 1; }
  friend mi operator+(mi a, const mi& b) { return a += b; }
  friend mi operator-(mi a, const mi& b) { return a -= b; }
  mi& operator*=(const mi& m) { val = (ll)val*m.val%MOD; return *this; }
  friend mi pow(mi a, ll p) {
    mi ans = 1; assert(p >= 0);
    for (; p; p /= 2, a *= a) if (p&1) ans *= a;
    return ans;
  }
  friend mi inv(const mi& a) { assert(!(a == 0)); return pow(a,MOD-2); }
  mi& operator/=(const mi& m) { return (*this) *= inv(m); }
  friend mi operator*(mi a, const mi& b) { return a *= b; }
  friend mi operator/(mi a, const mi& b) { return a /= b; }
};

// Extended Below:

template <int MOD, int RT> struct mint {
	static const int mod = MOD;
	static mint rt() { return RT; } // primitive root for FFT
	int v; explicit operator int() const { return v; } // don't silently convert to int
	mint() { v = 0; }
	mint(ll _v) { v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
		if (v < 0) v += MOD; }
	friend bool operator==(const mint& a, const mint& b) { 
		return a.v == b.v; }
	friend bool operator!=(const mint& a, const mint& b) { 
		return !(a == b); }
	friend bool operator<(const mint& a, const mint& b) { 
		return a.v < b.v; }
	friend void re(mint& a) { ll x; re(x); a = mint(x); }
	friend str ts(mint a) { return ts(a.v); }
   
	mint& operator+=(const mint& m) { 
		if ((v += m.v) >= MOD) v -= MOD; 
		return *this; }
	mint& operator-=(const mint& m) { 
		if ((v -= m.v) < 0) v += MOD; 
		return *this; }
	mint& operator*=(const mint& m) { 
		v = (ll)v*m.v%MOD; return *this; }
	mint& operator/=(const mint& m) { return (*this) *= inv(m); }
	friend mint pow(mint a, ll p) {
		mint ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend mint inv(const mint& a) { assert(a.v != 0); 
		return pow(a,MOD-2); }
		
	mint operator-() const { return mint(-v); }
	mint& operator++() { return *this += 1; }
	mint& operator--() { return *this -= 1; }
	friend mint operator+(mint a, const mint& b) { return a += b; }
	friend mint operator-(mint a, const mint& b) { return a -= b; }
	friend mint operator*(mint a, const mint& b) { return a *= b; }
	friend mint operator/(mint a, const mint& b) { return a /= b; }
};
 
using mi = mint<MOD,3>;
