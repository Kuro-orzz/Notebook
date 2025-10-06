#include "../template.h"

vector<vector<ll>> prefix_2d_init(int n, int m, const vector<vector<int>> &a) {
    vector<vector<ll>> pref(n+1, vector<ll>(m+1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + a[i-1][j-1];
        }
    }
    return pref;
}

ll get(const vector<vector<ll>> &pref, int a, int b, int c, int d) {
    return pref[c][d]-pref[c][b-1]-pref[a-1][d]+pref[a-1][b-1];
}