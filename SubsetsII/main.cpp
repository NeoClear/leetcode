#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> nums_;
    void solve(vector<int> path, int n) {
        if (n == nums_.size()) {
            ans.push_back(path);
            return;
        }
        path.push_back(nums_[n]);
        for (int i = n + 1; i <= nums_.size(); i++) {
            if (i != n + 1 && i != nums_.size() && nums_[i - 1] == nums_[i])
                continue;
            solve(path, i);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        nums_.swap(nums);
        sort(nums_.begin(), nums_.end());
        for (int i = 0; i <= nums_.size(); i++) {
            if (i != 0 && i != nums_.size() && nums_[i - 1] == nums_[i])
                continue;
            solve({}, i);
        }
        return ans;
    }
};

int main()
{
    vector<int> in = {1, 2, 2};
    Solution ins;
    for (const auto& solution : ins.subsetsWithDup(in)) {
        for (const auto& ele : solution)
            cout<< ele<< " ";
        cout<< endl;
    }
    return 0;
}
