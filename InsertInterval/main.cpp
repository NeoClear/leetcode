#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int left_ = newInterval[0];
        int right_ = newInterval[1];
        vector<vector<int>> ans_;
        for (const auto& it : intervals) {
            int l = it[0], r = it[1];
            if (r < left_ || l > right_) {
                ans_.push_back({l, r});
            } else {
                left_ = min(left_, l);
                right_ = max(right_, r);
            }
        }
        ans_.push_back({left_, right_});
        sort(ans_.begin(), ans_.end());
        return ans_;
    }
};

int main()
{
    Solution ins;
    vector<vector<int>> in = {
        {1, 3},
        {6, 9}
    };
    vector<int> n_ = {
        2, 5
    };
    for (const auto& it : ins.insert(in, n_)) cout<< "["<< it[0]<< ", "<< it[1]<< "]"<< endl;
    return 0;
}
