#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> height;
    int solve(vector<int>& base) {
        vector<int> stack;
        base.push_back(0);
        int ans = 0;
        for (int i = 0; i < base.size(); i++) {
            if (stack.empty() || base[stack.back()] < base[i])
                stack.push_back(i);
            else {
                while (!stack.empty() && base[stack.back()] >= base[i]) {
                    int id = stack.back();
                    stack.pop_back();
                    int h = base[id];
                    int w = stack.empty() ? i : i - (stack.back() + 1);
                    ans = max(ans, h * w);
                }
                stack.push_back(i);
            }
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;
        height = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[0].size(); j++)
                height[i][j] = matrix[i][j] - '0';

        for (int i = 1; i < height.size(); i++) {
            for (int j = 0; j < height[0].size(); j++) {
                if (height[i][j] == 1)
                    height[i][j] += height[i - 1][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < height.size(); i++)
            ans = max(ans, solve(height[i]));
        return ans;
    }
};

int main()
{
    return 0;
}
