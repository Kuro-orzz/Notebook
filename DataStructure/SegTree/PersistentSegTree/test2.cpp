// https://www.spoj.com/problems/PSEGTREE/

#include "../../../template.h"
#include "PersistentSegTree.h"

void solve() {
	int n; cin >> n;
	vector<int> a(n+1);
	for (int i = 1; i <= n; i++) cin >> a[i];

	PersistentSegTree tree(n);
    Node *root = new Node(0);
    tree.build(root, 1, n, a);

	int cntVer = 0;
    tree.ver[cntVer] = root;

	int q; cin >> q;
	while (q--) {
		int tv, idx; cin >> tv >> idx;
		if (tv == 1) {
			int pos, v; cin >> pos >> v;
			int oldVal = tree.getSum(tree.ver[idx], 1, n, pos, pos);
			
			Node *prev = tree.ver[idx];
			tree.ver[++cntVer] = new Node(0);
			Node *newRoot = tree.ver[cntVer];

			tree.update(prev, newRoot, 1, n, pos, oldVal+v);
		} else if (tv == 2) {
            int l, r; cin >> l >> r;
            cout << tree.getSum(tree.ver[idx], 1, n, l, r) << '\n';
        }
	}
}