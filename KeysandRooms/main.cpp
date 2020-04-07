#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int N = rooms.size();
        vector<int> visited(N, 0);
        vector<int> dfs(0);
        dfs.push_back(0);
        while (!dfs.empty()) {
            int node_ = dfs.back(); dfs.pop_back();
            visited[node_] = 1;
            for (const auto& reach : rooms[node_]) {
                if (visited[reach]) continue;
                dfs.push_back(reach);
            }
        }
        if (accumulate(visited.begin(), visited.end(), 0) == N)
            return true;
        return false;
    }
};

int main()
{
    Solution ins;
    vector<vector<int>> in = {
        {1, 3},
        {3, 0, 1},
        {2},
        {0}
    };
    if (ins.canVisitAllRooms(in))
        cout<< "True"<< endl;
    else
        cout<< "False"<< endl;
    return 0;
}
