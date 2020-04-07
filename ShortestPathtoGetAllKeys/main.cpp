#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int cons(int r, int c, int state) {
        return (r << 16) | (c << 8) | state;
    }
    int row(int con) {
        return con >> 16;
    }
    int col(int con) {
        return (con >> 8) & 0xff;
    }
    int state(int con) {
        return con & 0xff;
    }
    int shortestPathAllKeys(vector<string>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<int> q;
        vector<vector<vector<int>>> seen(rows, vector<vector<int>>(cols, vector<int>(64, 0)));
        int allKeys = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                const char c = grid[i][j];
                if (c == '@') { q.push(cons(i, j, 0)); seen[i][j][0] = 1; }
                else if (c >= 'a' && c <= 'f') allKeys |= (1 << (c - 'a'));
            }
        }
        vector<int> dirs = {-1, 0, 1, 0, -1};
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                const auto node = q.front(); q.pop();
                int r_ = row(node);
                int c_ = col(node);
                int state_ = state(node);
                if (state_ == allKeys)
                    return steps;
                for (int i = 0; i < 4; i++) {
                    int tx = r_ + dirs[i];
                    int ty = c_ + dirs[i + 1];
                    int nkeys = state_;
                    if (tx < 0 || ty < 0 ||
                        tx >= rows || ty >= cols) continue;
                    const char att = grid[tx][ty];
                    if (att == '#') continue;
                    if (att >= 'A' && att <= 'F' && !(state_ & (1 << (att - 'A')))) continue;
                    if (seen[tx][ty][state_]) continue;
                    if (att >= 'a' && att <= 'f') nkeys |= 1 << (att - 'a');
                    seen[tx][ty][nkeys] = 1;
                    q.push(cons(tx, ty, nkeys));
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
    vector<string> in = {"Dd#b@",".fE.e","##.B.","#.cA.","aF.#C"};
    cout<< ins.shortestPathAllKeys(in)<< endl;
    return 0;
}
