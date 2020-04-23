#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#define pb push_back

#define problemname "speeding"

int main(){
	  ios_base::sync_with_stdio(0); cin.tie(0);
      freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);
      int n,m;
      cin >> n >> m;
      int a[n][2];
      int b[m][2];
      for(int i = 0; i < n; i++){
            cin >> a[i][0] >> a[i][1];
      }
      for(int i = 0; i < m; i++){
            cin >> b[i][0] >> b[i][1];
      }
      int max = 0;
      int i,j = 0;
      while(i < n && j < m ){
            //cout << a[i][1] << b[j][1];
            if((b[j][1] - a[i][1]) > max){
                  max = b[j][1] - a[i][1];
            }
            a[i][0]--;
            b[j][0]--;
            if(a[i][0] == 0){
                  i++;
            }
            if(b[j][0] == 0){
                  j++;
            }

      }
      cout << max << "\n";
}
