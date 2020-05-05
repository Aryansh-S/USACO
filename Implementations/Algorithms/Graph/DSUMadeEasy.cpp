#include <bits/stdc++.h> 
using namespace std; 
//union-find data structure made easy & efficient
//keep an array of parents (e below)

const int mx=1e5; 
int e[mx]; 

int get(int x){return e[x]<0?x:e[x]=get(e[x]);} //want parent, use path compression
void merge(int x, int y){
    x=get(x),y=get(y); if(x==y) return; //already united (prevent union to prevent cycle -- can also use for cycle counting)
    if(e[x]>e[y]) swap(x,y); 
    e[x]+=e[y]; e[y]=x; //merge with union by rank
    //modifying our ranks as such allows us to do this neatly
}
bool sameSet(int x, int y){return get(x)==get(y);}
//check if in same set

int main(){
    memset(e,-1,sizeof(e)); //init values 
    merge(0,1);
    merge(1,2); 
    merge(2,10); 
    merge(10,50);
    merge(1,50); 
    cout << get(2) << "\n"; //look at how cleanly we can create a union-find data structure
    return 0;
}
