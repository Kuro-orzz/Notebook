#include "../template.h"


// Longest common substring with trace

struct Trace {
    int i, j;
    char c;
    Trace(int _i = 0, int _j = 0, char _c = '\0'): i(_i), j(_j), c(_c) {}
};

void solve() {
    string s1, s2; cin >> s1 >> s2;
    s1 = "#" + s1;
    s2 = "#" + s2;
    int n = s1.size(), m = s2.size();
    int dp[n][m];
    Trace par[n][m] = {};
    memset(dp, 0, sizeof dp);
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (s1[i] == s2[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                par[i][j] = Trace(i-1, j-1, s1[i]);
            } else {
                if (dp[i][j-1] >= dp[i-1][j]) {
                    dp[i][j] = dp[i][j-1];
                    par[i][j] = Trace(i, j-1);
                } else {
                    dp[i][j] = dp[i-1][j];
                    par[i][j] = Trace(i-1, j);
                }
            }
        }
    }
    Trace cur = par[n-1][m-1];
    string ans = "";
    while (1) {
        if (cur.c != '\0') ans += cur.c;
        if (!cur.i && !cur.j) break;
        cur = par[cur.i][cur.j];
    }
    reverse(all(ans));
    cout << ans;
}