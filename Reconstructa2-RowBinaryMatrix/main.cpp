#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        if (accumulate(colsum.begin(), colsum.end(), 0) != upper + lower)
            return {};
        vector<vector<int>> matrix = vector<vector<int>>(2, vector<int>(colsum.size(), 0));
        for (int i = 0; i < colsum.size(); i++)
            if (colsum[i] == 2) {
                upper--;
                lower--;
                matrix[0][i] = 1;
                matrix[1][i] = 1;
                if (upper < 0 || lower < 0)
                    return {};
            }
        for (int i = 0; i < colsum.size(); i++) {
            if (colsum[i] != 1)
                continue;
            if (upper > 0) {
                upper--;
                matrix[0][i]++;
            } else if (lower > 0) {
                lower--;
                matrix[1][i]++;
            }
        }
        return matrix;
    }
};

int main()
{
    return 0;
}
