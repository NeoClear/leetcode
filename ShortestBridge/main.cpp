#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int N;
    queue<pair<int, int>> q;
    void dfs(int x, int y, vector<vector<int>>& A) {
        if (x < 0 || y < 0 ||
            x >= N || y >= N ||
            A[x][y] != 1) return;
        A[x][y] = 2;
        q.push({0, x * N + y});
        vector<int> dirs = {-1, 0, 1, 0, -1};
        for (int i = 0; i < 4; i++) dfs(x + dirs[i], y + dirs[i + 1], A);
    }
    int bfs(vector<vector<int>>& A) {
        while (!q.empty()) {
            auto node = q.front(); q.pop();
            int d = node.first;
            int x = node.second / N;
            int y = node.second % N;
            vector<int> dirs = {-1, 0, 1, 0, -1};
            if ((A[x][y] & 1) == 1) {
                return d;
            }
            for (int i = 0; i < 4; i++) {
                int tx = x + dirs[i];
                int ty = y + dirs[i + 1];
                int id = tx * N + ty;
                if (tx < 0 || ty < 0 ||
                    tx >= N || ty >= N ||
                    (A[tx][ty] & 2) == 2)
                    continue;
                A[tx][ty] |= 2;
                q.push({d + 1, id});
            }
        }
        return -1;
    }
    int shortestBridge(vector<vector<int>>& A) {
        N = A.size();
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (A[i][j] == 1) { dfs(i, j, A); goto what; }
    what:
//        for (int i = 0; i < N; i++) {
//            for (int j = 0; j < N; j++) {
//                cout<< A[i][j];
//            }
//            cout<< endl;
//        }
        return bfs(A) - 1;
    }
};

int main()
{
    Solution ins;
    vector<vector<int>> in = {{1,1,1,1,1},{1,0,0,0,1},{1,0,1,0,1},{1,0,0,0,1},{1,1,1,1,1}};
    cout<< ins.shortestBridge(in)<< endl;
    return 0;
}
