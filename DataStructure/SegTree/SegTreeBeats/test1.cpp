// https://codeforces.com/problemset/problem/438/D

#include "../../../template.h"
#include "SegTreeBeats1.h"

void solve() {
    int n, m; cin >> n >> m;
    SegTreeBeats st(n);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        st.build(1, 1, n, i, i, x);
    }
    while (m--) {
        int type; cin >> type;
        if (type == 1) {
            int l, r; cin >> l >> r;
            cout << st.getSum(1, 1, n, l, r) << '\n';
        } else if (type == 2) {
            int l, r, x; cin >> l >> r >> x;
            st.updateMod(1, 1, n, l, r, x);
        } else if (type == 3) {
            int k, x; cin >> k >> x;
            st.build(1, 1, n, k, k, x);
        }
    }
}