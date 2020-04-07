#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int N = nums.size();
        int odd = 0, even = 0;
        for (int i = 0; i < N; i++) {
            int left = i == 0 ? 1001 : nums[i - 1];
            int right = i == N - 1 ? 1001 : nums[i + 1];
            if (i % 2 == 0) {
                odd += max(0, nums[i] + 1 - min(left, right));
            } else {
                even += max(0, nums[i] + 1 - min(left, right));
            }
        }
        return min(odd, even);
    }
};

int main()
{
    return 0;
}
