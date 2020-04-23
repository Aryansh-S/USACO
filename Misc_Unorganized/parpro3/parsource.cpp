#include <array>
#include <vector>
#include <iostream>

using namespace std;

array<int , 2500> faces;
bool store[2500];
vector<int> next[2500];
bool check[2500];
int p1;
int p2;

int N;
void dfs(int runner, int f1, bool store, array<int , 2500> further){
	if(!store[f1]){
		if(check){
			check=0;
		}
		else{
			runner++;
			if(runner==13){
				runner=1;
			}
		}
		bool b=1;
		for(int i=0; i<N; i++){
			if(further[i]!=12) b=0;
		}
		if(b==1){
			store[f1]=1; store++;
			return;
		}
		for(auto tryvar: next[runner]){
			if(further[tryvar]!=12) {
				dfs(tryvar, f1, check, further);
			}
		}
}
}


int main(){
	freopen("clocktree.in", "r", stdin);
	freopen("clocktree.out", "w", stdout);
	cin >> N;
	for(int i=0; i<N; i++) cin >> faces[i];
	for(int i=0; i<N-1; i++){
		cin >> p1 >> p2;

		next[p1-1].push_back(p2-1);

		next[p1-1].push_back(p2-1);
	}
	for(int checker=0; checker<N; checker++){
		dfs(checker,checker,true,faces);

		check[checker]=true;
	}
	int sum=0;
	for(int i=0; i<N; i++) {
		sum+=store[i];
	}
	cout << sum;
}


