#include "../../template.h"
#include "../Rolling_Hash.h"

/* AC: https://oj.vnoi.info/problem/substr */

void solve() {
    string s1, s2; cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    Hash<int> h1(s1), h2(s2);
    for (int i = 1; i <= n-m+1; i++) {
        if (h1.getHash(i, i+m-1) == h2.getHash(1, m)) {
            cout << i << ' ';
        }
    }
}