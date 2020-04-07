#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = 0;
        for (const auto& n : nums)
            if (n != val)
                nums[len++] = n;
        return len;
    }
};

int main()
{
    return 0;
}
