//helper function if needed to balance the tree for binary search, etc.

int nxtp2(int v) { //next power 2
    --v;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    return ++v;
}
