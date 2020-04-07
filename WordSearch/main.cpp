#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string word_;
    vector<vector<char>> board_;
    unordered_map<char, vector<pair<int, int>>> map_;
    int R_, C_;

    unordered_set<int64_t> visited;

    int64_t connect(int x, int y) {
        return static_cast<int64_t>(x) << 32 | static_cast<int64_t>(y);
    }

    bool solve(int x, int y, int step) {
        if (step == word_.size() - 1) return true;
        vector<int> dirs = {-1, 0, 1, 0, -1};
        visited.insert(connect(x, y));
        bool flag = false;
        for (int i = 0; i < 4; i++) {
            int tx = x + dirs[i];
            int ty = y + dirs[i + 1];
            if (tx < 0 || ty < 0 ||
                tx >= R_ || ty >= C_ ||
                visited.count(connect(tx, ty)) ||
                board_[tx][ty] != word_[step + 1]) continue;
            if ((flag |= solve(tx, ty, step + 1)))
                break;
        }
        visited.erase(connect(x, y));
        return flag;
    }

    bool exist(vector<vector<char>>& board, string word) {
        board_.swap(board);
        word_.swap(word);
        R_ = board_.size();
        C_ = board_[0].size();
        for (int i = 0; i < R_; i++) {
            for (int j = 0; j < C_; j++) {
                map_[board_[i][j]].push_back({i, j});
            }
        }
        for (const auto& it : map_[word_[0]]) {
            visited.clear();
            if (solve(it.first, it.second, 0))
                return true;
        }
        return false;
    }
};

int main()
{
    Solution ins;
    vector<vector<char>> in = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    if (ins.exist(in, "ABCB"))
        cout<< "YES"<< endl;
    else
        cout<< "NO"<< endl;
    return 0;
}
