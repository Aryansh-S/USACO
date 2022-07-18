## Description

Up-to-date, original, and comprehensive implementations of algorithms and data structures for each USACO division from bronze to gold based on classifications from the [Unofficial USACO Syllabus](https://www.overleaf.com/read/fktckfprxyxn). Code should be neat, but indentation may be somewhat inconsistent between implementations (GitHub's fault). Currently a WIP. 

Study these thoroughly to do well! Don't just memorize the implementation -- seek to understand why it works. The intuition behind why could be useful for problems where these implementations can't be applied directly. 

## Updates

(07/11/22) Under daily construction.

(07/11/22) Finished bronze.

(07/13/22) Almost finished silver (just sweep line left). 

## Note on Use

USACO no longer allows prewritten code. As such, you may not directly copy and paste code from these files in contest. Instead, I recommend committing the important features of these implementations to memory through constant practice writing them from scratch. However, if you'd like to use this code on another platform that allows prewritten code (e.g., Codeforces), or just in your practice USACO submissions, please include a comment like the following near the top of the file:

```cpp
// credit: https://github.com/Aryansh-S/USACO/blob/main/algo_by_div/silver.cpp (adjacency list and dfs implementations)
```

## FAQ

> Can I just copy and paste these whenever I want? 

See "Note on Use" above.

> Can you add X, remove X, change X, etc.?

> I have a question/concern not answered by the FAQ. 

Please create an issue including your request. I'll get to it as soon as possible. Or, if you're willing to write the code yourself, please submit a pull request.

> How can I tell if an implementation will run in time? 

This is where big $\mathcal{O}$ asymptotic time complexity analysis comes in. In the comment preceding each implementation, I've included that implementation's big $\mathcal{O}$ time complexity (basically an approximation for the number of operations the implementation takes as a function of the variables it uses, accounting for only the highest order terms and ignoring constant factors). As is common in computer science, the logarithm without a base ($\log$) denotes the binary logarithm $\log_2.$ As a rule of thumb for USACO, C++ can handle on the order of $10^8$ fundamental operations per second. Accordingly, get familiar with some common time complexity bounds: 

| Bounds | Complexity | Example Algorithms |
| --- | --- | --- |
| $n \leq 10$ | $\subseteq \mathcal{O}(n!), \mathcal{O}(n^6)$ | trying all permutations
| $n \leq 18$ | $\subseteq \mathcal{O}(2^n \cdot n^2)$ |
| $n \leq 22$ | $\subseteq \mathcal{O}(2^n \cdot n)$ | trying all subsets
| $n \leq 100$ | $\subseteq \mathcal{O}(n^4)$ |
| $n \leq 400$ | $\subseteq \mathcal{O}(n^3)$ | Floyd Warshall
| $n \leq 2 \cdot 10^3$ | $\subseteq \mathcal{O}(n^2 \log n)$ | $\mathcal{O}(n^2)$ operations with a tree data structure
| $n \leq 10^4$ | $\subseteq \mathcal{O}(n^2)$ | trying all pairs
| $n \leq 2 \cdot 10^5$ | $\subseteq \mathcal{O}(n \log n)$\* | sorting, binary searching, using a tree data structure
| substantially large $n$ | $\subseteq \mathcal{O}(n), \mathcal{O}(\log n), \mathcal{O}(1)$ | deriving a closed form in $n$ by hand using math

\* probably the most common one in USACO

In some cases, asymptotic analysis won't cut it and your implementation may still exceed the time limit by a small margin. Then, we'll have to optimize the constant factor of the implementation. As a rule of thumb, more complex data structures produce higher constant factors. For instance, even though sorting an array of $n$ elements and adding $n$ elements to a set are both $\mathcal{O}(n \log n)$ procedures, the latter procedure will be slower (and require more memory) as sets are quite complex under the hood: they're actually binary search trees.

> What versions of C++ are compatible with these implementations? 

I guarantee compatibility with C++17 and above across all implementations, though some might also work with C++14 or C++11. For the most part, if the implementation compiles, you should be fine. 

> If you say you've finished a division, how come its file is still being updated? 

Having finished a division just means I'm done with all the necessary implementations. I might update comments or reorder stuff, but the implementations will remain the same.

> According to X, Y isn't in the Z division. Why do you have it there?

X seems to be the problem. I'm using classifications from the [Unofficial USACO Syllabus](https://www.overleaf.com/read/fktckfprxyxn), which represents what I believe, not X.

> Why not use templates to make these implementations more generic?

As much as I love metaprogramming, I do this to keep the implementations beginner-friendly. Templates may encourage blackboxing, because it's inconvenient to write templated code from scratch, and blackboxing is detrimental to beginners. Moreover, avoiding templates keeps the implementations simple and instructive.

> How do the implementations here differ from ones in other parts of the repository? 

> I've seen other repositories with implementations for algorithms and data structures. What's unique about this one?

The other implementations, though functional, are generally longer and more disorganized, using an unnecessary amount of macros and templates to shorten code. The implementations here are equally (if not more) functional but also concise and organized, not resorting to macros and templates. A big part of the uniqueness also comes from the *classification* into divisions.

> Why do you use the array class in your implementations instead of pairs or tuples?

Pairs are limited to two elements and make you do ``.first`` and ``.second`` (and nesting them involves convoluted stuff like ``.second.first``), and tuples have something weird involving ``get``. On the other hand, arrays have indexing and convenient syntax. So, even if pairs and tuples are more popular, I prefer arrays.

> I notice you use the auto keyword a lot. Why don't you also make the return type in each function signature auto?

Some people use the auto keyword blindly whenever they can get away with it. However, these are the circumstances under which I use the auto keyword:

* to save typing whenever the type being replaced is obvious and otherwise cumbersome to type
* when the type is meant to be generic (inferred)

I generally want my function signatures to be intuitive, ideally such that the name, parameters, and return type alone make it fairly obvious what the function does and how it should be used. That's why I write out the return type instead of using the auto keyword.

> Why don't you use bitsets?

> When can using bitsets help speed up these implementations? 

Yes, there are some implementations that could be optimized by at least a constant factor using bitsets, and other cases where bitsets have even allowed $\mathcal{O}(n^2)$ solutions to run in comparable time to $\mathcal{O}(n \log n)$ solutions. But, to keep things simple and beginner-friendly, I didn't use bitsets (bitsets are commonly seen as a more advanced technique in competitive programming, most prevalent in situations where constant factor optimization is important). However, if you'd like to learn about bitsets and modify some of these implementations using bitsets for your own use, [this](https://www.youtube.com/watch?v=jqJ5s077OKo) is a fantastic video. 

***

And a final important one unrelated to implementations:

> Where do I go to actually learn the algorithms and data structures you've implemented here? 

You're right: these are just implementations, and while they have some explanatory comments attached to them, they don't formally teach the concepts. A good starting point is googling the names of concepts to find relevant articles and videos. I would recommend steering clear of GeeksforGeeks -- they're infamous for bad explanations and faulty, verbose code. Check these out instead:
* [USACO Guide modules to find links to articles that explain topics particularly well](https://usaco.guide/)
* [CP Algorithms explanations](https://cp-algorithms.com/)
* [Wikipedia pages on algorithms and data structures](https://www.wikipedia.org/)
* [Codeforces blogs for niche explanations](https://codeforces.com/)
* Free textbooks like [the CSES book](https://cses.fi/book/book.pdf) or [Darren's USACO textbook](https://darrenyao.com/usacobook/cpp.pdf), or another competitive programming textbook (such as [CP4](https://www.amazon.com/Book-1-Halim-Effendy/dp/B093G64LY2/ref=pd_bxgy_img_sccl_1/143-4553352-2969865?pd_rd_w=ZVzqJ&content-id=amzn1.sym.7757a8b5-874e-4a67-9d85-54ed32f01737&pf_rd_p=7757a8b5-874e-4a67-9d85-54ed32f01737&pf_rd_r=Q5W2JNW0VG2T9PED3MAG&pd_rd_wg=5wu3V&pd_rd_r=2d8e2bcf-dd6f-49e1-8697-ed70d93360ee&pd_rd_i=B093G64LY2&psc=1))
