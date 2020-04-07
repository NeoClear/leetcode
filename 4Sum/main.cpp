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
    vector<vector<int>> fourSum(vector<int> nums, int target) {
        sort(nums.begin(), nums.end());
        N = nums.size();
        for (int i = 0; i < N - 3; i = next(nums, i)) {
            for (int j = i + 1; j < N - 2; j = next(nums, j)) {
                int ll = j + 1;
                int rr = N - 1;
                while (ll < rr) {
                    if (nums[i] + nums[j] + nums[ll] + nums[rr] < target) {
                        ll = next(nums, ll);
                    } else if (nums[i] + nums[j] + nums[ll] + nums[rr] > target) {
                        rr = prev(nums, rr);
                    } else {
                        ans_.push_back({nums[i], nums[j], nums[ll], nums[rr]});
                        ll = next(nums, ll);
                        rr = prev(nums, rr);
                    }
                }
            }
        }
        return ans_;
    }
};

int main()
{
    Solution ins;
    for (const auto& it : ins.fourSum({1, 0, -1, 0, -2, 2}, 0)) {
        cout<< it[0]<< " "<< it[1]<< " "<< it[2]<< " "<< it[3]<< endl;
    }
    return 0;
}
