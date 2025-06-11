#define PROBLEM "https://judge.yosupo.jp/problem/counting_primes"

#include "../template.h"
#include "Math/CheckPrime.h"

void solve() {
    ll n; cin >> n;
    cout << Meissel(n);
}