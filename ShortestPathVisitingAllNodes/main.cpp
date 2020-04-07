#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<vector<int>> visited(N, vector<int>(1 << N, 0));
        queue<pair<int, int>> q;
        int finalState = (1 << N) - 1;

        for (int i = 0; i < N; i++) { q.push({i, 1 << i}); }
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto n_ = q.front(); q.pop();
                int cur_ = n_.first;
                int state_ = n_.second;
                if (state_ == finalState) return steps;
                if (visited[cur_][state_]) continue;
                visited[cur_][state_] = 1;
                for (auto it : graph[cur_]) {
                    q.push({it, state_ | (1 << it)});
                }
            }
            steps++;
        }
        return -1;
    }
};

int main()
{
    Solution ins;
    vector<vector<int>> in = {{1,2,3},{0},{0},{0}};
    cout<< ins.shortestPathLength(in)<< endl;
    return 0;
}
