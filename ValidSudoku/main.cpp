#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            auto count = vector<int>(9, 0);
            for (int j = 0; j < 9; j++) {
                char cur = board[i][j];
                if (cur == '.') continue;
                count[cur - '1']++;
                if (count[cur - '1'] > 1) return false;
            }
        }
        for (int i = 0; i < 9; i++) {
            auto count = vector<int>(9, 0);
            for (int j = 0; j < 9; j++) {
                char cur = board[j][i];
                if (cur == '.') continue;
                count[cur - '1']++;
                if (count[cur - '1'] > 1) return false;
            }
        }
        vector<pair<int, int>> dirs = {
            {-1, -1},
            {-1, 0},
            {-1, 1},
            {0, -1},
            {0, 0},
            {0, 1},
            {1, -1},
            {1, 0},
            {1, 1}
        };
        for (int i = 1; i < 9; i += 3) {
            for (int j = 1; j < 9; j += 3) {
                auto count = vector<int>(9, 0);
                for (const auto& it : dirs) {
                    int tx = i + it.first;
                    int ty = j + it.second;
                    char cur = board[tx][ty];
                    if (cur == '.') continue;
                    count[cur - '1']++;
                    if (count[cur - '1'] > 1) return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    return 0;
}
