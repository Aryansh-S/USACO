#include <bits/stdc++.h>
using namespace std;
//BIT is very easy to implement!

int bit[100];
void upd(int x, int v){for(;x<=100;x+=x&-x) bit[x]+=v;}
int sum(int r){int res=0; for(;r;r-=r&-r) res+=bit[r]; return res;}
int rsum(int l, int r){return sum(r)-sum(l-1);}

int main(){
    upd(1,10); 
    upd(2,20);
    cout << sum(2);
    return 0;
}
