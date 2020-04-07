#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int nextDir(int d) {
        return (d + 1) & 3;
    }
    vector<vector<int>> generateMatrix(int n) {
        auto ans = vector<vector<int>>(n, vector<int>(n, 0));
        vector<int> dirs = {0, 1, 0, -1, 0};
        pair<int, int> pos = {0, 0};
        int dir = 0;
        for (int i = 1; i <= n * n; i++) {
            ans[pos.first][pos.second] = i;
            int tx = pos.first + dirs[dir];
            int ty = pos.second + dirs[dir + 1];
            if (tx < 0 || ty < 0 ||
                tx >= n || ty >= n ||
                ans[tx][ty] != 0)
                dir = nextDir(dir);
            pos = {pos.first + dirs[dir], pos.second + dirs[dir + 1]};
        }
        return ans;
    }
};

int main()
{
    Solution ins;
    for (const auto& line : ins.generateMatrix(4)) {
        for (const auto& ele : line)
            cout<< ele<< " ";
        cout<< endl;
    }
    return 0;
}
