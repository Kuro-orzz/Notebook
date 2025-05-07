#include "../../template.h"


struct Data {
	ll val = 0;
	ll sz = 0;
	Data() {}
	Data(ll x) {
		this->sz = 1;
		val = x * sz;
	}
	Data(ll x, ll L, ll R) {
		this->sz = R-L+1;
		val = x * sz;
	}
	void upd(Data x) {this->val = x.val * sz;}
	static Data merge(Data a, Data b) {
		Data res;
		res.val = a.val + b.val;
		res.sz = a.sz + b.sz;
		return res;
	}
};

struct Tree {
	Tree *left = 0, *right = 0;
	ll l, r;
	Data d;

	Tree(int L, int R) {l = L, r = R;}
	~Tree() {
		delete left;
		delete right;
	}

	void update(int u, int v, Data x) {
		if (l > v || r < u) return;
		if (u <= l && r <= v) {
			d.upd(x);
			return;
		}
		ll mid = (l + r) >> 1;
		if (u <= mid) {
			if (!left) left = new Tree(l, mid);
			left->update(u, v, x);
		}
		if (v >= mid+1){
			if (!right) right = new Tree(mid+1, r);
			right->update(u, v, x);
		}
		Data t1 = left ? left->d : Data(0, l, mid);
		Data t2 = right ? right->d : Data(0, mid+1, r);
		d = Data::merge(t1, t2);
	}

	Data query(int u, int v) {
		if (l > v || r < u) return {};
		if (u <= l && r <= v) return d;
		int mid = (l + r) >> 1;
		if (left && right) return Data::merge(left->query(u, v), right->query(u, v));
		Data t1 = left ? left->query(u, v) : Data();
		Data t2 = right ? right->query(u, v) : Data();
		return Data::merge(t1, t2);
	}
};