#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B"

#include "../../template.h"
#include "../DSU/Weighted_Dsu.h"

void solve() {
    int n, q; cin >> n >> q;
    WeightedDsu g(n);
    while (q--) {
        int type; cin >> type;
        if (type == 0) {
            int x, y, z; cin >> x >> y >> z;
            g.merge(x, y, z);
        } else if (type == 1) {
            int x, y; cin >> x >> y;
            int res = g.getDiff(x, y);
            if (res != INT_MAX) {
                cout << res << '\n';
            } else {
                cout << "?\n";
            }
        }
    }
}