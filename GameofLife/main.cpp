#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> dirs = {
        {-1, -1},
        {-1, 0},
        {-1, 1},
        {0, -1},
        {0, 1},
        {1, -1},
        {1, 0},
        {1, 1}
    };
    int count(vector<vector<int>>& board, pair<int, int> pos) {
        int x = pos.first;
        int y = pos.second;
        int cnt = 0;
        for (const auto& dir : dirs) {
            int tx = x + dir.first;
            int ty = y + dir.second;
            if (tx < 0 || ty < 0 ||
                tx >= board.size() || ty >= board[0].size() ||
                (board[tx][ty] & 1) == 0)
                continue;
            cnt++;
        }
        return cnt;
    }
    int state(vector<vector<int>>& board, pair<int, int> pos) {
        int state_ = board[pos.first][pos.second];
        if (state_ == 1) {
            int cnt = count(board, pos);
            if (cnt < 2 || cnt > 3)
                return 0;
            return 1;
        } else {
            if (count(board, pos) == 3)
                return 1;
            return 0;
        }
    }
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty())
            return;
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++) {
                int& ele = board[i][j];
                ele |= (state(board, {i, j}) << 1);
            }
        for (auto& line : board)
            for (auto& ele : line)
                ele >>= 1;
    }
};

int main()
{
    return 0;
}
