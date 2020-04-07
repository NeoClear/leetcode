#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<int, vector<int>> map_;
    vector<int> status_;
    // 0 unvisited
    // 1 visiting
    // 2 visited
    unordered_set<int> prim_;
    bool lock = false;
    void solve(int cur) {
        if (status_[cur] == 2) return;
        if (status_[cur] == 1) {
            lock = true;
            return;
        }
        status_[cur] = 1;
        for (const auto& dest : map_[cur])
            solve(dest);
        status_[cur] = 2;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < numCourses; i++) prim_.insert(i);
        status_ = vector<int>(numCourses, 0);
        for (const auto& pre : prerequisites) {
            if (prim_.count(pre[0])) prim_.erase(pre[0]);
            map_[pre[1]].push_back(pre[0]);
        }
        for (const auto& it : prim_) {
            solve(it);
        }
        if (lock) return false;
        for (const auto& flag : status_)
            if (flag == 0) return false;
        return true;
    }
};

int main()
{
    return 0;
}
