#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include "../../template.h"
#include "../Z_Function.h"

void solve() {
    string s; cin >> s;
    vector<int> ans = Z_function(s);
    for (int x : ans) cout << x << " ";
}