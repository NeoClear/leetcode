#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size();
        vector<pair<int, int>> dirs = {
            {0, 0},
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0}
        };
        auto gen = [](int x, int y) {
            return (x << 16) | y;
        };
        auto getX = [](int addr) {
            return addr >> 16;
        };
        auto getY = [](int addr) {
            return addr & 0xffff;
        };
        // -cost, id
        priority_queue<pair<int, int>> q;
        unordered_set<int> visited;
        q.push({0,  0});
        while (!q.empty()) {
            int addr, cost;
            tie(cost, addr) = q.top();
            q.pop();
            int x = getX(addr);
            int y = getY(addr);
            cost = -cost;
            // cout << "cost: " << cost << ", index: (" << x << ", " << y << ")" << endl;
            if (x == M - 1 && y == N - 1)
                return cost;
            if (visited.count(addr))
                continue;
            visited.insert(addr);
            for (int i = 1; i <= 4; i++) {
                int tx = x + dirs[i].first;
                int ty = y + dirs[i].second;
                if (tx < 0 || tx >= M ||
                    ty < 0 || ty >= N)
                    continue;
                if (grid[x][y] == i)
                    q.push({-cost, gen(tx, ty)});
                else
                    q.push({-cost - 1, gen(tx, ty)});
            }
        }
        return INT_MAX;
    }
};

int main() {
    Solution ins;
    vector<vector<int>> in{
        {1,1,1,1},{2,2,2,2},{1,1,1,1},{2,2,2,2}
    };
    cout << ins.minCost(in);
    return 0;
}
