// https://codeforces.com/group/1rv4rhCsHp/contest/327313/problem/B

#include "../../template.h"
#include "../SegTree/SegTreeBeats2.h"

void solve() {
    int n; cin >> n;
    SegTreeBeats st(n+1);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        st.build(1, 1, n, i, i, x);
    }
    int q; cin >> q;
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int l, r, x; cin >> l >> r >> x;
            st.updateChmin(1, 1, n, l, r, x);
        } else if (type == 2) {
            int l, r; cin >> l >> r;
            cout << st.getSum(1, 1, n, l, r) << '\n';
        }
    }
}