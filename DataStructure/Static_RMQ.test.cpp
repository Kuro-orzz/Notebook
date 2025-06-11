#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../template.h"
#include "RMQ/RMQ.h"

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    RMQ<int> rmq(n);
    rmq.preprocess(a);
    while (q--) {
        int l, r; cin >> l >> r;
        cout << rmq.queryMin(l+1, r) << '\n';
    }
}