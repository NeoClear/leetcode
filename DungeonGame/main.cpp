#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int r = dungeon.size();
        int c = dungeon[0].size();
        auto maps = vector<vector<int>>(r + 1, vector<int>(c + 1, INT_MAX));
        maps[r][c - 1] = 1;
        maps[r - 1][c] = 1;
        for (int i = r - 1; i >= 0; i--) {
            for (int j = c - 1; j >= 0; j--) {
                maps[i][j] = max(1,
                                 min(maps[i + 1][j], maps[i][j + 1]) - dungeon[i][j]);
            }
        }
        return maps.front().front();
    }
};

int main()
{
    return 0;
}
