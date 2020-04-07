#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int N;
    int ans_ = 0;
    vector<string> status_;
    vector<bool> cols;
    vector<bool> ltop, lbot;
    bool available(int x, int y) {
        return cols[y] &&
                ltop[x + y] &&
                lbot[N - 1 - (x - y)];
    }
    void toggle(int x, int y, bool val) {
        cols[y] = val;
        ltop[x + y] = val;
        lbot[N - 1 - (x - y)] = val;
        status_[x][y] = val ? '.' : 'Q';
    }
    void solve(int x) {
        if (x == N) {
            ans_++;
            return;
        }
        for (int i = 0; i < N; i++) {
            if (!available(x, i)) continue;
            toggle(x, i, false);
            solve(x + 1);
            toggle(x, i, true);
        }
    }
    int totalNQueens(int n) {
        N = n;
        cols = vector<bool>(N, true);
        ltop = vector<bool>(N * 2 - 1, true);
        lbot = vector<bool>(N * 2 - 1, true);
        status_ = vector<string>(N, string(N, '.'));
        solve(0);
        return ans_;
    }
};

int main()
{
    return 0;
}
