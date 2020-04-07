#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // return 1 means is closed
    // return 0 means is not closed
    vector<int> DIRS = {-1, 0, 1, 0, -1};
    int solve(int x, int y, vector<vector<int>>& grid) {
        int flag = 1;
        grid[x][y] = -1;
        for (int i = 0; i < 4; i++) {
            int tx = x + DIRS[i];
            int ty = y + DIRS[i + 1];
            if (tx < 0 || ty < 0 ||
                    tx >= grid.size() || ty >= grid[0].size()) {
                flag = 0;
                continue;
            }
            if (grid[tx][ty] == -1 || grid[tx][ty] == 1)
                continue;
            flag &= solve(tx, ty, grid);
        }
        return flag;
    }
    int closedIsland(vector<vector<int>>& grid) {
        if (grid.empty())
            return 0;
        int cnt = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j] == 0)
                    if (solve(i, j, grid))
                        cnt++;
        return cnt;
    }
};

int main()
{
    return 0;
}
