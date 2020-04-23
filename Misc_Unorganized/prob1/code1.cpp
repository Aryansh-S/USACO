#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
#define pb push_back

#define problemname "lineup"

struct two {int fir; int sec;};

map<string, int> m;
map<int,string> m_inv;
two p[9];
int n;
string c1, c2, waste; //8!
string s="01234567";
// Beatrice Belinda Bella Bessie Betsy Blue Buttercup Sue

int main(){
	m["Beatrice"]=0; m["Belinda"]=1; m["Bella"]=2; m["Bessie"]=3; m["Betsy"]=4; m["Blue"]=5;
	m["Buttercup"]=6; m["Sue"]=7;
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);

	cin >> n;
	for(int i=0; i<n; i++){
		cin >> c1 >> waste >> waste >> waste >> waste >> c2;
		p[i].fir=m[c1]; p[i].sec=m[c2];
	}

	do{
		bool b=1;
		for(int i=0; i<8; i++){
			for(int j=0; j<n; j++){
				if(s[i]==p[j].fir){
					if(i!=0 && i!=7) {if(s[i+1]!=p[j].sec || s[i-1]!=p[j].sec){b=0;}}
					if(i==0) {if(s[i+1]!=p[j].sec){b=0;}}
					if(i==7) {if(s[i-1]!=p[j].sec){b=0;}}
				}

				if(s[i]==p[j].sec){
					if(i!=0 && i!=7) {if(s[i+1]!=p[j].fir || s[i-1]!=p[j].fir){b=0;}}
					if(i==0) {if(s[i+1]!=p[j].fir){b=0;}}
					if(i==7) {if(s[i-1]!=p[j].fir){b=0;}}
				}

			}
		}
		if(b){break;}
	}while(next_permutation(s.begin(),s.end()));

	cout << s << "\n";

	return 0;
}

