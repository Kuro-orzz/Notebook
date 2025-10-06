#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D"

#include "../../template.h"
#include "../Math/EulerPhi.h"

void solve() {
    ll n; cin >> n;
    cout << eulerPhi(n) << '\n';
}