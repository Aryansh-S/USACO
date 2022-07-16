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

> If you say you've finished a division, how come its file is still being updated? 

Having finished a division just means I'm done with all the necessary implementations. I might update comments or reorder stuff, but the implementations will remain the same.

> According to X, Y isn't in the Z division. Why do you have it there?

X seems to be the problem. I'm using classifications from the [Unofficial USACO Syllabus](https://www.overleaf.com/read/fktckfprxyxn), which represents what I believe, not X.

> Why not use templates to make these implementations more generic?

As much as I love metaprogramming, I do this to keep the implementations beginner-friendly. Templates may encourage blackboxing, because it's inconvenient to write templated code from scratch, and blackboxing is detrimental to beginners. Moreover, avoiding templates keeps the implementations simple and instructive.

> Why do you use the array class in your implementations instead of pairs or tuples?

Pairs are limited to two elements and make you do ``.first`` and ``.second`` (and nesting them involves convoluted stuff like ``.second.first``), and tuples have something weird involving ``get``. On the other hand, arrays have indexing and convenient syntax.
