#include "../../template.h"

template <typename T>
struct LazySegTree {
    vector<T> st, lazy;

    LazySegTree() {}
    LazySegTree(int n): st(n*4), lazy(n*4) {}

    void push(int id) {
        if (lazy[id]) {
            st[id*2] += lazy[id];
            st[id*2+1] += lazy[id];
            lazy[id*2] += lazy[id];
            lazy[id*2+1] += lazy[id];
            lazy[id] = 0;
        }
    }

    void update(int id, int l, int r, int u, int v, T val) {
        if (v < l || u > r)
            return;
        if (u <= l && v >= r) {
            st[id] += val;
            lazy[id] += val;
            return;
        }
        push(id);
        int mid = (l + r) >> 1;
        update(id*2, l, mid, u, v, val);
        update(id*2+1, mid+1, r, u, v, val);
        st[id] = st[id*2] + st[id*2+1];
    }

    T getSum(int id, int l, int r, int u, int v) {
        if (l > v || r < u) return 0;
        if (l >= u && r <= v) return st[id];
        int mid = (l + r) >> 1;
        push(id);
        T t1 = getSum(id*2, l, mid, u, v);
        T t2 = getSum(id*2+1, mid+1, r, u, v);
        return t1 + t2;
    }

    T getSumMod(int id, int l, int r, int u, int v) {
        if (l > v || r < u) return 0;
        if (l >= u && r <= v) return st[id];
        int mid = (l + r) >> 1;
        push(id);
        T t1 = getSum(id*2, l, mid, u, v) % mod;
        T t2 = getSum(id*2+1, mid+1, r, u, v) % mod;
        return (t1 + t2) % mod;
    }
};