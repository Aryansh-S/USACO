#include <iostream>
#include <string> 
using namespace std; 

int main() {
  cin.tie(0)->sync_with_stdio(0); 
  int n, ans = 0; 
  string s; 
  cin >> n >> s;
  
  for (int i = n - 1; i > 0; i -= 2) {
    bool block = (s[i] != s[i - 1]); 
    bool odd_case = s[i] == 'G' && (ans & 1); 
    bool even_case = s[i] == 'H' && !(ans & 1); 
    ans += block && (odd_case || even_case); 
  }
  
  cout << ans << "\n";
}
