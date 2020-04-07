#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
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
    int threeSumClosest(vector<int> nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = INT_MAX / 2;
        N = nums.size();
        for (int i = 0; i < N - 2; i = next(nums, i)) {
            int ll = i + 1;
            int rr = N - 1;
            while (ll < rr) {
                if (nums[i] + nums[ll] + nums[rr] < target) {
                    ans = abs(nums[i] + nums[ll] + nums[rr] - target) < abs(ans - target) ?\
                                nums[i] + nums[ll] + nums[rr] : ans;
                    ll = next(nums, ll);
                } else if (nums[i] + nums[ll] + nums[rr] > target) {
                    ans = abs(nums[i] + nums[ll] + nums[rr] - target) < abs(ans - target) ?\
                                nums[i] + nums[ll] + nums[rr] : ans;
                    rr = prev(nums, rr);
                } else
                    return target;
            }
        }
        return ans;
    }
};

int main()
{
    Solution ins;
    cout<< ins.threeSumClosest({0, 1, 2}, 3)<< endl;
    return 0;
}
