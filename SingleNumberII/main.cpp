#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            int count = 0;
            for (const auto& it : nums)
                count += 0x01 & (it >> i);
            if (count % 3 != 0)
                ans |= (1 << i);
        }
        return ans;
    }
};

int main()
{
    return 0;
}
