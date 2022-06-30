#include <iostream>
using namespace std;

// my original submission from back then with nothing changed; too lazy to deal with all the casework in this problem

#define problemname "buckets"

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);
    char a[10][10];
    int bi, bj, li, lj, ri, rj;
    for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                    cin >> a[i][j];
            }
    }
    
    for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                    if(a[i][j]=='B'){bi=i; bj=j;}
                    if(a[i][j]=='R'){ri=i; rj=j;}
                    if(a[i][j]=='L'){li=i; lj=j;}
            }
    }
    int cow=abs(li-bi)+abs(lj-bj)-1;
    
    if(li==bi && bi==ri){
              if( (rj>bj && rj<lj) || (rj>lj && rj<bj) ) {cow+=2;}
    }
    if(lj==bj && bj==rj){
              if( (ri>bi && ri<li) || (ri>li && ri<bi) ) {cow+=2;}
    }
    
    cout << cow << "\n";
    return 0;
}
