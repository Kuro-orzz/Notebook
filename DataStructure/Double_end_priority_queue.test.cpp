#define PROBLEM "https://judge.yosupo.jp/problem/double_ended_priority_queue"

#include "../template.h"

void solve() {
    int n, q; cin >> n >> q;
    priority_queue<int> maxElement;
    priority_queue<int, vector<int>, greater<int>> minElement;
    unordered_map<int, int> maxRev, minRev;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        maxElement.push(x);
        minElement.push(x);
    }
    auto lazyRev = [&]() {
        while (!maxElement.empty() && maxRev[maxElement.top()] > 0) {
            maxRev[maxElement.top()]--;
            maxElement.pop();
        }
        while (!minElement.empty() && minRev[minElement.top()] > 0) {
            minRev[minElement.top()]--;
            minElement.pop();
        }
    };
    while (q--) {
        int tv; cin >> tv;
        if (tv == 0) {
            int x; cin >> x;
            maxElement.push(x);
            minElement.push(x);
        } else if (tv == 1) {
            lazyRev();
            int mn = minElement.top();
            minElement.pop();
            maxRev[mn]++;
            cout << mn << '\n';
        } else if (tv == 2) {
            lazyRev();
            int mx = maxElement.top();
            maxElement.pop();
            minRev[mx]++;
            cout << mx << '\n';
        }
    }
}