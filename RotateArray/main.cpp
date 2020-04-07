#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void convert(vector<int>& nums, int k) {
        vector<int> temp;
        for (int i = nums.size() - k; i < nums.size(); i++) {
            temp.push_back(nums[i]);
        }
        for (int i = nums.size() - k - 1; i >= 0; i--) {
            nums[i + k] = nums[i];
        }
        for (int i = 0; i < k; i++)
            nums[i] = temp[i];
    }
    void rotate(vector<int>& nums, int k) {
        if (nums.empty())
            return;
        k %= nums.size();
        convert(nums, k);
    }
};

int main()
{
    return 0;
}
