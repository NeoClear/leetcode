#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1)
            return nums.front();
        if (nums.front() < nums.back())
            return nums.front();
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] < nums[i - 1])
                return nums[i];
    }
};

int main()
{
    return 0;
}
