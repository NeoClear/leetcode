#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

class Solution {
private:
    vector<uint64_t> dp;
    uint64_t add(uint64_t a, uint64_t b) { return (a + b) % MOD; }
public:
    int knightDialer(int N) {
        dp = vector<uint64_t>(10, 1);
        vector<uint64_t> cac(10, 0);
        for (int i = 0; i < N - 1; i++) {
            for (int i = 0; i <= 9; i++)
                cac[i] = 0;
            cac[0] = add(dp[4], dp[6]);
            cac[1] = add(dp[6], dp[8]);
            cac[2] = add(dp[7], dp[9]);
            cac[3] = add(dp[4], dp[8]);
            cac[4] = add(dp[3], dp[9]);
            cac[4] = add(cac[4], dp[0]);
            cac[6] = add(dp[1], dp[7]);
            cac[6] = add(cac[6], dp[0]);
            cac[7] = add(dp[2], dp[6]);
            cac[8] = add(dp[1], dp[3]);
            cac[9] = add(dp[2], dp[4]);
            dp = cac;
        }
        uint64_t ans = 0;
        for (int i = 0; i <= 9; i++)
            ans = add(ans, dp[i]);
        return static_cast<int>(ans);
    }
};

int main()
{
    Solution ins;
    cout<< ins.knightDialer(161)<< endl;
    return 0;
}
