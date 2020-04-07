#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        map<pair<int, int>, int> map_;
        vector<int> ans_;
        int maxHeight = 0;
        for (const auto& kv : positions) {
            int start = kv[0];
            int height = kv[1];
            int end = start + height;
            auto it = map_.upper_bound({start, end});
            if (it != map_.begin()) {
                auto it2 = it;
                if ((--it2)->first.second > start) it = it2;
            }
            int baseHeight = 0;
            vector<tuple<int, int, int>> ranges;
            while (it != map_.end() && it->first.first < end) {
                const int s_ = it->first.first;
                const int e_ = it->first.second;
                const int h_ = it->second;
                if (s_ < start) ranges.emplace_back(s_, start, h_);
                if (e_ > end) ranges.emplace_back(end, e_, h_);
                baseHeight = max(baseHeight, h_);
                it = map_.erase(it);
            }
            int newHeight = height + baseHeight;
            map_[{start, end}] = newHeight;
            for (const auto& range : ranges) {
                map_[{get<0>(range), get<1>(range)}] = get<2>(range);
            }
            maxHeight = max(maxHeight, newHeight);
            ans_.push_back(maxHeight);
        }
        return ans_;
    }
};

int main()
{
    return 0;
}
