#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> mem_;
    int rows, cols;
    vector<int> dirs = {-1, 0, 1, 0, -1};
    int dfs(int r, int c, vector<vector<int>>& matrix) {
        if (mem_[r][c] >= 0) return mem_[r][c];
        mem_[r][c] = 1;
        for (int i = 0; i < 4; i++) {
            int tx = r + dirs[i];
            int ty = c + dirs[i + 1];
            if (tx < 0 || ty < 0 ||
                tx >= rows || ty >= cols ||
                matrix[tx][ty] >= matrix[r][c]) continue;
            int u_ = dfs(tx, ty, matrix);
            mem_[r][c] = u_ + 1 > mem_[r][c] ? u_ + 1 : mem_[r][c];
        }
        return mem_[r][c];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        rows = matrix.size();
        cols = matrix[0].size();
        mem_ = vector<vector<int>>(rows, vector<int>(cols, -1));
        int ans = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int u_ = dfs(i, j, matrix);
                ans = u_ > ans ? u_ : ans;
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}
