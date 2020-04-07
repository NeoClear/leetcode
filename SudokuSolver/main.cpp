#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int xtag(int x, int y) {
        return x;
    }
    int ytag(int x, int y) {
        return y;
    }
    int btag(int x, int y) {
        return (x / 3) * 3 + (y / 3);
    }
    vector<unordered_set<int>> xset;
    vector<unordered_set<int>> yset;
    vector<unordered_set<int>> bset;
    vector<pair<int, int>> fill;
    bool solved = false;
    unordered_set<int> proba(int x, int y) {
        unordered_set<int> possibility;
        for (int i = 0; i < 9; i++)
            if (xset[xtag(x, y)].count(i) &&
                yset[ytag(x, y)].count(i) &&
                bset[btag(x, y)].count(i))
                possibility.insert(i);
        return possibility;
    }
    void solve(int n, vector<vector<char>>& board) {
        if (n == fill.size()) {
            solved = true;
            return;
        }
        int tx = fill[n].first;
        int ty = fill[n].second;
        for (const auto& number : proba(tx, ty)) {
            board[tx][ty] = number + '1';
            xset[xtag(tx, ty)].erase(number);
            yset[ytag(tx, ty)].erase(number);
            bset[btag(tx, ty)].erase(number);
            solve(n + 1, board);
            if (solved)
                return;
            board[tx][ty] = '.';
            xset[xtag(tx, ty)].insert(number);
            yset[ytag(tx, ty)].insert(number);
            bset[btag(tx, ty)].insert(number);
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        xset = vector<unordered_set<int>>(9, {0, 1, 2, 3, 4, 5, 6, 7, 8});
        yset = vector<unordered_set<int>>(9, {0, 1, 2, 3, 4, 5, 6, 7, 8});
        bset = vector<unordered_set<int>>(9, {0, 1, 2, 3, 4, 5, 6, 7, 8});
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char cur = board[i][j];
                if (cur == '.')
                    fill.push_back({i, j});
                xset[xtag(i, j)].erase(cur - '1');
                yset[ytag(i, j)].erase(cur - '1');
                bset[btag(i, j)].erase(cur - '1');
            }
        }
        solve(0, board);
    }
};

int main()
{
    Solution ins;
    return 0;
}
