#include "../../template.h"

template <typename T>
struct SegTree {
	vector<T> sum;

	SegTree() {}
	SegTree(int n): sum(n*4) {}

	void update(int id, int l, int r, int pos, T val) {
		if (pos < l || pos > r) return;
		if (l == r) {
			sum[id] += val;
			return;
		}
		int mid = (l + r) >> 1;
		update(id*2, l, mid, pos, val);
		update(id*2+1, mid+1, r, pos, val);
		sum[id] = sum[id*2] + sum[id*2+1];
	}

	T getSum(int id, int l, int r, int u, int v) {
		if (l > v || r < u) return 0;
		if (l >= u && r <= v) return sum[id];
		int mid = (l + r) >> 1;
		T t1 = getSum(id*2, l, mid, u, v);
		T t2 = getSum(id*2+1, mid+1, r, u, v);
		return t1 + t2;
	}
};