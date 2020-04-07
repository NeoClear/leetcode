#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> grid;
    int m, n;
    vector<int> dirs = {-1, 0, -1};
    unordered_map<int, int> map_;
    int solve(int x, int y) {
        if (x == 0 && y == 0 && grid[0][0] == 0)
            return 1;
        if (x < 0 || y < 0 || grid[x][y] == 1)
            return 0;
        if (map_.count((x << 16) + y))
            return map_[(x << 16) + y];
        int ret = 0;
        for (int i = 0; i < 2; i++) {
            int tx = x + dirs[i];
            int ty = y + dirs[i + 1];
            ret += solve(tx, ty);
        }
        return map_[(x << 16) + y] = ret;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        grid.swap(obstacleGrid);
        m = grid.size();
        n = grid[0].size();
//        graph = vector<vector<int>>(m, vector<int>(n, 0));
//        graph[0][0] = 1;
        return solve(m - 1, n - 1);
    }
};

int main()
{
    return 0;
}
