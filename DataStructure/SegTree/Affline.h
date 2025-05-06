#include "../../template.h"

template <typename T>
struct AfflineSegTree {
	vector<T> st;
    vector<pll> lazy;

    AfflineSegTree() {}
    AfflineSegTree(int n): st(n*4), lazy(n*4) {}

    void build(int id, int l, int r, const vector<ll> &a) {
        lazy[id] = {1, 0};
        if (l == r) {
            st[id] = a[l] % mod;
            return;
        }
        int m = (l + r) >> 1;
        build(id*2, l, m, a);
        build(id*2+1, m+1, r, a);
        st[id] = (st[id*2] + st[id*2+1]) % mod;
    }

    void push(int id, int l, int r) {
        if (lazy[id] == make_pair(1ll*1, 1ll*0)) return;
        int m = (l + r) >> 1;
        st[id*2] = st[id*2] * lazy[id].fi % mod + lazy[id].se * (m-l+1) % mod;
        st[id*2] %= mod;
        st[id*2+1] = st[id*2+1] * lazy[id].fi % mod + lazy[id].se * (r-m) % mod;
        st[id*2+1] %= mod;
        setLazy(id*2, lazy[id]);
        setLazy(id*2+1, lazy[id]);
        lazy[id] = {1, 0};
    }

    void setLazy(int id, pll val) {
        lazy[id].fi = lazy[id].fi * val.fi % mod;
        lazy[id].se = (lazy[id].se * val.fi % mod + val.se) % mod;
    }

    void update(int id, int l, int r, int u, int v, pll val) {
        if (v < l || u > r)
            return;
        if (u <= l && v >= r) {
            st[id] = (st[id] * val.fi % mod + val.se * (r-l+1) % mod) % mod;
            setLazy(id, val);
            return;
        }
        push(id, l, r);
        int mid = (l + r) >> 1;
        update(id*2, l, mid, u, v, val);
        update(id*2+1, mid+1, r, u, v, val);
        st[id] = (st[id*2] + st[id*2+1]) % mod;
    }

    T getSumMod(int id, int l, int r, int u, int v) {
        if (l > v || r < u) return 0;
        if (l >= u && r <= v) return st[id];
        int mid = (l + r) >> 1;
        push(id, l, r);
        T t1 = getSumMod(id*2, l, mid, u, v) % mod;
        T t2 = getSumMod(id*2+1, mid+1, r, u, v) % mod;
        return (t1 + t2) % mod;
    }
};