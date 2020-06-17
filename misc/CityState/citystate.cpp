#include <iostream>
using namespace std;

#define MAXN 1000
#define MAXK 1000

bool state[MAXN+5][MAXK+5], visited[MAXN+5][MAXK+5];
int island[MAXN+5][MAXK+5];
int n,k;

void dfs(int x, int y, int isl, bool ad){
    if(!visited[x][y] && state[x][y]){
        visited[x][y]=1;
        if(island[x][y]==0){
            if(ad==1) island[x][y]=isl;
            else{
                int maxi=island[0][0];
                for(int i=0; i<n; i++){
                    for(int j=0; j<k; j++){
                        maxi=max(maxi, island[i][j]);
                    }
                }
                island[x][y]=maxi+1;
            }
        }
        if(x-1>=0) dfs(x-1, y, isl, 1);
        if(y-1>=0) dfs(x, y-1, isl, 1);
        if(x+1<n) dfs(x+1, y, isl, 1);
        if(y+1<k) dfs(x, y+1, isl, 1);
        if(x-1>=0 && y-1>=0) dfs(x-1, y-1, isl, 1);
        if(x+1<n && y+1<k) dfs(x+1, y+1, isl, 1);
        if(x-1>=0 && y+1<k) dfs(x-1, y+1, isl, 1);
        if(x+1<n && y-1>=0) dfs(x+1, y-1, isl, 1);
    }
}

int main(){
    cin >> n >> k;
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            cin >> state[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            dfs(i, j, 0, 0);
        }
    }
    int maxi=island[0][0];
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            maxi=max(maxi, island[i][j]);
        }
    }
    cout << maxi << "\n";
    return 0;
}
