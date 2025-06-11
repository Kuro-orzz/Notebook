// #define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include "../template.h"

const int mod = 998244353;

vector<int> a, b;

int calc(int l, int r, int x) {
    if (l == r) return (1ll * a[l] * x + b[l]) % mod;
    return (1ll * a[r] * calc(l, r-1, x) + b[r]) % mod;
}

void solve() {
    int n, q; cin >> n >> q;
    a.resize(n);
    b.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    while (q--) {
        int tv; cin >> tv;
        if (tv == 0) {
            int p, c, d; cin >> p >> c >> d;
            a[p] = c;
            b[p] = d;
        } else {
            int l, r, x; cin >> l >> r >> x;
            cout << calc(l, r-1, x) << '\n';
        }
    }
}