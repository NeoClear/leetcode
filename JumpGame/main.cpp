#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int pre = 0, cur = 0;
        int i = 0;
        nums.back() = 1;
        while (cur < nums.size() - 1) {
            pre = cur;
            for (; i <= pre; i++) {
                cur = max(cur, i + nums[i]);
            }
            if (cur == pre)
                return false;
        }
        return true;
    }
};

int main()
{
    return 0;
}
