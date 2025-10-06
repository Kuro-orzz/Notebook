#include "../../template.h"
#include "../DSU/Dsu_2D.h"

// AC: https://leetcode.com/problems/making-a-large-island/description/

class Solution {
public:
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        Dsu_2D<int> g(n, n);    
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j]) continue;
                for (int k = 0; k < 4; k++) {
                    pii u = {i+dx[k], j+dy[k]};
                    if (g.isValid(n, n, u) && grid[u.fi][u.se]) {
                        g.merge({i, j}, u);
                    }
                }
            }
        }
        return g.Try_all_cell(grid);
    }
};