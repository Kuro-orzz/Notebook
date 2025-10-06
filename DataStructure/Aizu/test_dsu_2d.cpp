#include "../../template.h"
#include "../DSU/Dsu_2D.h"

// AC: https://codeforces.com/contest/1985/problem/H1

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    Dsu_2D<char> g(n, m);
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != '#') continue;
            for (int k = 0; k < 4; k++){
                pii u = {i + dx[k], j + dy[k]};
                if (g.isValid(n, m, u) && a[u.fi][u.se] == '#'){
                    g.merge({i, j}, u);
                }
            }
        }
    }
    int ans = g.max_component();
    for (int i = 0; i < n; i++) {
        ans = max(ans, g.Try_Row(i, a));
    }
    for (int i = 0; i < m; i++) {
        ans = max(ans, g.Try_Col(i, a));
    }
    cout << ans << '\n';
}