#include <iostream>
using namespace std;

using ll = long long; 
ll n,a[5005][5005],s[5005];

int main(){
    cin >> n; for(int i=1; i<=n; ++i) cin >> a[i][i], s[i]=s[i-1]+a[i][i];
    for(int i=1; i<=n; ++i) for(int j=1; i+j<=n; ++j) a[i+j][j]=s[i+j]-s[j-1]-min(a[i+j][j+1],a[i+j-1][j]);
    cout << a[n][1] << " " << "\n";
    return 0;
}
