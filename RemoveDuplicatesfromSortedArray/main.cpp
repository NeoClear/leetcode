#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> nums) {
        if (nums.size() == 0 || nums.size() == 1) return static_cast<int>(nums.size());
        uint64_t N = nums.size();
        int len = 1;
        for (uint64_t i = 1; i < N; i++) {
            if (nums[i] != nums[i - 1]) {
                nums[len] = nums[i];
                len++;
            }
        }
        return len;
    }
};

int main()
{
    Solution ins;
    cout<< ins.removeDuplicates({1, 1, 2})<< endl;
    return 0;
}
