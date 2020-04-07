#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;
        int R = matrix.size();
        int C = matrix[0].size();
        auto sol = vector<vector<int>>(R + 1, vector<int>(C + 1, 0));
        int maxLen = 0;
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                if (matrix[i - 1][j - 1] == '1') {
                    int len = sol[i][j] = min(sol[i - 1][j],
                            min(sol[i][j - 1], sol[i - 1][j - 1])) + 1;
                    maxLen = max(maxLen, len);
                }
            }
        }
        return maxLen * maxLen;
    }
};

int main()
{
    return 0;
}
