#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        int ans = 0;
        int low = prices.front();
        for (int i = 1; i < prices.size(); i++) {
            ans = max(ans, prices[i] - low);
            low = min(low, prices[i]);
        }
        return ans;
    }
};

int main()
{
    return 0;
}
