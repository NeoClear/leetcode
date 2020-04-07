#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;
        if (matrix.front().front() > target || matrix.back().back() < target)
            return false;
        int R = matrix.size(), C = matrix[0].size();
        int id = C - 1;
        for (int i = 0; i < R; i++) {
            while (id >= 0 && matrix[i][id] > target)
                id--;
            if (id == -1)
                return false;
            if (matrix[i][id] == target)
                return true;
        }
        return false;
    }
};

int main()
{
    return 0;
}
