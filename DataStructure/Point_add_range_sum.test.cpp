#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../template.h"
#include "SegTree/SegTree.h"

void solve() {
    int n, q; cin >> n >> q;
    SegTree<ll> segTree(n);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        segTree.update(1, 1, n, i, x);
    }
    while (q--) {
        int tv; cin >> tv;
        if (tv == 0) {
            int pos, val; cin >> pos >> val;
            segTree.update(1, 1, n, pos+1, val);
        } else {
            int l, r; cin >> l >> r;
            cout << segTree.getSum(1, 1, n, l+1, r) << '\n';
        }
    }
}