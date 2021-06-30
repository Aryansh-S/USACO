#include <bits/stdc++.h>
using namespace std; 

int n, a[1 << 20], ans = -0x3f3f3f3f, dp; 
  //ans stores ans, dp stores max subarr sum ending at idx i (including i) 

int main() {
	cin.tie(0)->sync_with_stdio(0); 
	cin >> n; for(int i = 0; i < n; ++i) cin >> a[i]; 
	for(int i = 0; i < n; ++i) dp = max(dp, 0) + a[i], ans = max(ans, dp); 
	cout << ans << "\n"; 
}
