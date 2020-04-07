#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> candies;
    int target_;
    void solve(vector<int> path, int id) {
        if (accumulate(path.begin(), path.end(), 0) == target_)
            ans.push_back(path);
        if (accumulate(path.begin(), path.end(), 0) > target_)
            return;
        for (int i = id; i < candies.size(); i++) {
            vector<int> pass = vector<int>(path.begin(), path.end());
            pass.push_back(candies[i]);
            solve(pass, i);
        }
    }
    vector<vector<int>> combinationSum(vector<int> candidates, int target) {
        candies.swap(candidates);
        sort(candies.begin(), candies.end());
        target_ = target;
        solve({}, 0);
        return ans;
    }
};

int main()
{
    Solution ins;
    auto ret = ins.combinationSum({2, 3, 5}, 8);
    for (const auto& line : ret) {
        for (const auto& ele : line)
            cout<< ele<< " ";
        cout<< endl;
    }
    return 0;
}
