#include <bits/stdc++.h>

using namespace std;

int translate (string s)
{
	if (s == "Beatrice") {return 0;}
	if (s == "Belinda") {return 1;}
	if (s == "Bella") {return 2;}
	if (s == "Bessie") {return 3;}
	if (s == "Betsy") {return 4;}
	if (s == "Blue") {return 5;}
	if (s == "Buttercup") {return 6;}
	if (s == "Sue") {return 7;}
	return -1;
}

string reverse (int s)
{
	if (s == 0) {return "Beatrice";}
	if (s == 1) {return "Belinda";}
	if (s == 2) {return "Bella";}
	if (s == 3) {return "Bessie";}
	if (s == 4) {return "Betsy";}
	if (s == 5) {return "Blue";}
	if (s == 6) {return "Buttercup";}
	if (s == 7) {return "Sue";}
	return "";
}

int cti (char c)
{
	return c-'0';
}

vector <int> next1[8];

bool inside(int n, vector<int> v){
	bool b=0;
	if(v.size()==0){return 1;}
	for(int i=0; i<v.size(); i++){
		if(v[i]==n){b=1;}
	}
	return b;
}

int main (void)
{
	ifstream fin ("lineup.in");
	ofstream fout ("lineup.out");
	int N; fin >> N;
	bool check = true;
	string x, y, z = "01234567";
	for (int i = 0; i < N; i++)
	{
		fin >> x;
		fin >> y >> y >> y >> y;
		fin >> y;
		int ix = translate(x); int iy = translate(y);
		next1[ix].push_back(iy);
		next1[iy].push_back(ix);
	}
	while (true)
	{
		for(int i=0; i<8; i++){
			if(i==0 && !inside(cti(z[i+1]), next1[cti(z[i])])){
				check=0; /*cout << "LOOK " << cti(z[i+1]) << "\n";
				for(int j=0; j<next1[i].size(); j++) {cout << next1[i][j] << " ";}
				cout << "\n";*/
			}
			if(i==0 && next1[cti(z[i])].size()==2) {check=0;}
			if(i==7 && !inside(cti(z[i-1]), next1[cti(z[i])])){
				check=0;
			}
			if(i==7 && next1[cti(z[i])].size()==2) {check=0;}
			if(i!=0 && i!=7 && (!inside(cti(z[i+1]), next1[cti(z[i])]) || !inside(cti(z[i-1]), next1[cti(z[i])]))){
				if(next1[cti(z[i])].size()==1 && (!inside(cti(z[i+1]), next1[cti(z[i])]) && !inside(cti(z[i-1]), next1[cti(z[i])]))){
					check=0;
				}
				if(next1[cti(z[i])].size()==2) {check=0;}
			}
		}
		if (check || z=="76543210")
		{
			break;
		}
		next_permutation (z.begin(), z.end());
		check=1;
	}

	for(int i=0; i<z.length(); i++)
	{
		fout << reverse(cti(z[i])) << '\n';
	}
	return 0;
}
