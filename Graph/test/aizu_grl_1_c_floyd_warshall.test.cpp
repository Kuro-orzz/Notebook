#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C"

#include "../../template.h"
#include "../Shortest_path/Floyd_warshall.h"

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<ll>> d(n+1, vector<ll>(n+1, 1e18));
    vector<vector<int>> trace(n+1, vector<int>(n+1));
    for (int i = 1; i <= n; i++) {
        d[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        ll u, v, w; cin >> u >> v >> w;
        d[u+1][v+1] = min(d[u+1][v+1], w);
    }
    floyd_warshall(n, d, trace);
    for (int i = 1; i <= n; i++) {
        if (d[i][i] < 0) {
            cout << "NEGATIVE CYCLE\n";
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (d[i+1][j+1] == 1e18) {
                cout << "INF";
            } else {
                cout << d[i+1][j+1];
            }
            cout << (j == n - 1 ? '\n' : ' ');
        }
    }
}