#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int globalmax = nums.front();
        int globalmin = nums.front();
        int localmax = nums.front();
        int localmin = nums.front();
        for (int i = 1; i < nums.size(); i++) {
            int cur = nums[i];
            int temp1 = cur * localmin;
            int temp2 = cur * localmax;
            localmin = min(cur, min(temp1, temp2));
            localmax = max(cur, max(temp1, temp2));
            globalmax = max(globalmax, localmax);
            globalmin = min(globalmin, localmin);
        }
        return globalmax;
    }
};

int main()
{
    Solution ins;
    vector<int> in = {
        7, -2, -4
    };
    cout<< ins.maxProduct(in)<< endl;
    return 0;
}
