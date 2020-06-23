# USACO
Competitive Programming Resources &amp; Implementations (C++ Based)

## Quick Find

- [An Organized Contest Programming Template (C++)](https://github.com/Aryansh-S/USACO/blob/master/CPtemplate.cpp)

- [Extensive Algorithm Library](https://github.com/Aryansh-S/USACO/blob/master/Algos.h)

- [Simple, Generic Fenwick Tree Implementations](https://github.com/Aryansh-S/USACO/tree/master/implementations/Query%20DS/Easy_Fenwick) 

- [Simple, Generic Segment Tree Implementations](https://github.com/Aryansh-S/USACO/tree/master/implementations/Query%20DS/Easy_Segtrees)

## Books \& Handouts

[DP Handout (WIP)](https://www.overleaf.com/read/vgdvpkrhjdbb)

[USACO guide](http://darrenyao.com/)

## Other Resources

- Competitive Programmer's Handbook (a good place to start)

- Guide to Competitive Programming (somewhere to continue)

- Competitive Programming 3: The New Lower Bound of Programming Contests (full of good content, ignore problems for the most part)

- Past Problems (the best resource around)

- Older Contests Predating 2011-2012: https://contest.usaco.org/DEC05.htm (change the ID around for more)

- YouTube Tutorials (none in particular, but just look for good series of videos)

- CodeForces, CodeChef, etc. (stylistic differences but good content)

- CSES Problem Set (good for practice with standard setups) 

- https://www.dropbox.com/s/z2lur71042pjaet/guide.pdf?dl=0 (a well-designed handout that is clear and cuts to the chase for algorithms)

- Go further: http://www.csc.kth.se/~jsannemo/slask/main.pdf

- Problems by topic and difficulty: https://codeforces.com/blog/entry/55274

## Topics
What to learn for each division

Bronze: basic data structures (int, bool, char, string, array, vector), basic if/else logic, syntax, complete search, basic iterative/recursive methods, functions (structs and objects like pairs are sometimes helpful but not necessary)
- Have a general command of the language and get comfortable with basic manipulations. The make or break for bronze tends to be on the problem solving level for most contestants -- know how to approach and dissect problems that may initially seem difficult; develop intuition.

Silver: time complexity analysis (and pruning to amortize), binary search, two pointer concept search, stacks/(priority/heap) queues/deques, DFS/BFS/floodfill/connected components (iterative/recursive) with graphs as adjacency lists, DSU union find data structure (optional but recommended), advanced recursive methods, basic DP (prefix/suffix and difference arrays aka +1/-1 trick), basic concept of greedy, basic line sweep processing (more on the harder side), sliding window minimums, sorting (conceptually and using std::sort), binary search tree data structures (sets, maps, etc.), basic bitwise XOR; hash tables like unordered_set and unordered_map are optional
- Brian asserts that BFS and related topics are best kept out of silver (typically classified as shortest path finders, fitting under gold), but I recommend practicing it anyway. Here is my reasoning behind this: it is a very powerful idea that DFS and BFS are essentially the same lines of code in execution other than switching a stack for a queue (from FILO to FIFO in terms of event processing), and this will aid your problem solving skills if you are aiming to get ahead. The benefits 
you will gain in terms of intuition far outweigh the time spent. 

Gold: DSU union find data structure (cycle finding, connected components, etc.), segment tree, Fenwick tree (BIT) for point/range updates and queries, priority queues as heaps (in-depth), topological sort and Euler tour, DFS/BFS (multisource BFS), Dijkstra's (multisource also), Floyd-Warshall, Kruskal's/Prim's (Minimum Spanning Tree), HLD (Heavy-Light Decomposition), LCA (lowest common ancestor), advanced greedy methods, standard DP (knapsack, coin change, top-down, bottom-up, recursive, iterative, memoized, basic state transitions, etc.), bitmasks and bitsets, in-depth two pointer search, sliding window minimum, advanced line sweep processing, more binary search, combinatorics (PIE, linearity of expectation), advanced bitwise XOR manipulations
- Pragmatically, I think it makes more sense to replace Bellman-Ford with SPFA (shortest path faster algorithm), which is an optimization. In my template, you can find an even further optimized version of SPFA based on a double-ended queue (deque) implementation. Experimentally, many surmise that SPFA can average to linear runtime, but even if this is not the case, I prefer SPFA for its cleanliness and closer resemblance to Dijkstra. 
- According to Brian, LCA is fair game for gold (though certainly on the harder side conceptually) -- you can implement Tarjan's offline LCA algorithm based on DSU or simply compute LCA with binary lifting. HLD is technically not required for gold, but it is definitely good to know if you have time: many tree problems lend themselves quite well to the thought process underlying HLD. 
- DP is very important to practice and arguably one of the harder topics covered in the division. Take time to get comfortable with it; make DP thinking second nature. 

Platinum: all of the above, lazy propagation, advanced DP, interactives, computational geometry, matrix exponentiation, etc. 
- There is no concrete limit for what fits here. Expect to see anything; this is the division that decides the team. 

These can actually change each year depending on what is tested by problem writers and the type of problem, but these lists should suffice as of late. The general trend is that contests are getting harder. 

## Stuck? 
Try the following.

- Analyze bounds and time complexity to reverse-engineer potential algorithms in the problem

- Draw a picture

- Work out the sample case

- Approach the problem from a different angle (backwards, sideways, etc.)

- Start with brute force and work toward pruning optimizations (even go for amortized analysis because heuristic solutions might suffice for the test cases)

- Gauge time and remember partial credit for test cases

- Move on to another problem/take a break and come back with a fresh mind

- Look out for edge cases! If things are 1-indexed, you can either leave them be by just increasing the array size (usually a good habit to have regardless), or you can 0-index them as necessary

- Look out for integer overflow! Use long long (64-bit integer type) if necessary (usually indicated by the problem)

- Try small cases or special cases

- Add single or multiline comments to keep track of what you are doing

- Debugging: add print statements (use what(x) in the template or some variant), watch out for segmentation faults (accessing out of bounds memory or too much memory), literally rewrite code as a last resort

- Stay organized and do not panic

## Time Complexity
Design Efficient Algorithms 

Time complexity is usually not much of a worry for bronze, but for silver and beyond, it is critical that algorithms are designed to appropriate time complexities (adhering to the bounds of the various variables in the problem statement). 

In general, by way of notation, define the time complexity ![O(f(n_1, n_2, \dots, n_k))](https://render.githubusercontent.com/render/math?math=O(f(n_1%2C%20n_2%2C%20%5Cdots%2C%20n_k))) to mean that the number of operations in a program (and therefore its runtime) is proportional to ![f(n_1, n_2, \dots, n_k)](https://render.githubusercontent.com/render/math?math=f(n_1%2C%20n_2%2C%20%5Cdots%2C%20n_k)), where all arguments in the function are some variables described in the problem relevant to its solution. 

USACO allows roughly ![10^8](https://render.githubusercontent.com/render/math?math=10%5E8) operations per three second. This means that roughly a third of ![10^8](https://render.githubusercontent.com/render/math?math=10%5E8) is the upper bound on the number of operations your implementation should execute. The exact upper bound is determined by what exactly constitutes an "operation." 

## Space/Memory Complexity

Not much to say here, but as far as USACO is concerned, your limit is 256MB unless otherwise noted. This means "2.46 e+8" bytes as an absolute upper bound, meaning that your memory usage should certainly be less. Here is a handy table to check what kinds of arrays you might be able to declare in terms of size. You can multiply the size in bytes of a single datatype by the number of datatypes in the overall array (essentially its size):

- Bool: 1 byte (if you use bitset, you can make this 1 bit)
- Char: 1 byte
- Int: 4 bytes
- Float: 4 bytes
- Double: 8 bytes
- Long Double: 16 Bytes
- Long Long: 8 bytes

You don't need to memorize these. You can check them directly: 
```cpp
cout << sizeof(typename) << "\n";
```

For instance, 
```cpp
cout << sizeof(float) << "\n";
```
gives 4. 

Look into bitsets and sliding window for more memory optimization tricks. 

## Questions/Suggestions

Email me at sendtoaryansh@gmail.com in the event that you have a detailed question that has not already been addressed here or elsewhere completely. Suggestions are welcome here as well! Otherwise, the above and general resources (Google) should be more than enough. 
