#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        uint64_t acc = 0;
        uint64_t mx = 0;
        bool hasZero = false;
        for (const auto& it : nums) {
            hasZero |= it == 0 ? true : false;
            mx = max(mx, static_cast<uint64_t>(it));
            acc += static_cast<uint64_t>(it);
        }
        int ret = static_cast<int>((mx + 1) * mx / 2 - acc);
        return hasZero ? (ret == 0 ? static_cast<int>(mx + 1) : ret) : 0;
    }
};

int main()
{
    return 0;
}
