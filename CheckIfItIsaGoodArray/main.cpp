#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    bool isGoodArray(vector<int>& nums) {
        int remainder = nums.front();
        for (const auto& it : nums)
            remainder = gcd(remainder, it);
        return remainder == 1;
    }
};

int main()
{
    return 0;
}
