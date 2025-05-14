#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../../template.h"
#include "Sqrt.h"

void solve() {
	int n, q; cin >> n >> q;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	SimpleSqrt Sqrt(n, a);
	while (q--) {
		int tv; cin >> tv;
		if (tv == 0) {
			int pos, val; cin >> pos >> val;
			Sqrt.add(pos, val);
		} else {
			int l, r; cin >> l >> r;
			cout << Sqrt.query(l, r-1) << '\n';
		}
	}
}