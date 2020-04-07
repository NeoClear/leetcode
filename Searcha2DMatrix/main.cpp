#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int R, C;
    int createTag(int r, int c) {
        return r * C + c;
    }
    int getR(int tag) {
        return tag / C;
    }
    int getC(int tag) {
        return tag % C;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty())
            return false;
        R = matrix.size();
        C = matrix[0].size();
        int l = 0, r = R * C - 1;
        int mid;
        while (l <= r) {
            mid = (l + r) / 2;
            int val = matrix[getR(mid)][getC(mid)];
            if (val < target)
                l = mid + 1;
            else if (val > target)
                r = mid - 1;
            else
                return true;
        }
        return false;
    }
};

int main()
{
    Solution ins;
    vector<vector<int>> in = {
        {1, 1}
    };
    if (ins.searchMatrix(in, 2))
        cout<< "YES"<< endl;
    else
        cout<< "NO"<< endl;
    return 0;
}
