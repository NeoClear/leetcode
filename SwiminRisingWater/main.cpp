#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int, int>> q;
        int N = grid.size();
        q.push({-grid[0][0], 0});
        vector<int> dirs{-1, 0, 1, 0, -1};
        vector<bool> seen(N * N, false);
        seen[0] = true;
        while (!q.empty()) {
            auto node = q.top(); q.pop();
            int time = -node.first;
            int x = node.second / N;
            int y = node.second % N;
            if (x == N - 1 && y == N - 1) return time;
            for (int i = 0; i < 4; i++) {
                int tx = x + dirs[i];
                int ty = y + dirs[i + 1];
                if (tx < 0 || ty < 0 || tx >= N || ty >= N) continue;
                if (seen[tx * N + ty]) continue;
                seen[tx * N + ty] = true;
                q.push({-max(time, grid[tx][ty]), tx * N + ty});
            }
        }
        return  -1;
    }
};

int main()
{
    Solution ins;
    vector<vector<int>> in = {
        {0, 2},
        {1, 3}
    };
    cout<< ins.swimInWater(in)<< endl;
    return 0;
}
