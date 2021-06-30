#include <bits/stdc++.h>
using namespace std; 

// some compilers (including g++ apparently) don't allow y1 as an int when you use bits (useful for mathy problems)
// , since it's defined in cmath as a different symbol
// luckily there's an easy fix:

#define y1 _y1

// and that's it! the preprocessor will now replace y1 instances with _y1, which is not defined in bits and thus perfect as a variable
// after this define, you can continue using y1 like normal

int y1; 

int main() {
  assert(y1 == 0); 
  cout << "works!\n"; 
}
