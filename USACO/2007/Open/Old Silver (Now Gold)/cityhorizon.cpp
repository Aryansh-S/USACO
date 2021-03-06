#include <bits/stdc++.h>
using namespace std;

//level: advanced silver, basic gold
//source: https://contest.usaco.org/OPEN07.htm

typedef long long ll; 

map<ll,vector<ll>> m; //map x to height + if start, - if end
//this map m is built by extending difference array logic to maps
int n; 
multiset<ll,greater<ll> > H; //keep heights running so far
ll ans; ll prevmax, currmax, prevstart, prevend; 

//we could use line sweep if we wanted to, but this solution is a slick alternative using the notion of difference arrays!

int main(){
    cin >> n; 
    for(int i=0; i<n; i++){
        ll a,b,h; cin >> a >> b >> h; 
        m[a].push_back(h); //push the beginning point
        m[b].push_back(-1*h); //push the ending point
    }
    for(auto i:m){
        for(auto j:i.second) { //update all heights
            if(j<0) H.erase(H.find(-1*j)); //be careful: only erase a single occurrence 
            if(j>0) H.insert(j);
        }
        currmax=*(H.begin());
        if(currmax!=prevmax) {
            prevend=i.first; 
            ans+=prevmax*(prevend-prevstart);
            prevstart=i.first;
        }
        prevmax=currmax;  
    }
    cout << ans << "\n";
    return 0;
}
