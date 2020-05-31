# Ultimate Segment Tree Library 
The segment tree is one of the most versatile structures in all of contest programming. The intuition behind the innerworkings
is fairly simple compared to that of a Fenwick Tree. Yet, unfortunately, segment trees are not so easy to implement. 

The goal of this library is to create the most generic, extensible segment tree data structures around, bridging the gap 
between implementation difficulty and solution.

Full support for point and range updates is provided based on perfected, optimized lazy propagation. 

Implementation Notes:
- One-indexing is required
- Avoid powers of two in base array size
- Leaf nodes are in .values index range ![\[n-1, 2n-2\]](https://render.githubusercontent.com/render/math?math=%5Bn-1%2C%202n-2%5D)
-- This is helpful for binary search, i.e. always take leftmost RMQ until leaf node, doing ![\log n](https://render.githubusercontent.com/render/math?math=%5Clog%20n) queries of complexity ![\log n](https://render.githubusercontent.com/render/math?math=%5Clog%20n) each for a total of ![\log ^2 n](https://render.githubusercontent.com/render/math?math=%5Clog%20%5E2%20n). 

## Abstract Algebra Concept

The idea behind this is that any segment tree can be concisely represented as a closed associative algebraic space, or monoid, on its nodes, whereafter any "update" becomes a functional endomorphism on ranges of nodes. 
- For ease of use, I have premade several monoids and endomorphisms in the namespace.

## Updating

All code updates will be added directly to the main library file! Examples are not necessarily updated.
