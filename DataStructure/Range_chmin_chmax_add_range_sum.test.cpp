#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"

#include "../template.h"
#include "SegTree/SegTreeBeats/SegTreeBeats3.h"

void solve() {
	int n, q; cin >> n >> q;
	SegTreeBeats st(n);
	for (int i = 1; i <= n; i++) {
		ll x; cin >> x;
		st.build(1, 1, n, i, x);
	}
	while (q--) {
		int type, l, r; cin >> type >> l >> r;
		if (type == 0) {
			ll b; cin >> b;
			st.updateChmin(1, 1, n, l+1, r, b);
		} else if (type == 1) {
			ll b; cin >> b;
			st.updateChmax(1, 1, n, l+1, r, b);
		} else if (type == 2) {
			ll b; cin >> b;
			st.updateRange(1, 1, n, l+1, r, b);
		} else if (type == 3) {
			cout << st.getSum(1, 1, n, l+1, r) << '\n';
		}		
	}
}