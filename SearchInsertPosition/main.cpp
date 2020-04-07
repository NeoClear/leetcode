#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int> nums, int target) {
        int left = 0, right = nums.size() - 1;
        int mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else
                return mid;
        }
        return left;
    }
};

int main()
{
    Solution ins;
    cout<< ins.searchInsert({1, 3, 5, 6}, 7)<< endl;
    return 0;
}
