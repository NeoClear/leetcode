#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int res = 0;
        for (const auto& it : nums)
            res ^= it;
        int low = res & -res;
        int a1 = 0, a2 = 0;
        for (const auto& it : nums) {
            if (low & it)
                a1 ^= it;
            else
                a2 ^= it;
        }
        return {a1, a2};
    }
};

int main()
{
    return 0;
}
