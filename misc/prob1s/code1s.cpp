#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

#define pb push_back

#define problemname "lineup"

map<string, int> m; map<int, string> minv;
string s="01234567", c1, c2, w; //1<=n<=7
int n;
vector < vector<int> > adj;

int main(){
	m["Beatrice"]=0; m["Belinda"]=1; m["Bella"]=2; m["Bessie"]=3; m["Betsy"]=4; m["Blue"]=5;
	m["Buttercup"]=6; m["Sue"]=7;
	minv[0]="Beatrice"; minv[1]="Belinda"; minv[2]="Bella"; minv[3]="Bessie"; minv[4]="Betsy"; minv[5]="Blue";
	minv[6]="Buttercup"; minv[7]="Sue";

	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);

	cin >> n;
	adj.resize(10);
	for(int i=0; i<n; i++){
		cin >> c1 >> w >> w >> w >> w >> c2;
		adj[m[c1]].pb(m[c2]);
		adj[m[c2]].pb(m[c1]);
	}
	bool b=1;
	do{ b=1;
		for(int i=0; i<8; i++){ //position on the permutation
			if(adj[s[i]-'0'].size()==1){
				if(i==0){
					if(s[i+1]-'0'!=adj[s[i]-'0'][0]){b=0;}
				}
				else if(i==7){
					if(s[i-1]-'0'!=adj[s[i]-'0'][0]){b=0;}
				}
				else{
					if(s[i-1]-'0'!=adj[s[i]-'0'][0] && s[i+1]-'0'!=adj[s[i]-'0'][0]){b=0;}
				}
			}
			if(adj[s[i]-'0'].size()==2){
				if(i==0 || i==7){b=0;}
				else{
					if((s[i-1]-'0' != adj[s[i]-'0'][0] || s[i+1]-'0' != adj[s[i]-'0'][1]) && (s[i+1]-'0' != adj[s[i]-'0'][0] || s[i-1]-'0' != adj[s[i]-'0'][1])){
						b=0;
					}
				}
			}
		}
	}while(b==0 && next_permutation(s.begin(),s.end()));

	for(int i=0; i<s.length(); i++){
		cout << minv[s[i]-'0'] << "\n";
	}

	return 0;
}
