#include "../../template.h"

void initTrace(int n, vector<vector<int>> &trace) {
	for (int u = 1; u <= n; ++u) {
		for (int v = 1; v <= n; ++v) {
			trace[u][v] = u;
		}
	}
}

void floyd_warshall(int n, vector<vector<ll>> &dist, vector<vector<int>> &trace) {
	initTrace(n, trace);
	for (int k = 1; k <= n; ++k) {
		for (int u = 1; u <= n; ++u) {
			for (int v = 1; v <= n; ++v) {
				if (dist[u][k] != 1e18 && dist[k][v] != 1e18 && dist[u][v] > dist[u][k] + dist[k][v]) {
					dist[u][v] = dist[u][k] + dist[k][v];
					trace[u][v] = trace[k][v];
				}
			}
		}
	}
}