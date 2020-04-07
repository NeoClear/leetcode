#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans_;
    int color_;

    void dfs(int x, int y, int newC) {
        if (ans_[x][y] != color_) return;
        ans_[x][y] = newC;
        vector<int> dirs = {-1, 0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int tx = x + dirs[i];
            int ty = y + dirs[i + 1];
            if (tx < 0 || ty < 0 ||
                tx >= ans_.size() || ty >= ans_[0].size())
                continue;
            dfs(tx, ty, newC);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (newColor == image[sr][sc])
            return image;
        ans_.swap(image);
        color_ = ans_[sr][sc];
        dfs(sr, sc, newColor);
        return ans_;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
