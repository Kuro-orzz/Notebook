#include "../../template.h"

struct Dsu_2D {
    vector<vector<pii>> par;
    vector<vector<int>> sz;

    Dsu_2D(int n, int m): par(n+1, vector<pii>(m+1)), sz(n+1, vector<int>(m+1, 1)) {
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= m; j++)
                par[i][j] = {i, j};
    }
    pii find(pii v) {
        if(v == par[v.fi][v.se])
            return v;
        return par[v.fi][v.se] = find(par[v.fi][v.se]);
    }
    void merge(pii a, pii b){
        a = find(a);
        b = find(b);
        if (a == b) return;
        if(sz[a.fi][a.se] < sz[b.fi][b.se]) swap(a, b);
        par[b.fi][b.se] = a;
        sz[a.fi][a.se] += sz[b.fi][b.se];
    }
};