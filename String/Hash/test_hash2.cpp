#include "../../template.h"
#include "Rolling_Hash.h"

/* AC: https://oj.vnoi.info/problem/paliny */

bool check_even(Hash<int> &h1, Hash<int> &h2, int n, int len) {
    int half = len/2;
    for (int i = 1; i <= n-len+1; i++) {
        int l1 = i, r1 = l1 + half - 1;
        int l2 = n - (r1 + half) + 1, r2 = l2 + half - 1;
        if (h1.getHash(l1, r1) == h2.getHash(l2, r2)) {
            return true;
        }
    }
    return false;
}

int binEven(Hash<int> &h1, Hash<int> &h2, int n) {
    int l = 1, r = n/2;
    int res = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check_even(h1, h2, n, 2*mid)) {
            res = 2*mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }   
    return res;
}

bool check_odd(Hash<int> &h1, Hash<int> &h2, int n, int len) {
    int half = len/2;
    for (int i = 1; i <= n-len+1; i++) {
        int l1 = i, r1 = l1 + half - 1;
        int l2 = n - (r1 + half + 1) + 1, r2 = l2 + half - 1;
        if (h1.getHash(l1, r1) == h2.getHash(l2, r2)) {
            return true;
        }
    }
    return false;
}

int binOdd(Hash<int> &h1, Hash<int> &h2, int n) {
    int l = 1, r = (n-1)/2;
    int res = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check_odd(h1, h2, n, 2*mid+1)) {
            res = 2*mid + 1;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }   
    return res;
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    string x = s;
    reverse(all(x));
    Hash<int> h1(s), h2(x);
    int ans = max(binEven(h1, h2, n), binOdd(h1, h2, n));
    cout << ans;
}