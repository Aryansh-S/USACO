inline ll gcd(ll a, ll b) { return (a == 0 || b == 0) ? max(abs(a), abs(b)) : __gcd(a, b); }
inline ll lcm(ll a, ll b) { return (a == 0 || b == 0) ? 0 : a * b / gcd(a, b); }
