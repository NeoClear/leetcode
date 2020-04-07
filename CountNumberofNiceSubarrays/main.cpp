#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int count_odd(vector<int>& nums) {
        int cnt = 0;
        for (const auto& it : nums)
            if (it & 0x1)
                cnt++;
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> group = {1};
        // group codes
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & 0x1)
                group.push_back(1);
            else
                group.back()++;
        }
        int cnt = 0;
        // use product rule to calc each subset with k odd numbers
        for (int i = k; i < group.size(); i++)
            cnt += group[i - k] * group[i];
        return cnt;
    }
};

int main()
{
    return 0;
}
