#include <bits/stdc++.h>

using namespace std; 

class NumMatrix {
private:
    vector<vector<int>> sums_;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        sums_.clear();

        if (matrix.empty())
            return;

        uint64_t lines = matrix.size();
        uint64_t cols = matrix[0].size();

        sums_ = vector<vector<int>>(lines + 1, vector<int>(cols + 1, 0));
        for (uint64_t i = 1; i <= lines; i++) {
            for (uint64_t j = 1; j <= cols; j++) {
                sums_[i][j] = matrix[i - 1][j - 1]
                            + sums_[i - 1][j]
                            + sums_[i][j - 1]
                            - sums_[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums_[row2 + 1][col2 + 1] - sums_[row2 + 1][col1] - sums_[row1][col2 + 1] + sums_[row1][col1];
    }
};


int main()
{
    vector<vector<int>> m = {
        {1, 2, 3},
        {2, 3, 4},
        {3, 4, 5}
    };
    NumMatrix ins(m);
    cout<< ins.sumRegion(1, 1, 2, 2)<< endl;
    return 0;
}
