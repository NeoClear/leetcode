#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<int64_t> set_;
        if (t < 0)
            return false;
        for (int i = 0; i < nums.size(); i++) {
            int64_t cur = nums[i];
            set_.insert(cur);
            if (set_.size() > k + 1) {
                set_.erase(set_.find(nums[i - k - 1]));
            }
            if (set_.count(cur) > 1)
                return true;
            auto up = set_.upper_bound(cur);
            if (up != set_.end() && *up - cur <= t)
                return true;
            auto low = set_.lower_bound(cur);
            if (low != set_.begin() && cur - *prev(low) <= t)
                return true;
        }
        return false;
    }
};

int main()
{
    vector<int> in = {1, 5, 9, 1, 5, 9};
    Solution ins;
    if (ins.containsNearbyAlmostDuplicate(in, 2, 3))
        cout<< "YES"<< endl;
    else
        cout<< "NO"<< endl;
    return 0;
}
