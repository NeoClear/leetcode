#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<int> sums_;
    vector<vector<vector<int>>> c_;
public:
    int sum(int l, int r) {
        return l == 0 ? sums_[r] : sums_[r] - sums_[l - 1];
    }
    int mergeStones(vector<int>& stones, int K) {
        int len = stones.size();

        if ((len - 1) % (K - 1))
            return -1;
        constexpr int kInf = 1e9;
        c_ = vector<vector<vector<int>>>(len, vector<vector<int>>(len, vector<int>(K + 1, kInf)));
        sums_ = vector<int>(len, 0);
        sums_[0] = stones[0];
        for (int i = 1; i < len; i++)
            sums_[i] = sums_[i - 1] + stones[i];
        for (int i = 0; i < len; i++)
            c_[i][i][1] = 0;
        for (int l = 2; l <= len; l++) {
            for (int i = 0; i <= len - l; i++) {
                int j = i + l - 1;
                for (int k = 2; k <= K; k++) {
                    if ((l - 1) % (k - 1))
                        continue;
                    for (int m = i; m < j; m += K - 1)
                        c_[i][j][k] = min(c_[i][j][k], c_[i][m][1] + c_[m + 1][j][k - 1]);
                    c_[i][j][1] = c_[i][j][k] + sum(i, j);
                }
            }
        }
        return c_[0][len - 1][1];
    }
};

int main()
{
    Solution ins;
    vector<int> stone = {
        3, 5, 1, 2, 6
    };
    cout << ins.mergeStones(stone, 3) << endl;
    return 0;
}
