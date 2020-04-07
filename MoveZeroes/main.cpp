#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.empty())
            return;
        int pre = 0, cur = 0;
        for (cur = 0; cur < nums.size(); cur++) {
            if (nums[cur])
                nums[pre++] = nums[cur];
        }
        for (; pre < nums.size(); pre++)
            nums[pre] = 0;
    }
};

int main()
{
    return 0;
}
