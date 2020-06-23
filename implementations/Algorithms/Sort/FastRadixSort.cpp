#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define all(v) begin(v),end(v)

//level: gold (rare but can help when sorting is the bottleneck)

//objective: design a linear-time efficient, concise implementation of radix sort based on most significant bit

struct radix{const int bit;radix(int off):bit(off){}bool operator()(int val)const{return (bit==31)?(val<0):(!(val&(1<<bit)));}}; //concise linear radix sort
void rsort(int*l,int*r,int msb=31){
    if(l!=r&&msb>=0){int*m=partition(l,r,radix(msb)); msb--;rsort(l,m,msb),rsort(m,r,msb);}
}void rsort(vi::iterator l, vi::iterator r, int msb=31){
    if(l!=r&&msb>=0){vi::iterator m=partition(l,r,radix(msb)); msb--;rsort(l,m,msb),rsort(m,r,msb);}
}

int main(){
  vi v={10,-11,9,3,4,5,1,6,2,2,-100};
  rsort(all(v)); for(int a:v) cout << a << " "; cout << "\n";
  return 0;
}
