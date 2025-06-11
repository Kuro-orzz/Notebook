#define PROBLEM "https://judge.yosupo.jp/problem/ordered_set"

#include "../template.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n, q; cin >> n >> q;
    ordered_set s;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        s.insert(x);
    }
    while (q--) {
        int tv, x; cin >> tv >> x;
        if (tv == 0) {
            s.insert(x);
        } else if (tv == 1) {
            s.erase(x);
        } else if (tv == 2) {
            if (x > (int)s.size()) cout << "-1\n";
            else cout << *s.find_by_order(x-1) << '\n';
        } else if (tv == 3) {
            cout << s.order_of_key(x+1) << '\n';
        } else if (tv == 4) {
            int idx = s.order_of_key(x+1);
            if (idx == 0) cout << "-1\n";
            else cout << *s.find_by_order(idx-1) << '\n';
        } else if (tv == 5) {
            int idx = s.order_of_key(x);
            if (idx == (int)s.size()) cout << "-1\n";
            else cout << *s.find_by_order(idx) << '\n';
        }
    }
}