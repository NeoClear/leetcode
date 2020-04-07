#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int row = seats.size(), col = seats[0].size();
        vector<vector<int>> dp(row + 1, vector<int>(1 << col, 0));
        for (int r = 1; r <= row; r++) {
            // the situation of rth row
            for (int prev = 0; prev < (1 << col); prev++) {
                // the status of prev row
                for (int cur = 0; cur < (1 << col); cur++) {
                    // the status of current row
                    bool valid = true;
                    for (int bit = 0; bit < col && valid; bit++) {
                        if (!(cur & (1 << bit))) continue;
                        if (seats[r - 1][bit] == '#') valid = false;
                        bool l = (bit == 0 ? 0 : (cur & (1 << (bit - 1))));
                        bool r = (bit == col - 1 ? 0 : (cur & (1 << (bit + 1))));
                        bool ul = (bit == 0 ? 0 : (prev & (1 << (bit - 1))));
                        bool ur = (bit == col - 1 ? 0 : (prev & (1 << (bit + 1))));
                        if (l || r || ul || ur) valid = false;
                    }
                    if (valid)
                        dp[r][cur] = max(dp[r][cur], dp[r - 1][prev] + __builtin_popcount(cur));
                }
            }
        }
        return *max_element(dp[row].begin(), dp[row].end());
    }
};

int main() {
    vector<vector<char>> seats = {
        {'.', '#'},
        {'#', '#'},
        {'#', '.'},
        {'#', '#'},
        {'.', '#'}
    };
    Solution ins;
    cout << ins.maxStudents(seats) << endl;
    return 0;
}
