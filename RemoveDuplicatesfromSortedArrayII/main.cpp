#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = 0;
        int checks = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i - 1] != nums[i]) {
                checks = 1;
                nums[len] = nums[i];
                len++;
            } else {
                if (checks < 2) {
                    checks++;
                    nums[len] = nums[i];
                    len++;
                }
            }
        }
        return len;
    }
};

int main()
{
    Solution ins;
    vector<int> in = {
        1, 1, 1, 2, 3, 3, 3, 3
    };
    int n;
    n = ins.removeDuplicates(in);
    for (int i = 0; i < n; i++)
        cout<< in[i]<< " ";
    return 0;
}
