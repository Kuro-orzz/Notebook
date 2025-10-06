#define PROBLEM "https://judge.yosupo.jp/problem/range_reverse_range_sum"

#include "../../template.h"
#include "../SqrtDecomposition/Split_Rebuild/Simplified_version.h"

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    Sqrt sqrt(n, a);
    sqrt.rebuild();
    while (q--) {
        if (sqrt.blockId.size() > 3000) sqrt.rebuild_if_need();
        int type, l, r; cin >> type >> l >> r;
        l++;
        if (type == 0) {
            sqrt.Reverse(l, r);
        } else if (type == 1) {
            cout << sqrt.sum(l, r) << '\n';
        }
    }
}