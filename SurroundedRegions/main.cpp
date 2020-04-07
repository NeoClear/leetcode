#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_set<int64_t> visited;
    vector<int> dirs = {-1, 0, 1, 0, -1};
    int64_t tag(int x, int y) {
        return (static_cast<int64_t>(x) << 32) | static_cast<int64_t>(y);
    }
    bool dfs(int x, int y, vector<vector<char>>& board) {
        if (board[x][y] == 'X')
            return true;
        for (int i = 0; i < 4; i++) {
            int tx = x + dirs[i];
            int ty = y + dirs[i + 1];
            if (tx < 0 || ty < 0 ||
                    tx >= board.size() || ty >= board[0].size())
                return false;
            if (visited.count(tag(tx, ty)))
                continue;
            visited.insert(tag(tx, ty));
            if (!dfs(tx, ty, board))
                return false;
        }
        return true;
    }
    void dye(int x, int y, vector<vector<char>>& board) {
        if (board[x][y] == 'X')
            return;
        if (visited.count(tag(x, y)))
            return;
        visited.insert(tag(x, y));
        board[x][y] = 'X';
        for (int i = 0; i < 4; i++) {
            int tx = x + dirs[i];
            int ty = y + dirs[i + 1];
            dye(tx, ty, board);
        }
    }
    void solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                if (board[i][j] == 'O') {
                    visited.clear();
                    visited.insert(tag(i, j));
                    if (dfs(i, j, board)) {
                        visited.clear();
                        dye(i, j, board);
                    }
                }
    }
};

int main()
{
    return 0;
}
