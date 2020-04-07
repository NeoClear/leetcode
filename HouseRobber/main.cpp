#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        if (nums.size() <= 2)
            return max(nums.front(), nums.back());
        int back = nums.back();
        nums.pop_back();
        vector<int> select(nums.size());
        vector<int> discard(nums.size());
        select.front() = nums.front();
        discard.front() = 0;
        select[1] = nums[1];
        discard[1] = select.front();
        for (int i = 2; i < nums.size(); i++) {
            select[i] = max(discard[i - 1], discard[i - 2]) + nums[i];
            discard[i] = max(select[i - 1], select[i - 2]);
        }
        int ans = max(select.back(), discard.back());
        nums.push_back(back);
        nums = vector<int>(next(nums.begin()), nums.end());
        select = vector<int>(nums.size());
        discard = vector<int>(nums.size());
        select.front() = nums.front();
        discard.front() = 0;
        select[1] = nums[1];
        discard[1] = select.front();
        for (int i = 2; i < nums.size(); i++) {
            select[i] = max(discard[i - 1], discard[i - 2]) + nums[i];
            discard[i] = max(select[i - 1], select[i - 2]);
        }
        return max(ans, max(select.back(), discard.back()));
    }
};

int main()
{
    return 0;
}
