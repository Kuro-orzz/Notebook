#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A"

#include "../../../template.h"
#include "../Factorization.h"

void solve() {
    int n; cin >> n;
    vector<ll> v = primeFactor(n);
    cout << n << ": ";
    for (int i = 0; i < (int)v.size() - 1; i++) {
        cout << v[i] << " ";
    }
    cout << v.back() << '\n';
}