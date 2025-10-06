#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_C"

#include "../../template.h"

// lcm support C++17 and above only
// if C++ lower than 17, use x / __gcd(x, y) * y

void solve() {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = a[0];
    for (int i = 1; i < n; i++) {
        ans = lcm(ans, a[i]);
    }
    cout << ans << '\n';
}