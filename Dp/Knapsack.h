#include "../template.h"

// 1 <= N <= 100, 1 <= W <= 1e5
// 1 <= wi <= W, 1 <= vi <= 1e9
void knapsack01() {
    int n, W; cin >> n >> W;
    vector<int> w(n+1), v(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    vector<vector<ll>> dp(n+1, vector<ll>(W+1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            dp[i][j] = dp[i-1][j];
            if (j-w[i] < 0) continue;
            dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + v[i]);
        }
    }
    cout << dp[n][W];
}

// 1 <= N <= 100, 1 <= W <= 1e9
// 1 <= wi <= W, 1 <= vi <= 1e3
void knapsack02() {
    int n, W; cin >> n >> W;
    vector<int> w(n+1), v(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    vector<vector<ll>> dp(n+1, vector<ll>(1e5+1, 1e18));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 1e5; j++) {
            dp[i][j] = dp[i-1][j];
            if (j-v[i] < 0) continue;
            if (dp[i-1][j-v[i]] + w[i] <= W) {
                dp[i][j] = min(dp[i][j], dp[i-1][j-v[i]] + w[i]);
            }
        }
    }
    for (int i = 1e5; i >= 0; i--) {
        if (dp[n][i] <= W) {
            cout << i;
            return;
        }
    }
}