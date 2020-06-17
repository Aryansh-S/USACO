#include <iostream>
#include <cstdio>
#include <deque>
#include <utility>
using namespace std;

#define maxn 100000
#define maxm 100000
typedef pair<int,int> pii;
#define f first
#define s second
int n,m,ans,choice[maxn]; deque<int> cereal[maxm],cows; pair<int,int> cowvals[maxn];
bool firstcheck[maxm]; //look at cow i

#define problemname "cereal"

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);
  cin >> n >> m;
  for(int i=0; i<n; i++){
    int a,b; cin >> a >> b; a--,b--; cows.push_back(i);
    cowvals[i].f=a; cowvals[i].s=b;
    cereal[a].push_back(i); cereal[b].push_back(i);
    if(!firstcheck[a]){
      firstcheck[a]=1;
      choice[i]=1; ans++;
    }
    else if(!firstcheck[b]){
      firstcheck[b]=1;
      choice[i]=2; ans++;
    }
    else choice[i]=3;
  }
  while(!cows.empty()){
    cout << ans << "\n";
    ans--; int prev=cows.front();
    cows.pop_front();
    int fc=cowvals[prev].f, sc=cowvals[prev].s;
    cereal[sc].pop_front(); //allow second cereal to go elsewhere
    cereal[fc].pop_front(); //next cow gets first cereal
    if(choice[cereal[fc].front()]==3){
        ans++;
        if(cowvals[cereal[fc].front()].f==fc) choice[cereal[fc].front()]=1;
        else choice[cereal[fc].front()]=2;
    }
    //that cows second cereal becomes usable
    //if(cereal[cowvals[cereal[fc].front()].s].front()==cereal[fc].front()) cereal[cowvals[cereal[fc].front()].s].pop_front();
    int count=0;
    int nextsecondcow=cereal[cowvals[cereal[fc].front()].s][1]; //the cow with the second choice of that first cow gets cereal
    if(choice[cereal[fc].front()]==1) while(count!=n){
        count++;
        if(choice[nextsecondcow]==3){
            ans++; choice[nextsecondcow]=2; break;
        }
        else{
        	choice[nextsecondcow]=1;
            nextsecondcow=cereal[cowvals[nextsecondcow].s][1];
        }
    }

    //process until a cow is hungry
   }
  return 0; //if not at the front, doesn't get cereal
}