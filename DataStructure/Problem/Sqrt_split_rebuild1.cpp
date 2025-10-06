/*    AC: https://www.e-olymp.com/en/problems/2961    */

#include "../../template.h"
#include "../SqrtDecomposition/Split_Rebuild/Full_version.h"

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    Sqrt sqrt(n, a);
    sqrt.rebuild();
    int q; cin >> q;
    while (q--) {
        if (sqrt.blockId.size() > 3000) sqrt.rebuild_if_need();
        string type; cin >> type;
        int l, r; cin >> l >> r;
        if (type == "get") {
            int x; cin >> x;
            cout << sqrt.numGreater(l, r, x) << '\n';
        } else if (type == "set") {
            int x; cin >> x;
            sqrt.set(l, r, x);
        } else if (type == "reverse") {
            sqrt.Reverse(l, r);
        }
    }
}