#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int count(vector<int>& nums, int v) {
        int cnt = 0;
        for (const auto& it : nums)
            if (it == v)
                cnt++;
        return cnt;
    }
    vector<int> majorityElement(vector<int>& nums) {
        int a = -1, b = -1;
        int ca = 0, cb = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (a != -1 && nums[i] == nums[a])
                ca++;
            else if (b != -1 && nums[i] == nums[b])
                cb++;
            else if (ca == 0)
                ca = 1, a = i;
            else if (cb == 0)
                cb = 1, b = i;
            else
                ca--, cb--;
        }
        vector<int> ans;
        if (a != -1 && count(nums, nums[a]) > nums.size() / 3)
            ans.push_back(nums[a]);
        if (b != -1 && count(nums, nums[b]) > nums.size() / 3)
            ans.push_back(nums[b]);
        return ans;

    }
};

int main()
{
    return 0;
}
