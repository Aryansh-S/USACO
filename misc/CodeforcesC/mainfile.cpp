#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

set <int> s;
vector <int> v;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	while(n--){int k; cin >> k; s.insert(k);}
	if(s.size()>3) {cout << "-1\n"; return 0;}
	if(s.size()==1) {cout << "0\n"; return 0;}
	for(auto el:s){v.push_back(el);}
	sort(v.begin(), v.end());
	if(v.size()==2){
		if((v[1]-v[0])%2) cout << v[1]-v[0] << "\n";
		else cout << (v[1]-v[0])/2 << "\n";
		return 0;
	}
	if(v.size()==3){
		if((v[2]-v[0]%2)) cout << "-1\n";
		else{
			if(v[2]-v[1]==v[1]-v[0]) cout << (v[2]-v[0])/2 << "\n";
			else cout << "-1\n";
		}
		return 0;
	}
}
