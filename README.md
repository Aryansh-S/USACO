# USACO
Competitive Programming Resources &amp; Implementations

This is a compilation of resources and implementations for contest programming -- algorithms and past problems for USACO.
You can find the latest version of my contest programming template (ongoing modification) in "template.cpp"; please credit
before use in-contest. 
If you want to #include <bits/stdc++.h> but your compiler does not allow you to do so, simply go to the file "stdc++.h" and
follow the unofficial directions at the top. 
The "src" folder just contains source files and images that are integrated elsewhere; you can ignore it. 

# Time Complexity
Design Efficient Algorithms 

Time complexity is usually not much of a worry for bronze, but for silver and beyond, it is critical that algorithms are designed to appropriate time complexities (adhering to the bounds of the various variables in the problem statement). 

In general, by way of notation, define the time complexity ![O(f(n_1, n_2, \dots, n_k))](https://render.githubusercontent.com/render/math?math=O(f(n_1%2C%20n_2%2C%20%5Cdots%2C%20n_k))) to mean that the number of operations in a program (and therefore its runtime) is proportional to ![f(n_1, n_2, \dots, n_k)](https://render.githubusercontent.com/render/math?math=f(n_1%2C%20n_2%2C%20%5Cdots%2C%20n_k)), where all arguments in the function are some variables described in the problem relevant to its solution. 

USACO allows roughly ![10^8](https://render.githubusercontent.com/render/math?math=10%5E8) operations per second. This means that ![10^8](https://render.githubusercontent.com/render/math?math=10%5E8) is the upper bound on the number of operations your implementation should execute. 

Below is helpful information in the context of contest programming (credit~CP3): 
![](https://github.com/Aryansh-S/USACO/blob/master/src/Screen%20Shot%202020-04-16%20at%204.10.43%20PM.png)
![](https://github.com/Aryansh-S/USACO/blob/master/src/Screen%20Shot%202020-04-16%20at%204.11.02%20PM.png)
![](https://github.com/Aryansh-S/USACO/blob/master/src/Screen%20Shot%202020-04-16%20at%204.11.23%20PM.png)
