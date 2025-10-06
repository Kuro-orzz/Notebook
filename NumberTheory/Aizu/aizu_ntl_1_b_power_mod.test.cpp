#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B"

#include "../../template.h"
#include "../Math/Binary_exponentiation.h"

void solve() {
    int n, m; cin >> n >> m;
    cout << binPow(n, m, MOD) << '\n';
}