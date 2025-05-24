/*    AC: https://oj.vnoi.info/problem/sqrt_b    */

#include "../../../template.h"
#include "Simplified_version.h"

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
        if (type == 1) {
            sqrt.Reverse(l, r);
        } else if (type == 2) {
            cout << sqrt.sum(l, r) << '\n';
        }
    }
}