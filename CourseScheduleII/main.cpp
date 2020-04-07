#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<int, vector<int>> graph;
    vector<int> status;
    vector<int> ans;
    // 0 unvisited
    // 1 visiting
    // 2 visited
    bool dfs(int id) {
        if (status[id] == 1)
            return false;
        if (status[id] == 2)
            return true;
        status[id] = 1;
        for (const auto& dest : graph[id])
            if (!dfs(dest))
                return false;
        status[id] = 2;
        ans.push_back(id);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        status = vector<int>(numCourses, 0);
        for (const auto& it : prerequisites)
            graph[it.back()].push_back(it.front());
        for (int i = 0; i < numCourses; i++)
            if (!dfs(i))
                return {};
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution ins;
    return 0;
}
