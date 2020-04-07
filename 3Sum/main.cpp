#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans_;
    int N;
    int next(vector<int>& nums, int id) {
        int i = id + 1;
        while (i == nums.size() ? false : nums[i] == nums[id]) i++;
        return i;
    }
    int prev(vector<int>& nums, int id) {
        int i = id - 1;
        while (i < 0 ? false : nums[i] == nums[id]) i--;
        return i;
    }
    vector<vector<int>> threeSum(vector<int> nums) {
        sort(nums.begin(), nums.end());
        N = nums.size();
        for (int i = 0; i < N - 2; i = next(nums, i)) {
            int ll = i + 1;
            int rr = N - 1;
            while (ll < rr) {
                if (nums[i] + nums[ll] + nums[rr] < 0) {
                    ll = next(nums, ll);
                } else if (nums[i] + nums[ll] + nums[rr] > 0) {
                    rr = prev(nums, rr);
                } else {
                    ans_.push_back({nums[i], nums[ll], nums[rr]});
                    ll = next(nums, ll);
                    rr = prev(nums, rr);
                }
            }
        }
        return ans_;
    }
};

int main()
{
    Solution ins;
    for (const auto& it : ins.threeSum({-1, 0, 1, 2, -1, -4}))
        cout<< it[0]<< ", "<< it[1]<< ", "<< it[2]<< endl;
    return 0;
}
