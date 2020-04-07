#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int color;
    int rows, cols;
    vector<vector<int>> *g;
    vector<int> area;
    vector<int> dirs = {-1, 0, 1, 0, -1};
    int dfs(int x, int y, int rgb) {
        int ans = 1;
        (*g)[x][y] = rgb;
        for (int i = 0; i < 4; i++) {
            int tx = x + dirs[i];
            int ty = y + dirs[i + 1];
            if (tx < 0 || ty < 0 ||
                tx >= rows || ty >= cols ||
                (*g)[tx][ty] != 1) continue;
            ans += dfs(tx, ty, rgb);
        }
        return ans;
    }
    int getColor(int x, int y) {
        if (x < 0 || y < 0 ||
            x >= rows || y >= cols) return 0;
        return (*g)[x][y];
    }
    int largestIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        rows = grid.size();
        cols = grid[0].size();
        g = &grid;
        color = 1;
        area = vector<int>(2, 0);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    color++;
                    area.push_back(dfs(i, j, color));
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) {
                    int area_ = 1;
                    for (auto it : set<int>{getColor(i - 1, j), getColor(i, j - 1),
                         getColor(i + 1, j), getColor(i, j + 1)}) {
                        area_ += area[it];
                    }
                    ans = area_ > ans ? area_ : ans;
                }
            }
        }
        return ans == 0 ? rows * cols : ans;
    }
};

int main()
{
    Solution ins;
    vector<vector<int>> in = {
        {1, 1},
        {1, 0}
    };
    cout<< ins.largestIsland(in)<< endl;
    return 0;
}
