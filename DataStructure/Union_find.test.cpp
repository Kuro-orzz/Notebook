#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "../template.h"
#include "Dsu/Dsu.h"

void solve(){
    int n, q; cin >> n >> q;
    Dsu g(n+1);
    while (q--) {
        int tv, u, v; cin >> tv >> u >> v;
        if (tv == 0) g.merge(u, v);
        else if (g.find(u) == g.find(v))
            cout << "1\n";
        else cout << "0\n";
    }
}