# Segment Tree Library

Iterative segment trees
- short, simple, and efficient compared to recursive

## Description
Easy segment trees for general use 
- "iterativesegtree.cpp" : Point Update, Range Query 
- "rng_upd_pt_qry.cpp" : Range Update, Point Query (Order Matters)

### Todo
- simple lazy prop

## Memory

Memory provides a strong advantage -- no more than twice N is used, with thrice N in the lazy case. Memory allocation is taken care of in init functions for the sake of vectors and arrays, although seg is always stored as a vector regardless due to flexibility. 


