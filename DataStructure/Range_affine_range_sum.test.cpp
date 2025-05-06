#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include "../template.h"
#include "SegTree/Affline.h"

void solve() {
	int n, q; cin >> n >> q;
	AfflineSegTree<ll> st(n);
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		st.update(1, 1, n, i, i, make_pair(0, x));
	}
	while (q--) {
		int tv, l, r; cin >> tv >> l >> r;
		if (tv == 0) {
			ll b, c; cin >> b >> c;
			st.update(1, 1, n, l+1, r, make_pair(b, c));
		} else if (tv == 1) {
			cout << st.getSum(1, 1, n, l+1, r) << '\n';
		}
	}
}