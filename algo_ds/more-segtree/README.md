# More Segment Trees

## Memory

Memory provides a strong advantage given iterative -- no more than twice N is used, with thrice N in the lazy case. Memory allocation is taken care of in init functions for the sake of vectors and arrays, although seg is always stored as a vector regardless due to flexibility. 
- Good idea to use next closest power of 2 round up if binary searching, ordered statistics, etc. 
- Every index from N and on in the seg vector is guaranteed to contain a leaf node
