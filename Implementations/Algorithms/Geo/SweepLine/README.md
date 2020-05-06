Sweep Line

Ah yes, the dreaded sweep line (plane sweep) approach. Although the algorithm itself is quite beautiful, a great many 
implementations of it get very messy and complicated. 

Here, I have written the cleanest possible approach of sweep line that I have ever seen in personal experience, so hopefully
this can be helpful. The problem at hand is finding the smallest distance between two points, but we can easily modify the 
approach to solve a vast set of challenging problems. 

Prerequisites: 
- Two-Pointer Approach (Used Lightly)
- Euclidean Distance (Used Heavily)
- Balanced Binary Search Trees (Used Heavily)

First, what is sweep line, and when do we use it? 

Suppose we are given a certain locus of data; call the elements of this locus points for simplicity (in practice, they could be other geometric objects as well: lines are the most common after actual points). We want to check a certain property among pairs of these points. 

Naive Algorithm: This is the algorithm you could come up with almost immediately. We can nest two for loops and check all pairs in quadratic time. 

But, the larger the size of the locus, the less likely quadratic time is to cut it. We want to come up with, say, a linear to log-linear time approach. 

We first make the following observations: 
- Imagine sorting the points by first coordinate and laying them across a line; disregard the notion of height for now. For each point, we can choose to consider only points behind (or to the left) of it. This will prune by merely a constant factor, but it is progress. How can we prune further?
- There will be numerous points to the left of our current point that no longer matter, for these points are simply too far away even when just considering the first coordinate. We can omit these from the set of points we care about. If we keep this set running throughout our search, since each point will only be added and removed at most once in our sorting scheme, this is an amortized constant operation. 

This is significant progress, but now we must account for height. For this, we might keep an "active" set of points within a satisfactory range above and below the current point. For instance, given the metric of distance and a current point with height Y, we need to consider heights from only Y-D to Y+D. Of course, we can find our range if we binary search the set. 

This gives us the following: 
- Sort the points in the locus by first coordinate in a separate linear container initially. This container can be a vector or an array, for instance. 
- Maintain an "active" balanced binary search tree (or set in this case) with sorting comparison operator based on the second coordinate of the points in the locus. To see how sorting comparison operators work in C++, look at the struct "cmps" towards the top of my implementation code. 
- We will always remove all points too far left of the current point from our active set, binary search from the bottom to top of our height-based active set for a certain metric (possibly closest distance), and keep a running tally of the closest distance. 
- At most, each point can enter the active set once and exit once. This means that we achieve log-linear time given the insertion specifics of a balanced binary search tree. 
