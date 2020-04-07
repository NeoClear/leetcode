#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<vector<int>> t_;
    int row, col;
public:
    void dfs(int r, int c, int pattern, vector<vector<int>>& matrix) {

        if ((t_[r][c] & pattern) != 0)
            return;
        t_[r][c] |= pattern;
        if (r < row - 1 && matrix[r + 1][c] >= matrix[r][c])
            dfs(r + 1, c, pattern, matrix);
        if (c < col - 1 && matrix[r][c + 1] >= matrix[r][c])
            dfs(r, c + 1, pattern, matrix);
        if (r > 0 && matrix[r - 1][c] >= matrix[r][c])
            dfs(r - 1, c, pattern, matrix);
        if (c > 0 && matrix[r][c - 1] >= matrix[r][c])
            dfs(r, c - 1, pattern, matrix);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return vector<vector<int>>();
        row = matrix.size();
        col = matrix[0].size();
        t_ = vector<vector<int>>(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++)
            dfs(i, 0, 1, matrix);
        for (int i = 0; i < col; i++)
            dfs(0, i, 1, matrix);
        for (int i = 0; i < row; i++)
            dfs(i, col - 1, 2, matrix);
        for (int i = 0; i < col; i++)
            dfs(row - 1, i, 2, matrix);
        vector<vector<int>> ans;
        ans.clear();

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (t_[i][j] == 3) {
                    vector<int> tp;
                    tp.push_back(i);
                    tp.push_back(j);
                    ans.push_back(tp);
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution ins;
    vector<vector<int>> t;
    vector<vector<int>> ip = {
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4}
    };
    t = ins.pacificAtlantic(ip);
    for (int i = 0; i < t.size(); i++)
        cout<< t[i][0]<< ", "<< t[i][1]<< endl;
    return 0;
}
