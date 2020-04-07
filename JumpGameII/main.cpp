#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int N;
    int jump(vector<int> nums) {
        N = nums.size();
        int pre = 0, cur = 0;
        int i = 0;
        int ret = 0;
        while (cur < N - 1) {
            pre = cur;
            for (; i <= pre; i++) {
                cur = max(cur, nums[i] + i);
            }
            ret++;
            if (cur == pre) return -1;
        }
        return ret;
    }
};

int main()
{
    Solution ins;
    cout<< ins.jump({2, 3, 1, 1, 4})<< endl;
    return 0;
}
