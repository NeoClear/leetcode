#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minimumDistance(string word) {
        constexpr int kRest = 26;
        const int n = word.length();
        vector<vector<vector<int>>> mem(n, vector<vector<int>>(27, vector<int>(27, -1)));
        auto dis = [](int a, int b) {
            if (a == kRest) return 0;
            return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
        };
        function<int(int, int, int)> dp = [&](int i, int l, int r) {
            if (i == n) return 0;
            if (mem[i][l][r] != -1) return mem[i][l][r];
            int d = word[i] - 'A';
            return mem[i][l][r] = min(dp(i + 1, d, r) + dis(l, d),
                                      dp(i + 1, l, d) + dis(r, d));
        };
        return dp(0, kRest, kRest);
    }
};
