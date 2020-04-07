#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int zero = 0;
    int64_t sums(vector<int>& nums) {
        int64_t ans = 1;
        for (const auto& it : nums) {
            if (it == 0) {
                zero++;
                continue;
            }
            ans *= static_cast<int64_t>(it);
        }
        return ans;
    }
    vector<int> productExceptSelf(vector<int>& nums) {
        int64_t ans = sums(nums);
        if (zero >= 2)
            return vector<int>(nums.size(), 0);
        vector<int> ret;
        for (const auto& it : nums) {
            if (zero == 1) {
                ret.push_back(it == 0 ? ans : 0);
            } else {
                ret.push_back(ans / it);
            }
        }
        return ret;
    }
};

int main()
{
    return 0;
}
