#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_point_get"

#include "../template.h"
#include "SegTree/Affline.h"

void solve() {
	int n, q; cin >> n >> q;
	vector<ll> a(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	AfflineSegTree<ll> st(n);
	st.build(1, 1, n, a);
	while (q--) {
		int tv; cin >> tv;
		if (tv == 0) {
			ll l, r, b, c; cin >> l >> r >> b >> c;
			st.update(1, 1, n, l+1, r, make_pair(b, c));
		} else if (tv == 1) {
			int i; cin >> i;
			cout << st.getSumMod(1, 1, n, i+1, i+1) << '\n';
		}
	}
}