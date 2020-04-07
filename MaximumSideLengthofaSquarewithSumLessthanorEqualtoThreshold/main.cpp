#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> sums;
    int get_sum(int i, int j) {
        if (i < 0 || j < 0)
            return 0;
        return sums[i][j];
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        if (mat.empty())
            return 0;
        sums = vector<vector<int>>(mat.size(), vector<int>(mat[0].size(), 0));
        for (int i = 0; i < mat.size(); i++) {
            int cnt = 0;
            for (int j = 0; j < mat[0].size(); j++) {
                cnt += mat[i][j];
                sums[i][j] = cnt + (i == 0 ? 0 : sums[i - 1][j]);
            }
        }
        // for (const auto& line : sums) {
        //     for (const auto& ele : line)
        //         cout << ele << " ";
        //     cout << endl;
        // }
        for (int side = min(mat.size(), mat[0].size()); side >= 0; side--) {
            for (int i = 0; i <= mat.size() - side; i++) {
                for (int j = 0; j <= mat[0].size() - side; j++) {
                    if (get_sum(i + side - 1, j + side - 1) - get_sum(i + side - 1, j - 1) -
                        get_sum(i - 1, j + side - 1) + get_sum(i - 1, j - 1) <= threshold)
                        return side;
                }
            }
        }
        return 0;
    }
};

int main() {
    Solution ins;
    vector<vector<int>> mat = {{1,1,3,2,4,3,2},{1,1,3,2,4,3,2},{1,1,3,2,4,3,2}};
    auto threshold = 4;
    cout << ins.maxSideLength(mat, threshold) << endl;
    return 0;
}