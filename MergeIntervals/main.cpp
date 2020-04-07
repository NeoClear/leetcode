#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<pair<int, int>> vec_;
        for (const auto& it : intervals) vec_.push_back({it[0], it[1]});
        sort(vec_.begin(), vec_.end());
        vector<vector<int>> ans_;
        for (int i = 0; i < intervals.size(); i++) {
            int l_ = vec_[i].first;
            int r_ = vec_[i].second;
            while (i < intervals.size() - 1 && r_ >= vec_[i + 1].first) {
                r_ = max(r_, vec_[i + 1].second);
                i++;
            }
            ans_.push_back({l_, r_});
        }
        return ans_;
    }
};

int main()
{
    return 0;
}
