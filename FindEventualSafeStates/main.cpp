#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    enum State {UNKNOWN, VISITING, SAFE, UNSAFE};
    vector<vector<int>> *G;
    vector<int> ans;
    vector<State> state_;
    int dfs(int cur) {
        if (state_[cur] == VISITING)
            return UNSAFE;
        if (state_[cur] != UNKNOWN)
            return state_[cur];
        state_[cur] = VISITING;
        bool flag = true;
        for (const auto& it : (*G)[cur]) {
            if (dfs(it) == UNSAFE)
                flag = false;
        }
        if (flag) {
            ans.push_back(cur);
            return state_[cur] = SAFE;
        }
        return state_[cur] = UNSAFE;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int N = graph.size();
        G = &graph;
        state_ = vector<State>(N, UNKNOWN);
        for (int i = 0; i < N; i++) {
            if (state_[i] == UNKNOWN)
                dfs(i);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution ins;

    return 0;
}
