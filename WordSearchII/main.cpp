#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<char, vector<pair<int, int>>> position;
    vector<int> dirs = {-1, 0, 1, 0, -1};
    bool dfs(vector<vector<char>>& board, string word, pair<int, int> pos) {
        if (word.empty())
            return true;
        char real = board[pos.first][pos.second];
        board[pos.first][pos.second] = '@';
        for (int i = 0; i < 4; i++) {
            int tx = pos.first + dirs[i];
            int ty = pos.second + dirs[i + 1];
            if (tx < 0 || ty < 0 ||
                    tx >= board.size() || ty >= board[0].size() ||
                    board[tx][ty] != word.front())
                continue;
            if (dfs(board, word.substr(1), {tx, ty})) {
                board[pos.first][pos.second] = real;
                return true;
            }
        }
        board[pos.first][pos.second] = real;
        return false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                position[board[i][j]].push_back({i, j});
        vector<string> ans;
        for (const auto& it : words)
            for (const auto& pos : position[it.front()])
                if (dfs(board, it.substr(1), pos)) {
                    ans.push_back(it);
                    break;
                }
        return ans;
    }
};

int main()
{
    return 0;
}
