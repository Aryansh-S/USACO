#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define f first
#define s second

//#define problemname "circlecross"

int a[]={-1,-1}, b, num;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);
	string s;
	cin >> s;
	for(char c='A'; c<='Z'; c++){
		for(int i=0; i<s.length(); i++){
			if(c==s[i]){
				if(a[0]==-1) a[0]=i;
				else a[1]=i;
			}
		}
		for(int i=a[0]+1; i<a[1]; i++){
			for(int j=a[0]+1; j<a[1]; j++){
				if(a[i]==a[j] && i!=j) b=1;
			}
			if(b==0) num++;
		}
	}
	cout << num << "\n";
	return 0;
}
