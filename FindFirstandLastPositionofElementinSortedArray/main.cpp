#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> nums, int target) {
        if (nums.empty()) return {-1, -1};
        int left = 0, right = nums.size() - 1;
        int mid;
        vector<int> ans;
        while (left < right) {
            mid = (left + right) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (nums[left] != target)
            return {-1, -1};
        ans.push_back(left);
        right = nums.size() - 1;
        while (left < right) {
            mid = (left + right + 1) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            } else
                left = mid;
        }
        ans.push_back(left);
        return ans;
    }
};

int main()
{
    Solution ins;
    for (const auto& it : ins.searchRange({6, 7, 7, 8, 8, 8, 8, 8, 10}, 8))
        cout<< it<< endl;
    return 0;
}
