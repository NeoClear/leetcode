#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int tot = accumulate(nums.begin(), nums.end(), 0);
        int acc = 0;
        auto it = nums.begin();
        while (acc * 2 <= tot) {
            acc += *it;
            it++;
        }
        return vector<int>(nums.begin(), it);
    }
};

int main() {
    Solution ins;
    vector<int> in{
        4, 3, 10, 9, 8
    };
    for (const auto& it : ins.minSubsequence(in))
        cout << it << " ";
    return 0;
}

