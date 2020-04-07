#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int nextDir(int d) {
        return (d + 1) & 3;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        int xm = matrix.size(), ym = matrix[0].size();
        vector<int> limit = {0, ym - 1, xm - 1, 0};
        int& xbase = limit[0];
        int& xtop = limit[2];
        int& ybase = limit[3];
        int& ytop = limit[1];
        pair<int, int> pos = {0, 0};
        vector<int> ans;
        int dir = 0;
        while (xbase <= xtop && ybase <= ytop) {
//            cout<< pos.first<< ", "<< pos.second<< endl;
            ans.push_back(matrix[pos.first][pos.second]);
            if ((dir == 0 && pos.second ==  ytop) ||
                    (dir == 1 && pos.first == xtop) ||
                    (dir == 2 && pos.second == ybase) ||
                    (dir == 3 && pos.first == xbase)) {
                if (dir == 1 || dir == 2)
                    limit[dir]--;
                else
                    limit[dir]++;
                dir = nextDir(dir);
            }
            switch (dir) {
            case 0:
                pos.second++;
                break;
            case 1:
                pos.first++;
                break;
            case 2:
                pos.second--;
                break;
            case 3:
                pos.first--;
                break;
            }
        }
        return ans;
    }
};

int main()
{
    Solution ins;
    vector<vector<int>> in = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    for (const auto& it : ins.spiralOrder(in))
        cout<< it<< " ";
    return 0;
}
