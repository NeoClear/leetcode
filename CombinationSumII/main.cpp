#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> candies;
    int target_;
    set<vector<int>> ans;
    void solve(vector<int> path, int id) {
        if (accumulate(path.begin(), path.end(), 0) == target_) {
            ans.insert(path);
            return;
        }
        if (accumulate(path.begin(), path.end(), 0) > target_ || id >= candies.size())
            return;
        for (int i = id; i < candies.size(); i++) {
            vector<int> pass = vector<int>(path.begin(), path.end());
            pass.push_back(candies[i]);
            solve(pass, i + 1);
        }
    }
    vector<vector<int>> combinationSum2(vector<int> candidates, int target) {
        candies.swap(candidates);
        sort(candies.begin(), candies.end());
        target_ = target;
        solve({}, 0);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};

int main()
{
    Solution ins;
    auto ret = ins.combinationSum2({10,1,2,7,6,1,5}, 8);
    for (const auto& line : ret) {
        for (const auto& ele : line)
            cout<< ele<< " ";
        cout<< endl;
    }
    return 0;
}
