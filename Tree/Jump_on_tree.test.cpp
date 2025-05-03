#define PROBLEM "https://judge.yosupo.jp/problem/jump_on_tree"

#include "../template.h"
#include "Tree/BinaryLifting.h"

void solve() {
	int n, q; cin >> n >> q;
	BinLift binLift(n);
	for (int i = 0; i < n-1; i++) {
		int u, v; cin >> u >> v;
		binLift.addEdge(u, v);
	}
	binLift.dfs(0, -1);
	while (q--) {
		int s, t, i; cin >> s >> t >> i;
		cout << binLift.jump(s, t, i) << '\n';
	}
}