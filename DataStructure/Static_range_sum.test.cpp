#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include "../template.h"
#include "Fenwick/Fenwick.h"

void solve() {
    int n, q; cin >> n >> q;
    Fenwick<ll> BIT(n);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        BIT.update(i, x);
    }
    while (q--) {
        int l, r; cin >> l >> r;
        cout << BIT.get(l+1, r) << '\n';
    }
}