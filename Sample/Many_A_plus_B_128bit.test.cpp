#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb_128bit"

#include "../template.h"
#include "../Big_Integer/BigInt.h"

void solve(){
    int t; cin >> t;
    while (t--) {
        string s1, s2; cin >> s1 >> s2;
        BigInt a(s1), b(s2);
        cout << a + b << '\n';
    }
}