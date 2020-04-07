#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <climits>
#include <queue>

using namespace std;

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        const vector<int> dirs = {1, 0, -1, 0, 1};
        const int n = grid.size();
        const int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, INT_MAX));
        queue<tuple<int, int, int>> q;  // (x, y, o)
        int steps = 0;
        q.push({0, 0, 0});
        visited[0][0] = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int x, y, o;
                tie(x, y, o) = q.front(); q.pop();
                if (x == n - 1 && y == m - 1)
                    return steps;
                for (int i = 0; i < 4; i++) {
                    int tx = x + dirs[i];
                    int ty = y + dirs[i + 1];
                    if (tx < 0 || ty < 0 ||
                        tx >= n || ty >= m)
                        continue;
                    int to = o + grid[tx][ty];
                    if (to >= visited[tx][ty] || to > k)
                        continue;
                    visited[tx][ty] = to;
                    q.push({tx, ty, to});
                }
            }
            steps++;
        }
        return -1;
    }
};

int main() {
    return 0;
}