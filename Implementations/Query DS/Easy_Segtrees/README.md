# Segment Tree Library

Iterative segment trees
- short, simple, and efficient compared to recursive
- "demonstrationals" folder helps visualize precise node allocation
- imperfect binary trees become multiple binary trees; we have a family and don't require a perfect power of 2

**But using a power of 2 for binary search, ordered statistics, etc. is highly recommended because it is easier to keep track of individual levels (guarantees a single tree, not a family)**
- using the iterative version with a perfect power of 2 happens to be much cleaner than having to deal with the recursive version at any rate

## Description
Easy segment trees for general use 
- "seglib.h"

### Todo
- simple lazy prop
  - range assignment 
  - range operation

## Memory

Memory provides a strong advantage -- no more than twice N is used, with thrice N in the lazy case. Memory allocation is taken care of in init functions for the sake of vectors and arrays, although seg is always stored as a vector regardless due to flexibility. 
- Good idea to use next closest power of 2 round up if binary searching, ordered statistics, etc. 
- Every index from N and on in the seg vector is guaranteed to contain a leaf node