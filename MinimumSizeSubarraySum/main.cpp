#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (accumulate(nums.begin(), nums.end(), 0) < s)
            return 0;
        int len = INT_MAX;
        int l = 0, r = 0;
        int sum = nums.front();
        while (r < nums.size()) {
            if (sum >= s) {
                len = min(len, r - l + 1);
                sum -= nums[l];
                l++;
            } else {
                r++;
                sum += r == nums.size() ? 0 : nums[r];
            }
            if (len == 1)
                break;
        }
        return len;
    }
};

int main()
{
    Solution ins;
    vector<int> in = {
        2, 3, 1, 2, 4, 3
    };
    cout<< ins.minSubArrayLen(7, in);
    return 0;
}
