#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (const auto& it : nums)
            ans ^= it;
        return ans;
    }
};

int main()
{
    return 0;
}
