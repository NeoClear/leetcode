#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    int solve(string& w1, string& w2, int len1, int len2) {
        if (len1 == 0)
            return len2;
        if (len2 == 0)
            return len1;
        if (dp[len1][len2] >= 0)
            return dp[len1][len2];
        if (w1[len1 - 1] == w2[len2 - 1])
            return dp[len1][len2] = solve(w1, w2, len1 - 1, len2 - 1);
        else
            return dp[len1][len2] = min(solve(w1, w2, len1 - 1, len2),
                                        min(solve(w1, w2, len1, len2 - 1),
                                            solve(w1, w2, len1 - 1, len2 - 1))) + 1;
    }
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        dp = vector<vector<int>>(len1 + 1, vector<int>(len2 + 1, -1));
        return solve(word1, word2, len1, len2);
    }
};

int main()
{
    Solution ins;
    cout<< ins.minDistance("horse", "ros")<< endl;
    return 0;
}
