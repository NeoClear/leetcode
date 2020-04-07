#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void solve(int x, int y, vector<vector<int>>& matrix) {
        int N = matrix.size();
        int& lt = matrix[x][y];
        int& lb = matrix[N - y - 1][x];
        int& rt = matrix[y][N - x - 1];
        int& rb = matrix[N - x - 1][N - y - 1];
        int lt_ = lt;
        int lb_ = lb;
        int rt_ = rt;
        int rb_ = rb;
        lt = lb_;
        lb = rb_;
        rb = rt_;
        rt = lt_;
    }
    void rotate(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size() / 2; i++) {
            for (int j = 0; j < (matrix.size() + 1) / 2; j++)
                solve(i, j, matrix);
        }
    }
};

int main()
{
    vector<vector<int>> in = {
        {1, 2},
        {3, 4}
    };
    Solution ins;
    ins.rotate(in);
    for (const auto& line : in) {
        for (const auto& ele : line)
            cout<< ele<< " ";
        cout<< endl;
    }
    return 0;
}
