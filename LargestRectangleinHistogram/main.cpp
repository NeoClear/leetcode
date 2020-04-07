#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty())
            return 0;
        int ans = 0;
        heights.push_back(0);
        vector<int> stack;
        for (int i = 0; i < heights.size(); i++) {
            if (stack.empty() || heights[i] > heights[stack.back()])
                stack.push_back(i);
            else {
                while (!stack.empty() && heights[stack.back()] >= heights[i]) {
                    int id = stack.back();
                    stack.pop_back();
                    int h = heights[id];
                    int w = stack.empty() ? i : i - (stack.back() + 1);
                    ans = max(ans, h * w);
                }
                stack.push_back(i);
            }
        }
        return ans;
    }
};

int main()
{
    Solution ins;
    vector<int> in = {
        2, 1, 5, 6, 2, 3
    };
    cout<< ins.largestRectangleArea(in)<< endl;
    return 0;
}
