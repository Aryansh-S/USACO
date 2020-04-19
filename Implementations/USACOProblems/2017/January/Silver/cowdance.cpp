#include <bits/stdc++.h>
using namespace std;
//level: silver 

//a simple exercise in priority queues as min heaps along with binary searching for the answer

#define minpq priority_queue<int, vector<int>, greater<int> >

//query when next cow is done, and if this happens at time T, delete this cow, and then insert
//the next cow with time t+T
//this should store end times

const int SZ=1e4; 
int n, tmax, d[SZ+5]; 
#define pname "cowdance"

int check(int k){
    minpq cows;
    for(int i=0; i<k; i++) cows.push(d[i]);
    int nxt=k; //k to n-1
    while(cows.size()!=1){
        int temp=cows.top(); cows.pop(); 
        if(nxt<=n-1) cows.push(temp+d[nxt]);
        nxt++;
    }
    return cows.top(); 
}

int main(){
    cin.tie(0)->sync_with_stdio(0); 
    if(fopen(pname ".in","r",stdin)){freopen(pname ".in","r",stdin); freopen(pname ".out","w",stdout);}
    cin >> n >> tmax; 
    for(int i=0; i<n; i++) cin >> d[i];
    int l=0,r=n-1; int ans;
    while(l<=r){
        int m=l+(r-l)/2;
        if(check(m)==tmax){ans=m; break;}
        if(check(m)<tmax){if(check(m-1)>tmax){ans=m; break;} else r=m-1;}
        else{l=m+1;} //monotonically decreasing
    }
    cout << ans << "\n";
    return 0;
}
