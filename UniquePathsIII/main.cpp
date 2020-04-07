#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dfs(vector<vector<int>>& grid, int x, int y, int n) {
        if (x < 0 ||
            y < 0 ||
            x == grid.size() ||
            y == grid[0].size() ||
            grid[x][y] == -1)
            return 0;
        if (grid[x][y] == 2)
            return n == 0 ? 1 : 0;
        grid[x][y] = -1;
        int paths = dfs(grid, x - 1, y, n - 1) +
                    dfs(grid, x, y - 1, n - 1) +
                    dfs(grid, x + 1, y, n - 1) +
                    dfs(grid, x, y + 1, n - 1);
        grid[x][y] = 0;
        return paths;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int sx = -1;
        int sy = -1;
        int n = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                n = grid[i][j] == 0 ? n + 1 : n;
                if (grid[i][j] == 1) {
                    sx = i;
                    sy = j;
                }
            }
        }
        return dfs(grid, sx, sy, n + 1);
    }
};

int main()
{
    Solution ins;
    vector<vector<int>> m = {{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
    cout<< ins.uniquePathsIII(m);
    return 0;
}
