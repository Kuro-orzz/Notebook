#include "../../template.h"

template <typename T>
struct LazySegTree{
	vector<T> st, lazy;

    LazySegTree(int n): st(n*4), lazy(n*4) {}


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

    void push(int id) {
        if (lazy[id]) {
            st[id*2] += lazy[id];
            st[id*2+1] += lazy[id];
            lazy[id*2] += lazy[id];
            lazy[id*2+1] += lazy[id];
            lazy[id] = 0;
        }
    }

    T getSum(int id, int l, int r, int u, int v) {
        if (r < u || v < l)
            return 0;
        if (u <= l && v >= r)
            return st[id];
        push(id);
        int mid = (l + r) >> 1;
        T t1 = getSum(id*2, l, mid, u, v);
        T t2 = getSum(id*2+1, mid+1, r, u, v);
        return t1 + t2;
    }
};