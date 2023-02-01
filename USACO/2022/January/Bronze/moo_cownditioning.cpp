#include <iostream>
using namespace std; 

int n, m;
int stall[100]; // stall[i] = the maximum cooling requirement for stall i
int ac[10][4]; // ac[i] = {a_i, b_i, p_i, m_i}

#define FOR(x) for (x = 0; x <= 1; ++x)

int b[10]; // b[i] = is ac i on or off?
int ans = 1e9;

bool works() { // check if current configuration of ac states works
    int tally[100]{}; // tally up cooling power for each stall
    for (int i = 0; i < m; ++i) {
        for (int j = ac[i][0]; j <= ac[i][1]; ++j) tally[j] += b[i] * ac[i][2]; 
    }
    for (int i = 0; i < 100; ++i) if (tally[i] < stall[i]) return 0; 
    return 1; 
}

int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin >> n >> m; 
    for (int i = 0; i < n; ++i) {
        int s, t, c; 
        cin >> s >> t >> c, --s, --t; 
        for (int j = s; j <= t; ++j) stall[j] = max(stall[j], c); 
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < 4; ++j) cin >> ac[i][j]; 
        --ac[i][0], --ac[i][1];
    }

    FOR(b[0]) FOR(b[1]) FOR(b[2]) FOR(b[3]) FOR(b[4]) FOR(b[5])
    FOR(b[6]) FOR(b[7]) FOR(b[8]) FOR(b[9]) if (works()) {
        int cost = 0;
        for (int i = 0; i < 10; ++i) cost += b[i] * ac[i][3];
        ans = min(ans, cost);
    }

    cout << ans << "\n";
}
