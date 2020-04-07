#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> pre, post;
    void genPre(vector<int>& prices) {
        pre[0] = 0;
        int low = prices.front();
        for (int i = 1; i < prices.size(); i++) {
            pre[i] = max(pre[i - 1], prices[i] - low);
            low = min(low, prices[i]);
        }
    }
    void genPost(vector<int>& prices) {
        post[prices.size() - 1] = 0;
        int high = prices.back();
        for (int i = prices.size() - 2; i >= 0; i--) {
            post[i] = max(post[i + 1], high - prices[i]);
            high = max(high, prices[i]);
        }
    }
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        pre = vector<int>(prices.size());
        post = vector<int>(prices.size());
        genPre(prices);
        genPost(prices);
        int profit = 0;
        for (int i = 0; i < prices.size() - 1; i++) {
            profit = max(profit, pre[i] + post[i + 1]);
        }
        return max(profit, pre.back());
    }
};

int main()
{
    Solution ins;
    vector<int> in = {7,6,4,3,1};
    cout<< ins.maxProfit(in)<< endl;
    return 0;
}
