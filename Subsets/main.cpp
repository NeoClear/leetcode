#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;
    vector<int> nums_;
    void solve(int n) {
        if (n == nums_.size()) {
            ans.push_back(cur);
            return;
        }
        cur.push_back(nums_[n]);
        for (int i = n + 1; i <= nums_.size(); i++) {
            solve(i);
        }
        cur.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        nums_.swap(nums);
        for (int i = 0; i <= nums_.size(); i++)
            solve(i);
        return ans;
    }
};

int main()
{
    Solution ins;
    vector<int> in = {
        1, 2, 3
    };
    for (const auto& subset : ins.subsets(in)) {
        for (const auto& ele : subset)
            cout<< ele<< " ";
        cout<< endl;
    }
    return 0;
}
