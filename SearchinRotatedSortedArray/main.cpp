#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        if (nums.size() == 1) return nums.front() == target ? 0 : -1;
        if (target == nums[0]) return 0;
        if (target == nums.back()) return nums.size() - 1;
        int l = 0;
        int r = nums.size() - 1;
        int mid;

        if (nums.front() < nums.back()) {
            while (l <= r) {
                mid = (l + r) / 2;
                if (nums[mid] < target)
                    l = mid + 1;
                else if (nums[mid] > target)
                    r = mid - 1;
                else
                    return mid;
            }
            return -1;
        }

        if (target < nums.back()) {
            while (l <= r) {
                mid = (l + r) / 2;
                if (nums[mid] > target) {
                    if (nums[mid] >= nums.front()) {
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                } else if (nums[mid] < target) {
                    l = mid + 1;
                } else
                    return mid;
            }
        } else if (target > nums.front()) {
            while (l <= r) {
                mid = (l + r) / 2;
                if (nums[mid] > target) {
                    r = mid - 1;
                } else if (nums[mid] < target) {
                    if (nums[mid] >= nums.front()) {
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                } else
                    return mid;
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> in = {
        4, 5, 6, 7, 0, 1, 2
    };
    Solution ins;
    cout<< ins.search(in, 3)<< endl;
    return 0;
}
