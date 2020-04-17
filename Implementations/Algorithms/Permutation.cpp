#include <bits/stdc++.h>
using namespace std;
//level: advanced bronze (this has come up in the past but is rare)

//objective: find all O(n!) permutations of a given string 

//this can be done in two ways -- the std::next_permutation function and blatant recursion

void permute(string s, int it, array<char,s.size()> per={''}){ //call permute(s,0)
  //it is more convenient to deal with a char array 
  //int it stores the iteration
  if(it==n-1) {for(char c:per) cout << c; cout << "\n";} 
  for(int i=0; i<n; i++) {per[i]=s[it]; permute(s,it+1,per);}
}

int main(){
  cin.tie(0)->sync_with_stdio(0);
  string s;
  cin >> s;
  sort(begin(s),end(s)); //sort s lexicographically 
  cout << s << "\n"; //don't forget to print the first permutation
  while(next_permutation(begin(s),end(s))){ //this function returns true if there exists a higher lexicographical permutation
    //it also modifies s to become this higher lexicographical permutation if it exists
    //meaning that we can simply print s each time
    cout << s << "\n";
  }
  //the recursive implementation is given as a separate function above
  return 0;
}
