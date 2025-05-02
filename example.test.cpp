#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

struct Dsu{
    vector<int> par, sz;
    Dsu(int n): par(n+1), sz(n+1, 1){
        for(int i = 0; i < n; i++)
            par[i] = i;
    }
    int find(int v){
        if(v == par[v]) return v;
        return par[v] = find(par[v]);
    }
    void merge(int a, int b){
        a = find(a);
        b = find(b);
        if (a == b) return;
        if(sz[a] < sz[b]) swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
    }
};

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

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // cin.exceptions(cin.failbit);
    // int t; cin >> t;
    // while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}
