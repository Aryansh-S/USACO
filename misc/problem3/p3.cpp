#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#define pb push_back

#define problemname "badmilk"

struct three{
	int x; int y; int z; //x is person, y is milk, z is time
};

bool compare_three(const three lhs, const three rhs){
	return (lhs.z<rhs.z);
}

struct two{
	int x; int y; //x is person, y is time
};

bool compare_two(const two lhs, const two rhs){
	return (lhs.x<rhs.x);
}

int n,m,d,s;
vector<three> events;
vector<two> sick;
set<int> worstmilks;
int ans;

set<int> inter(set<int> s1, set<int> s2){
	set<int> intersect;
	set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(), inserter(intersect,intersect.begin()));
	return intersect;
}

int maxi(int x, int y){
	return (x>y)?x:y;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);

	cin >> n >> m >> d >> s;
	set<int> milks[s];
	for(int i=0; i<d; i++) {
		int p,m,t;
		three a; a.x=p; a.y=m; a.z=t;
		events.pb(a);
	}
	for(int i=0; i<s; i++){
		int p,t;
		two b; b.x=p; b.y=t;
		sick.pb(b);
	}
	sort(events.begin(), events.end(), compare_three);
	sort(sick.begin(), sick.end(), compare_two);

	for(int i=0; i<s; i++){
		int personsick=sick[s].x;
		int timesick=sick[s].y;
		for(int j=0; j<d; j++){
			if(events[j].z<timesick && events[j].x==personsick){
				milks[j].insert(events[j].y);
			}
		}
	}
	for(int i=0; i<s-1; i++){
		if(milks[i+1].size()!=0){worstmilks=inter(worstmilks, milks[i+1]);}
	}

	auto it=worstmilks.begin();
	while(it!=worstmilks.end()){
		int consider=*it;
		set<int> affected;
		for(int i=0; i<d; i++){
			if(events[i].y==consider){affected.insert(events[i].x);}
		}
		if(ans<affected.size()){ans=affected.size();}
		it++;
	}
	//cout << s+1 << "\n";
	//cout << ans << "\n";
	return 0;
}
