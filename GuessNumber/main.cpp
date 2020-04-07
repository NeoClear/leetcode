#include <bits/stdc++.h>

using namespace std;

#define ind 300
int dp[ind][ind];

class Solution {
private:
    int solve(int lef, int rig) {
        if (lef == rig)
            return 0;
        if (rig - lef == 1) {
            return dp[lef][rig] = lef;
        }
        if (dp[lef][rig])
            return dp[lef][rig];
        int min = 0x7fffffff;
        for (int k = lef + 1; k < rig; k++) {
            int ll = solve(lef, k - 1);
            int rr = solve(k + 1, rig);
            int update = k + (ll > rr ? ll : rr);
            min = update < min ? update : min;
        }
        return dp[lef][rig] = min;
    }
    int sol(int n) {
        for (int i = 1; i < n; i++) {
            dp[i][i + 1] = i;
        }
        for (int i = 2; i < n; i++) {
            for (int j = 1; j <= n - i; j++) {
                int min = INT_MAX;
                for (int k = j + 1; k < j + i; k++) {
                    int ll = dp[j][k - 1];
                    int rr = dp[k + 1][j + i];
                    int res = k + (ll > rr ? ll : rr);
                    min = res < min ? res : min;
                }
                dp[j][j + i] = min;
            }
        }
        return dp[1][n];
    }
public:
    int getMoneyAmount(int n) {
        memset(dp, 0, sizeof(dp));
        return sol(n);
    }
};

int main()
{
    Solution ins;
    cout<< ins.getMoneyAmount(7)<< endl;
    return 0;
}
