#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#define pb push_back

#define problemname "badmilk"

int main(){
	  ios_base::sync_with_stdio(0); cin.tie(0);
	  freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);
      int n,m,d,s;
      cin >> n >> m >> d >> s;
      int a[d][3];
      int b[s][2];
      int mi[51];
      int max  = 0;
      for(int i = 0; i < 51; i++){
            mi[i] = 0;
      }
      for(int i = 0; i < d; i++){
            cin >> a[i][0] >> a[i][1] >> a[i][2];
      }
      for(int i = 0; i < s; i++){
            cin >> b[i][0] >> b[i][1];
      }

      for(int i = 0; i < s; i++){
            for(int j = 0; j < d; j++){
                  if(b[i][0] == a[j][0] && b[i][1] > a[j][2]){
                        mi[a[j][1]]++;
                  }
            }
      }
      for(int i = 1; i < 51; i++){
            int sum  = 0;
            if(mi[i] == s){
                  for(int j = 0; j < d;j++){
                        if(a[j][1] == i){
                              sum++;
                        }
                  }
            }
            if(sum > max){
                  max = sum;
            }
      }
      cout << max << "\n";
}

