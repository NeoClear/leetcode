#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    struct Node {
        int x;
        int y;
        int h;
        bool operator <(const Node& k) {
            return h < k.h;
        }
    };
    vector<vector<int>> forest_;
    pair<int, int> prev_ = {0, 0};
    int R_, C_;
    vector<Node> vec_;
    int steps_ = 0;
    bool solve(int x, int y) {
        auto visited = vector<vector<int>>(R_, vector<int>(C_, 0));
        queue<pair<int, int>> q;
        q.push(prev_);
        int level = 0;
        vector<int> dirs = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto cur = q.front(); q.pop();
                int dx = cur.first;
                int dy = cur.second;
                if (visited[dx][dy]) continue;
                visited[dx][dy] = 1;
                if (dx == x && dy == y) {
                    forest_[x][y] = 1;
                    steps_ += level;
                    prev_ = {x, y};
                    return true;
                }
                for (int i = 0; i < 4; i++) {
                    int tx = dx + dirs[i];
                    int ty = dy + dirs[i + 1];
                    if (tx < 0 || ty < 0 ||
                        tx >= R_ || ty >= C_ ||
                        forest_[tx][ty] == 0)
                        continue;
                    q.push({tx, ty});
                }
            }
            level++;
        }
        return false;
    }
    int cutOffTree(vector<vector<int>>& forest) {
        R_ = forest.size();
        C_ = forest[0].size();
        forest_.swap(forest);
        for (int i = 0; i < R_; i++) {
            for (int j = 0; j < C_; j++) {
                if (forest_[i][j] > 1) {
                    vec_.push_back((Node){i, j, forest_[i][j]});
                }
            }
        }
        sort(vec_.begin(), vec_.end());
        for (const auto& tree : vec_)
            if (!solve(tree.x, tree.y))
                return -1;
        return steps_;
    }
};

int main()
{
    return 0;
}
