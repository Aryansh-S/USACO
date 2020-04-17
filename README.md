# USACO
Competitive Programming Resources &amp; Implementations

This is a compilation of resources and implementations for contest programming -- algorithms and past problems for USACO.
You can find the latest version of my contest programming template (ongoing modification) in "template.cpp"; please credit
before use in-contest. 
If you want to #include <bits/stdc++.h> but your compiler does not allow you to do so, simply go to the file "stdc++.h" and
follow the unofficial directions at the top. 
The "src" folder just contains source files and images that are integrated elsewhere; you can ignore it. 

# Topics
What to learn for each division

Bronze: basic data structures (int, bool, char, string, array, vector), basic if/else logic, syntax, complete search, basic iterative/recursive methods, functions (structs and objects like pairs are sometimes helpful but not necessary)

Silver: time complexity analysis (and pruning to amortize), binary search, two pointer concept search, stacks/(priority/heap) queues/deques, DFS/BFS/floodfill/connected components (iterative/recursive) with graphs as adjacency lists, DSU union find data structure (optional but recommended), advanced recursive methods, basic DP (prefix/suffix and difference arrays aka +1/-1 trick), basic concept of greedy, basic line sweep processing (more on the harder side), sliding window minimums, sorting (conceptually and using std::sort), binary search tree data structures (sets, maps, etc.), basic bitwise XOR; hash tables like unordered_set and unordered_map are optional

Gold: DSU union find data structure (cycle finding, connected components, etc.), segment tree, Fenwick tree (BIT), priority queues as heaps (in-depth), topological sort and Euler tour, DFS/BFS (multisource BFS), Dijkstra's (multisource also), Floyd-Warshall, Kruskal's/Prim's (Minimum Spanning Tree), HLD (Heavy-Light Decomposition), LCA (lowest common ancestor), advanced greedy methods, standard DP (knapsack, coin change, basic state transitions, etc.), bitmasks and bitsets, in-depth two pointer search, sliding window minimum, advanced line sweep processing, more binary search, combinatorics (PIE, linearity of expectation), advanced bitwise XOR manipulations

Platinum: all of the above, advanced DP, interactives, computational geometry, matrix exponentiation, etc. 

These can actually change each year depending on what is tested by problem writers and the type of problem, but these lists should suffice as of late. 

# Other Resources
I discourage the training gate offered by USACO, as it is outdated and problem quality is not the best as of now. 

Competitive Programmer's Handbook

Guide to Competitive Programming 

Competitive Programming 3: The New Lower Bound of Programming Contests

Past Problems

YouTube Tutorials (none in particular, but just look for good series of videos)

CodeForces, CodeChef, etc.

# Time Complexity
Design Efficient Algorithms 

Time complexity is usually not much of a worry for bronze, but for silver and beyond, it is critical that algorithms are designed to appropriate time complexities (adhering to the bounds of the various variables in the problem statement). 

In general, by way of notation, define the time complexity ![O(f(n_1, n_2, \dots, n_k))](https://render.githubusercontent.com/render/math?math=O(f(n_1%2C%20n_2%2C%20%5Cdots%2C%20n_k))) to mean that the number of operations in a program (and therefore its runtime) is proportional to ![f(n_1, n_2, \dots, n_k)](https://render.githubusercontent.com/render/math?math=f(n_1%2C%20n_2%2C%20%5Cdots%2C%20n_k)), where all arguments in the function are some variables described in the problem relevant to its solution. 

USACO allows roughly ![10^8](https://render.githubusercontent.com/render/math?math=10%5E8) operations per second. This means that ![10^8](https://render.githubusercontent.com/render/math?math=10%5E8) is the upper bound on the number of operations your implementation should execute. 

Below is helpful information in the context of contest programming (credit~CP3): 
![](https://github.com/Aryansh-S/USACO/blob/master/src/Screen%20Shot%202020-04-16%20at%204.10.43%20PM.png)
![](https://github.com/Aryansh-S/USACO/blob/master/src/Screen%20Shot%202020-04-16%20at%204.11.02%20PM.png)
![](https://github.com/Aryansh-S/USACO/blob/master/src/Screen%20Shot%202020-04-16%20at%204.11.23%20PM.png)
