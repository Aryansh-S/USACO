#include <iostream>
#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;
#define f first
#define s second
#define maxn 100000
#define maxm 100000

#define problemname "cereal"

int n,m; pii favs[maxn];

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  //freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);
  cin >> n >> m;
  for(int i=0; i<n; i++) {cin >> favs[i].f >> favs[i].s; favs[i].f--,favs[i].s--;}
  for(int i=0; i<n; i++){ //cows i through n-1
    bool cereal[m]; int ans=0;
    for(int j=0; j<m; j++) cereal[j]=1;
    for(int j=i; j<n; j++){ //cow j
      if(cereal[favs[j].f]){cereal[favs[j].f]=0;ans++;}
      else if(cereal[favs[j].s]){cereal[favs[j].s]=0;ans++;}
    }
    cout << ans << "\n";
  }
  return 0;
}




/*
 * #include<iostream>
#include<fstream>
#include<cmath>
#include<set>
using namespace std;
#define f first
#define s second
int n;
int counter[10000];
pair<int, int> types[10000];
int typesleft[10000];
set<int> a;
int k;
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>types[i].f>>types[i].s;
    }
    for(int i=n;i>=1;i--){
        a.insert(types[i].f);
        a.insert(types[i].s);
        typesleft[i]=a.size();
    }
    for(int i=1;i<=n;i++){
        int left=n-i+1;
        cout<<min(left, typesleft[i])<<'\n';
    }
}
*/





/*
 #include <iostream>
#include <queue>
#include <utility>
using namespace std;

#define maxn 100000
#define maxm 100000
typedef pair<int,int> pii;
#define f first
#define s second
int n,m,ans,choice[maxn]; queue<int> cereal[maxm],cows; pair<int,int> cowvals[maxn];
bool firstcheck[maxm]; //look at cow i

int main(){
  cin >> n >> m;
  for(int i=0; i<n; i++){
    int a,b; cin >> a >> b; a--,b--; cows.push(i);
    cowvals[i].f=a; cowvals[i].s=b;
    cereal[a].push(i); cereal[b].push(i);
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
    ans--; //cereals has cow number
    int firstcereal=cowvals[cows.front()].f;
    cereal[firstcereal].pop(); //update for leave
    int newfirstcerealcow=cereal[firstcereal].front();
    //choice[cereal[cowvals[cows.front()].f].front()]
    if(choice[newfirstcerealcow]==3){
      ans++;
      //figure out if it's first or second choice
      if(cowvals[newfirstcerealcow].f==firstcereal){ //someone else had the second choice
        choice[newfirstcerealcow]=1;  cout << "LOL\n";
        //revive the first cow for second choice (whoever first wanted it)
        cout << "LOOKHERE" << choice[cereal[cowvals[newfirstcerealcow].s].front()] << "\n";
        if(choice[cereal[cowvals[newfirstcerealcow].s].front()]==3){
          ans++; cout << "LOL\n";
          choice[cereal[cowvals[newfirstcerealcow].s].front()]=2;
        }
      }
      else{choice[newfirstcerealcow]=2;}
      //ans++;
    }
    cows.pop();
  }
  return 0; //if not at the front, doesn't get cereal
}
 */



/*
 #include <iostream>
#include <queue>
#include <utility>
using namespace std;

#define maxn 100000
#define maxm 100000
typedef pair<int,int> pii;
#define f first
#define s second
int n,m,ans,choice[maxn]; queue<int> cereal[maxm],cows; pair<int,int> cowvals[maxn];
bool firstcheck[maxm]; //look at cow i

int main(){
  cin >> n >> m;
  for(int i=0; i<n; i++){
    int a,b; cin >> a >> b; a--,b--; cows.push(i);
    cowvals[i].f=a; cowvals[i].s=b;
    cereal[a].push(i); cereal[b].push(i);
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
    ans--;
    //ans--; //cereals has cow number
    int firstcereal=cowvals[cows.front()].f;
    int secondcereal=cowvals[cows.front()].s;
    cereal[firstcereal].pop(); //update for leave
    cereal[secondcereal].pop();
    int newfirstcerealcow=cereal[firstcereal].front();
    //person who should be enjoying firstcereal
    int secondcerealcow=cereal[secondcereal].front();
    if(secondcereal==cowvals[secondcerealcow].f)choice[secondcerealcow]=1;
    else choice[secondcerealcow]=2;

    //choice[newfirstcerealcow]=1;
    //person enjoying second cereal all along

    //choice[cereal[cowvals[cows.front()].f].front()]
    if(choice[newfirstcerealcow]==3) {ans++; cout << "HAHA\n"; choice[newfirstcerealcow]=1;}

    if(firstcereal==cowvals[newfirstcerealcow].f) choice[newfirstcerealcow]=1;
    else choice[newfirstcerealcow]=2;



    if(choice[newfirstcerealcow]==1){
        cereal[cowvals[newfirstcerealcow].s].pop();
        if(choice[cereal[cowvals[newfirstcerealcow].s].front()]==3) {ans++; cout << "HALA\n"; choice[cereal[cowvals[newfirstcerealcow].s].front()]=1;}
        //check if new cow is one that was dead before
    }
    else{
        cereal[cowvals[newfirstcerealcow].f].pop();

    }
    cows.pop();
    choice[cows.front()]=1;
   }
  return 0; //if not at the front, doesn't get cereal
}
 * */

