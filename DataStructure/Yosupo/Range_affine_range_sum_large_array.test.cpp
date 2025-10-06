#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum_large_array"

#include "../../template.h"
#include "../SegTree/SparseSegTree.h"

void solve() {
    int n, q; cin >> n >> q;
    SparseSegTree st(n);
    while (q--) {
        int tv, l, r; cin >> tv >> l >> r;
        if (tv == 0) {
            ll b, c; cin >> b >> c;
            st.update(l+1, r, {b, c});
        } else if (tv == 1) {
            cout << st.query(l+1, r) << '\n';
        }
    }
}