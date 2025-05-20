#include "../../template.h"

template <typename T>
struct SegTree {
    int n;
    vector<T> tree;

    SegTree() {}
    SegTree(int _n): n(_n), tree(_n*4) {}

    void update(int pos, T val) {
        update(1, 1, n, pos, val);
    }

    T getSum(int u, int v) {
        return getSum(1, 1, n, u, v);
    }

    void update(int id, int l, int r, int pos, T val) {
        if (pos < l || pos > r) return;
        if (l == r) {
            tree[id] += val;
            return;
        }
        int mid = (l + r) >> 1;
        update(id*2, l, mid, pos, val);
        update(id*2+1, mid+1, r, pos, val);
        tree[id] = tree[id*2] + tree[id*2+1];
    }

    T getSum(int id, int l, int r, int u, int v) {
        if (l > v || r < u) return 0;
        if (l >= u && r <= v) return tree[id];
        int mid = (l + r) >> 1;
        T t1 = getSum(id*2, l, mid, u, v);
        T t2 = getSum(id*2+1, mid+1, r, u, v);
        return t1 + t2;
    }
};