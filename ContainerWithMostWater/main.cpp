#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int N;
    int maxArea(vector<int>& height) {
        N = height.size();
        int ans = 0;

        int l = 0;
        int r = N - 1;
        while (l < r) {
            ans = max(ans, (r - l) * min(height[l], height[r]));
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}
