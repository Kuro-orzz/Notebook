#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum_large_array"

#include "../template.h"
#include "../Misc/Compress.h"
#include "SegTree/Affline.h"

struct Query {
	ll tv, l, r, b, c;
};

void solve() {
	int n, q; cin >> n >> q;
	vector<Query> a;
	for (int i = 0; i < q; i++) {
		Query x;
		cin >> x.tv >> x.l >> x.r;
		if (x.tv == 0) cin >> x.b >> x.c;
		x.l++;
		a.push_back(x);
	}
	vector<ll> v;
	for (Query it : a) {
		v.push_back(it.l);
		v.push_back(it.r);
		v.push_back(it.r+1);
	}
	Compress<ll> query(v);
	n = (int)query.decompress.size()-1;
	AfflineSegTree<ll> st(n, query.decompress);
	for (int i = 0; i < q; i++) {
		int l = query.compressed[a[i].l];
		int r = query.compressed[a[i].r]-1;
		if (a[i].tv == 0) {
			st.update(1, 1, n, l, r, make_pair(a[i].b, a[i].c));
		} else if (a[i].tv == 1) {
			cout << st.getSumMod(1, 1, n, l, r) << '\n';
		}

	}
}