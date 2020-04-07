#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty())
            return {};
        if (nums.size() == 1)
            return {to_string(nums.front())};
        int64_t pre = nums.front();
        int64_t cur;
        vector<string> ans;
        for (int64_t i = 1; i < nums.size(); i++) {
            int64_t n = nums[i];
            int64_t p = nums[i - 1];
            if (n - p == 1)
                continue;
            cur = p;
            if (cur == pre)
                ans.push_back(to_string(cur));
            else
                ans.push_back(to_string(pre) + "->" + to_string(cur));
            pre = n;
        }
        cur = nums.back();
        if (cur == pre)
            ans.push_back(to_string(cur));
        else
            ans.push_back(to_string(pre) + "->" + to_string(cur));
        return ans;
    }
};

int main()
{
    vector<int> in = {
        0, 2, 3, 4, 6, 8, 9
    };
    Solution ins;
    for (const auto& it : ins.summaryRanges(in))
        cout<< it<< endl;
    return 0;
}
