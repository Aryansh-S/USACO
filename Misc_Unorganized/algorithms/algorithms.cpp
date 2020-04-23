#include <iostream>
#include <cstdio>
#include <vector> //for vectors
#include <string> //for strings
#include <algorithm> //for sort, binary search (upperbound, lowerbound)
#include <utility> //for pairs
#include <set> //for sets
#include <unordered_set> //for unordered_set hashtable
#include <stack> //for stacks
#include <queue> //for queues and priority_queues(heaps)
#include <map> //for maps
#include <cmath> //for pow, roots, and floors
using namespace std;

//or #include <bits/stdc++.h>

#define problemname ""


/*
USACO - Silver

Sorting

Selection Sort, Bubble sort, Built-in sort
Array sort, Class array sort
Searching

Linear Search, Binary Search
Silver Level techniques

FloodFill, RMQ (range minimum query), Prefix Sums, Brute Force(Complete Search)
String Algorithms

Greedy Algorithm Problems

USACO Silver Greedy Problems
Simulation, Ad-hoc Problems

Data Structures

Stack, Queue, Vector, Set, Map,PriorityQueue- Silver level
Recursion

Depth First Search

Breath First Search
Sweepline
*/

//BINARY SEARCH

//lower bound is the first greater than or equal to a given value, but if the value is greater than everything else, then it returns the size (lastIndex+1)
//upper bound is the first greater than a given value, but if the given value is the greatest, then it returns the size (lastIndex+1)

//to find the number of values in a sorted vector v that lie in the interval [a,b], use upper_bound(v.begin(), v.end(), b)-lower_bound(v.begin(), v.end(), a)

#define SIZE 4
vector<int> v={4, 3, 5, 1};
int a[SIZE]={4, 3, 5, 1};

bool binary_search_vec(vector <int> v1, int val){
     sort(v1.begin(), v1.end());
     return binary_search(v1.begin(), v1.end(), val);
}

int binary_search_vec_lb (vector <int> v1, int val){
    sort(v1.begin(), v1.end());
    auto lb=lower_bound(v1.begin(), v1.end(), val);
    return lb-v1.begin();
}

int binary_search_vec_ub (vector <int> v1, int val){
    sort(v1.begin(), v1.end());
    auto ub=upper_bound(v1.begin(), v1.end(), val);
    return ub-v1.begin();
}

bool binary_search_arr(int val){
    sort(a, a+SIZE);
    return binary_search(a, a+SIZE, val);
}

int binary_search_arr_lb (int val){
    sort(a, a+SIZE);
    auto lb=lower_bound(a, a+SIZE, val);
    return lb-a;
}

int binary_search_arr_ub (int val){
    sort(a, a+SIZE);
    auto ub=upper_bound(a, a+SIZE, val);
    return ub-a;
}

/*
int l=0, r=SIZE, m, val=x;
while(r-l>1){
    m = (l+r)/2;
    if(a[m] < val) l = m;
    else r = m;
}
(index is the value of r - the lower bound)*/

//STACKS (LIFO - last in, first out)

stack <int> s;
s.push(10);
s.push(11);
s.push(12);
//{12,11,10}
s.pop();
//{11,10}
//A stack only exposes its top element through s.top() and its size through s.size()

//MAPS
/*
map <int, int> m;
m.clear() clears the map completely
m[key]=value
map.empty() returns if map is empty
m.count(key) counts the number of occurences of a key (0 or 1)
map.find(key) returns an iterator pointing to the location of a key
*/


//DFS
/*
vector <vector <int>> adj;
vector <bool> visited;
void dfs(int u){
     if(!visited[u]){
                     visited[u]=1;
                     //process
                     for(auto el:adj[u]) dfs(el);
     }
}
*/

//BFS
/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue <int> q;
vector <bool> visited;
vector <int> dist;
vector <vector <int>> adj;
int x; //starting vertex for BFS

int main(){
    int n, k;
    cin >> n >> k;
    visited.resize(n);
    dist.resize(n);
    adj.resize(n);
    for(int i=0; i<k; i++){
            int a,b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
    }
    //start BFS at vertex x
    visited[x]=1;
    dist[x]=0;
    q.push(x);
    while(!q.empty()){
                      int s=q.front();
                      q.pop();
                      //process node
                      for(auto u:adj[s]){
                           if(visited[u]) continue;
                           visited[u]=1;
                           dist[u]=dist[s]+1;
                           q.push(u);
                      }
    }
    return 0;
}
*/

/*
#include <unordered_set>
unordered_set <int> s;
s.insert(4); s.insert(10); s.insert(11);
the boolean (s.find(4)==s.end()) allows lookup in O(1)
*/

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen(problemname ".in", "r", stdin); freopen(problemname ".out", "w", stdout);

    return 0;
}
