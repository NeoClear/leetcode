#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        if (nums.size() <= 2)
            return max(nums.front(), nums.back());
        vector<int> select(nums.size() - 1);
        vector<int> discard(nums.size() - 1);
        select.front() = nums.front();
        discard.front() = 0;
        select[1] = nums[1];
        discard[1] = select.front();
        for (int i = 2; i < nums.size() - 1; i++) {
            select[i] = max(discard[i - 1], discard[i - 2]) + nums[i];
            discard[i] = max(select[i - 1], select[i - 2]);
        }
        int ans = max(select.back(), discard.back());
        select.clear();
        select = vector<int>(nums.size() - 1);
        discard.clear();
        discard = vector<int>(nums.size() - 1);
        select.front() = nums[1];
        discard.front() = 0;
        select[1] = nums[2];
        discard[1] =select[1];
        for (int i = 2; i < nums.size() - 1; i++) {
            select[i] = max(discard[i - 1], discard[i - 2]) + nums[i + 1];
            discard[i] = max(select[i - 1], select[i - 2]);
        }
        ans = max(ans, max(select.back(), discard.back()));
        return ans;
    }
};

int main()
{
    return 0;
}
