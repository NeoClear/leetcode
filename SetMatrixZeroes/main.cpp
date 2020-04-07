#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> rows, cols;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        for (const auto& it : rows)
            for (int i = 0; i < matrix[0].size(); i++)
                matrix[it][i] = 0;
        for (const auto& it : cols)
            for (int i = 0; i < matrix.size(); i++)
                matrix[i][it] = 0;
    }
};

int main()
{
    return 0;
}
