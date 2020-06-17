#include <iostream>
#include <cstdio>
#include <queue>
#include <set>
#include <functional>
#include <iterator>
#include <utility>
using namespace std;

#define mp make_pair
#define pb push_back

struct sweepline{ //give input
	struct pt{int x,y;};
	struct raw_seg{pt s, e;};
	struct seg{int m,b; pt s,e;};
	raw_seg mraw(seg s){raw_seg ret; ret.s=s.s; ret.e=s.e; return ret;}
	seg raw_to_seg(raw_seg sg){
		int m=(sg.s.y-sg.e.y)/(sg.s.x-sg.e.x);
		int b=sg.s.y-m*(sg.s.x);
		seg ret;
		ret.m=m; ret.b=b; ret.s=sg.s; ret.e=sg.e;
		return ret;
	}
	bool checkisect(seg a, seg b){
		return 1;
	}
	struct event{
		char name; raw_seg s[2];
		bool operator<(const event& e2){
			if(name=='S' && e2.name=='S') return s[0].s.x<e2.s[0].s.x;
			else if(name=='E' && e2.name=='E') return s[0].e.x<e2.s[0].e.x;
			else if(name=='S' && e2.name=='E') return s[0].s.x<e2.s[0].e.x;
			else return 0;
		}
	};
	vector< pair< pair <int,int>,pair<int,int> > > input;
	vector<raw_seg> segs;
	vector< pair< raw_seg,raw_seg> > isects;
	set<seg> seglist;
	priority_queue<event, vector<event>, greater<event> > eq;
	void sweep(){
		for(auto i:input){
			pt s,e; s.x=i.first.first, s.y=i.first.second; e.x=i.second.first; e.y=i.second.second;
			raw_seg give; give.s=s; give.e=e; segs.pb(give);
		}
		for(auto sg:segs){
			event t; t.name='S'; t.s[0]=sg; eq.push(t);
			t.name='E'; eq.push(t);
		}
		while(!eq.empty()){
			//process sweeps
			auto e=eq.top(); eq.pop();
			if(e.name=='S'){
				seg s=raw_to_seg(e.s[0]);
				seglist.insert(s);
				if(checkisect(s,*next(seglist.find(s),1))){event t; t.name='I'; t.s[0]=mraw(s); t.s[1]=mraw(*next(seglist.find(s),1)); eq.push(t);}
				if(checkisect(s,*next(seglist.find(s),-1))){event t; t.name='I'; t.s[0]=mraw(s); t.s[1]=mraw(*next(seglist.find(s),-1)); eq.push(t);}
			}
			else if(e.name=='E'){
				seg s=raw_to_seg(e.s[0]);
				if(checkisect(*next(seglist.find(s),1),*next(seglist.find(s),-1))){
					event t; t.name='I'; t.s[0]=mraw(*next(seglist.find(s),-1)); t.s[1]=mraw(*next(seglist.find(s),1)); eq.push(t);
				}
				seglist.erase(seglist.find(s));
			}
			else if(e.name=='I'){
				auto inter=mp(e.s[0],e.s[1]); isects.pb(inter);
				auto s0=raw_to_seg(e.s[0]); auto s1=raw_to_seg(e.s[1]);
				seglist.erase(seglist.find(s0));
				seglist.erase(seglist.find(s1));
				seglist.insert(s1); seglist.insert(s0);
				if(checkisect(s1,*next(seglist.find(s1),-1))){event t; t.name='I'; t.s[0]=mraw(s1); t.s[1]=mraw(*next(seglist.find(s1),-1)); eq.push(t);}
				if(checkisect(s0,*next(seglist.find(s0),1))){event t; t.name='I'; t.s[0]=mraw(s0); t.s[1]=mraw(*next(seglist.find(s0),1)); eq.push(t);}
			}
		}
	}
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);



	return 0;
}
