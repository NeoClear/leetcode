#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int R = matrix.size(), C = matrix[0].size();
        vector<int> row(R), col(C);
        for (int i = 0; i < R; i++) {
            int val = INT_MAX / 2;
            for (int k = 0; k < C; k++)
                val = min(val, matrix[i][k]);
            row[i] = val;
        }
        for (int k = 0; k < C; k++) {
            int val = 0;
            for (int i = 0; i < R; i++)
                val = max(val, matrix[i][k]);
            col[k] = val;
        }
        vector<int> ans;
        for (int i = 0; i < R; i++) {
            for (int k = 0; k < C; k++)
                if (matrix[i][k] == row[i] && matrix[i][k] == col[k])
                    ans.push_back(matrix[i][k]);
        }
        return ans;
    }
};

int main() {
    Solution ins;
    vector<vector<int>> in = {
        {7,8},{1,2}
    };
    for (const auto& it : ins.luckyNumbers(in))
        cout << it << " ";
    return 0;
}