#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int R_, C_;
    vector<vector<int>> grid_;
    int color = 1;
    void dfs(int x, int y, int c) {
        grid_[x][y] = c;
        vector<int> dirs = {-1, 0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int tx = x + dirs[i];
            int ty = y + dirs[i + 1];
            if (tx < 0 || ty < 0 ||
                tx >= R_ || ty >= C_ ||
                grid_[tx][ty] != 1)
                continue;
            dfs(tx, ty, c);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        R_ = grid.size();
        C_ = grid[0].size();
        grid_ = vector<vector<int>>(R_, vector<int>(C_));
        for (int i = 0; i < R_; i++) {
            for (int j = 0; j < C_; j++) {
                grid_[i][j] = grid[i][j] == '0' ? 0 : 1;
            }
        }
        for (int i = 0; i < R_; i++) {
            for (int j = 0; j < C_; j++) {
                if (grid_[i][j] == 1)
                    dfs(i, j, ++color);
            }
        }
        return color - 1;
    }
};

int main()
{
    return 0;
}
