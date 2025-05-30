#include "../../template.h"

template <typename T>
struct Dsu_2D {
    int n, m;
    vector<vector<pii>> par;
    vector<vector<int>> sz;

    Dsu_2D() {}
    Dsu_2D(int _n, int _m): n(_n), m(_m) {
        par.resize(n+1, vector<pii>(m+1));
        sz.resize(n+1, vector<int>(m+1, 1));
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                par[i][j] = {i, j};
            }
        }
    }

    pii find(pii v) {
        if (v == par[v.fi][v.se]) {
            return v;
        }
        return par[v.fi][v.se] = find(par[v.fi][v.se]);
    }

    void merge(pii a, pii b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (sz[a.fi][a.se] < sz[b.fi][b.se]) {
            swap(a, b);
        }
        par[b.fi][b.se] = a;
        sz[a.fi][a.se] += sz[b.fi][b.se];
    }

    bool same_component(pii u, pii v) {
        return find(u) == find(v);
    }

    int component_size(pii u) {
        u = find(u);
        return sz[u.fi][u.se];
    }

    int max_component() {
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res = max(res, sz[i][j]);
            }
        }
        return res;
    }

    bool isValid(int n, int m, pii u) {
        return u.fi >= 0 && u.fi < n && u.se >= 0 && u.se < m;
    }

    /*----------- Paint cell and check maximum component ---------*/
    int Try_all_cell (vector<vector<T>> &a) {
        int dx[4] = {-1, 0, 0, 1};
        int dy[4] = {0, -1, 1, 0};
        int ans = max_component();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j]) continue;
                int t = 1;
                set<pii> s;
                for (int k = 0; k < 4; k++) {
                    pii u = {i + dx[k], j + dy[k]};
                    if (isValid(n, m, u) && a[u.fi][u.se]) {
                        pii v = find(u);
                        if (s.count(v)) continue;
                        t += sz[v.fi][v.se];
                        s.insert(v);
                    }
                }
                ans = max(ans, t);
            }
        }
        return ans;
    }
    /*------------------------------------------------------------*/

    /*-------------------- Paint all row or col ------------------*/
    int Try_Row(int k, vector<vector<T>> &a) {
        int dx[2] = {-1, 1};
        int dy[2] = {0, 0};
        int res = 0;
        set<pii> s;
        for (int i = 0; i < m; i++) {
            if (a[k][i] == '.') res++;
            if (a[k][i] == '#') {
                pii x = find({k, i});
                if (s.find(x) == s.end()) {
                    res += sz[x.fi][x.se];
                    s.insert({x.fi, x.se});
                }
            } 
            for (int j = 0; j < 2; j++) {
                pii u = {k + dx[j], i + dy[j]};
                if (isValid(n, m, u) && a[u.fi][u.se] == '#') {
                    pii v = find(u);
                    if (s.find(v) == s.end()) {
                        s.insert(v);
                        res += sz[v.fi][v.se];
                    }   
                }
            }
        }
        return res;
    }

    int Try_Col(int k, vector<vector<T>> &a) {
        int dx[2] = {0, 0};
        int dy[2] = {-1, 1};
        int res = 0;
        set<pii> s;
        for (int i = 0; i < n; i++) {
            if (a[i][k] == '.') res++;
            if (a[i][k] == '#') {
                pii x = find({i, k});
                if (s.find(x) == s.end()) {
                    res += sz[x.fi][x.se];
                    s.insert({x.fi, x.se});
                }
            } 
            for (int j = 0; j < 2; j++) {
                pii u = {i+dx[j], k+dy[j]};
                if (isValid(n, m, u) && a[u.fi][u.se] == '#') {
                    pii v = find(u);
                    if (s.find(v) == s.end()) {
                        s.insert(v);
                        res += sz[v.fi][v.se];
                    }   
                }
            }
        }
        return res;
    }
    /*------------------------------------------------------------*/
};