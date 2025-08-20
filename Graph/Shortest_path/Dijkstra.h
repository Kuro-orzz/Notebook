#include "../../template.h"

vector<ll> dijkstra(int s, int n, vector<vector<pii>> &g) {
    vector<int> vis(n + 1);
    vector<ll> d(n + 1, LLONG_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({d[s], s});
    d[s] = 0;
    while (!pq.empty()) {
        auto [dist, u] = pq.top(); pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v, w] : g[u]) {
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }
    return d;
}



struct Oxyz {
    int x, y, z;

    Oxyz(int _x, int _y, int _z): x(_x), y(_y), z(_z) {}

    bool operator < (Oxyz other) const {
        if (x != other.x) return x < other.x;
        if (y != other.y) return y < other.y;
        return z < other.z;
    }
};

using plO = pair<ll, Oxyz>;

int dijkstra(Oxyz s, int n, vector<vector<vector<int>>> &a) {
    vector<vector<vector<int>>> vis(n+1, vector<vector<int>>(n+1, vector<int>(n+1, 0)));
    vector<vector<vector<ll>>> d(n+1, vector<vector<ll>>(n+1, vector<ll>(n+1, 1e9)));
    priority_queue<plO, vector<plO>, greater<plO>> pq;
    d[s.x][s.y][s.z] = 0;
    pq.push({d[s.x][s.y][s.z], s});
    while (!pq.empty()) {
        plO u = pq.top(); pq.pop();
        auto [dist, pos] = u;
        auto [x, y, z] = pos;
        if (vis[x][y][z]) continue;
        vis[x][y][z] = 1;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                for (int k = -1; k <= 1; k++) {
                    Oxyz v(x+i, y+j, z+k);
                    if (abs(v.x-x)+abs(v.y-y)+abs(v.z-z) != 1) continue;
                    if (v.x < 1 || v.y < 1 || v.z < 1) continue;
                    if (v.x > n || v.y > n || v.z > n) continue;
                    ll w = a[x+i][y+j][z+k];
                    if (d[v.x][v.y][v.z] > dist + w) {
                        d[v.x][v.y][v.z] = dist + w;
                        pq.push({d[v.x][v.y][v.z], v});
                    }
                }
            }
        }
    }
    return d[n][n][n];
}
