#define PROBLEM "https://judge.yosupo.jp/problem/primality_test"

#include "../template.h"
#include "Math/MillerRabin.h"

void solve() {
    int q; cin >> q;
    while (q--) {
        ll n; cin >> n;
        if (MillerRabin(n)) cout << "Yes\n";
        else cout << "No\n";
    }
}