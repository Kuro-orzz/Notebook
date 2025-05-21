#include "../../template.h"


struct Node {
	Node *left = nullptr, *right = nullptr;
	ll val;
	pll lazy = {1, 0};
	
	Node(): val(0), lazy({1, 0}) {}
	
	Node operator+(const Node& b) const {
		Node res;
		res.val = (val + b.val) % mod;
		return res;
	}

	~Node() {
		delete left;
		delete right;
	}
};

class SparseSegTree {
private:
	Node *r = new Node();
	int n;

	void push(Node *cur, int l, int r) {
		int m = (l + r) >> 1;
		if (!cur->left) cur->left = new Node();
		if (!cur->right) cur->right = new Node();
		apply(cur->left, l, m, cur->lazy);
		apply(cur->right, m+1, r, cur->lazy);
		cur->lazy = {1, 0};
	}

	void apply(Node *cur, int l, int r, pll x) {
		ll b = x.fi, c = x.se;
		int len = r-l+1;
		cur->val = (cur->val * b % mod + c * len % mod) % mod;
		cur->lazy.fi = cur->lazy.fi * b % mod;
		cur->lazy.se = (cur->lazy.se * b % mod + c) % mod;
	}

	void update(Node *cur, int l, int r, int u, int v, pll x) {
		if (l > v || r < u) return;
		if (u <= l && r <= v) {
			apply(cur, l, r, x);
			return;
		}
		push(cur, l, r);
		ll mid = (l + r) >> 1;
		update(cur->left, l, mid, u, v, x);
		update(cur->right, mid+1, r, u, v, x);
		cur->val = (cur->left->val + cur->right->val) % mod;
	}

	ll query(Node *cur, int l, int r, int u, int v) {
		if (l > v || r < u) return 0;
		if (u <= l && r <= v) return cur->val;
		push(cur, l, r);
		int mid = (l + r) >> 1;
		ll t1 = query(cur->left, l, mid, u, v) % mod;
		ll t2 = query(cur->right, mid+1, r, u, v) % mod;
		return (t1 + t2) % mod;
	}

public:
	SparseSegTree() {}
	SparseSegTree(int _n): n(_n) {}

	void update(int u, int v, pll val) { update(r, 1, n, u, v, val); }
	
	ll query(int u, int v) { return query(r, 1, n, u, v); }
};