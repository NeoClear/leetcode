#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.empty())
            return false;
        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());
        vector<bool> cnt = vector<bool>(mx - mn + 1, false);
        for (const auto& it : nums) {
            uint64_t id = it - mn;
            if (cnt[id])
                return true;
            cnt[id] = true;
        }
        return false;
    }
};

int main()
{
    return 0;
}
