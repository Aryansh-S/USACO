## Time Complexity
Design Efficient Algorithms 

Time complexity is usually not much of a worry for bronze, but for silver and beyond, it is critical that algorithms are designed to appropriate time complexities (adhering to the bounds of the various variables in the problem statement). 

In general, by way of notation, define the time complexity ![O(f(n_1, n_2, \dots, n_k))](https://render.githubusercontent.com/render/math?math=O(f(n_1%2C%20n_2%2C%20%5Cdots%2C%20n_k))) to mean that the number of operations in a program (and therefore its runtime) is proportional to ![f(n_1, n_2, \dots, n_k)](https://render.githubusercontent.com/render/math?math=f(n_1%2C%20n_2%2C%20%5Cdots%2C%20n_k)), where all arguments in the function are some variables described in the problem relevant to its solution. 

USACO allows roughly ![10^8](https://render.githubusercontent.com/render/math?math=10%5E8) operations per three second. This means that roughly a third of ![10^8](https://render.githubusercontent.com/render/math?math=10%5E8) is the upper bound on the number of operations your implementation should execute. The exact upper bound is determined by what exactly constitutes an "operation." 

## Space/Memory Complexity

Not much to say here, but as far as USACO is concerned, your limit is 256MB unless otherwise noted. This means "2.46 e+8" bytes as an absolute upper bound, meaning that your memory usage should certainly be less. Here is a handy table to check what kinds of arrays you might be able to declare in terms of size. You can multiply the size in bytes of a single datatype by the number of datatypes in the overall array (essentially its size)...

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
