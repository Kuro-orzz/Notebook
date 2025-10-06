#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"

#include "../../template.h"

void solve(){
    unordered_map<ll, ll> mp;
    int q; cin >> q;
    while (q--) {
        int tv; cin >> tv;
        if (tv == 0) {
            ll k, v; cin >> k >> v;
            mp[k] = v;
        }
        else {
            ll k; cin >> k;
            cout << mp[k] << '\n';
        }
    }
}