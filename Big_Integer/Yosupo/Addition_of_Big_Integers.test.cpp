#define PROBLEM "https://judge.yosupo.jp/problem/addition_of_big_integers"

#include "../../template.h"
#include "../BigInt.h"

void solve(){
    int t; cin >> t;
    while (t--) {
        string s1, s2; cin >> s1 >> s2;
        BigInt a(s1), b(s2);
        cout << a + b << '\n';
    }
}