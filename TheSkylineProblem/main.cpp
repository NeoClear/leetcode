#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    multiset<int> set_;
    int Max() {
        return set_.empty() ? 0 : *set_.rbegin();
    }
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        typedef pair<int, int> Event;
        vector<Event> event_;
        for (const auto& kv : buildings) {
            event_.emplace_back(kv[0], kv[2]);
            event_.emplace_back(kv[1], -kv[2]);
        }
        sort(event_.begin(), event_.end(), [](const Event& a, const Event& b) {
            if (a.first == b.first)
                return a.second > b.second;
            return a.first < b.first;
        });
        vector<vector<int>> ans_;
        for (const auto& e : event_) {
            int axis = e.first;
            bool enter = e.second > 0;
            int h_ = abs(e.second);
            if (enter) {
                if (h_ > Max()) ans_.push_back({axis, h_});
                set_.insert(h_);
            } else {
                set_.erase(set_.equal_range(h_).first);
                if (h_ > Max()) ans_.push_back({axis, Max()});
            }
        }
        return ans_;
    }
};

int main()
{
    return 0;
}
