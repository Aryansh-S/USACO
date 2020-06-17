#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <vector>
using namespace std;

#define problemname "citystate"

vector<int> contain;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);
    int n;
    cin >> n;
    map<pair<string, string>, int> m;
    for(int i=0; i<n; i++){
            pair <string, string> p;
            cin >> p.first >> p.second;
            p.first=p.first.substr(0,2);
            if(p.first!=p.second){
                                  if(m.find(p)==m.end()) m[p]=0;
                                  m[p]++;

            }
    }
    int ans=0;
    for(auto el:m){
             auto ell=el.first;
             swap(ell.first, ell.second);
             if(m.find(ell)!=m.end()) ans+=m[el.first]*m[ell];
    }
    ans/=2;
    cout << ans << "\n";
    return 0;
}

