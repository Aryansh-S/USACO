#include <iostream>
#include <string>
using namespace std;

#define sz(s) (int)size(s)

int solve(string s) {
    int ans = 1e9; 
    if (sz(s) == 1 || sz(s) == 2) return -1; 
    for (int i = 1; i < sz(s) - 1; ++i) 
        if (s[i] == 'O') ans = min(ans, sz(s) - 3 + (s[i - 1] != 'M') + (s[i + 1] != 'O')); 
    return (ans == 1e9) ? -1 : ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0); 

    int q; 
    cin >> q; 
    while (q--) {
        string s; 
        cin >> s; 
        cout << solve(s) << "\n";
    }
}
