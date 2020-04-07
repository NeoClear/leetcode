#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> height_;
    int calc(int l, int r) {
        int ans = 0;
        int level = min(height_[l], height_[r]);
        for (int i = l + 1; i < r; i++) {
            ans += level - height_[i];
        }
        return ans;
    }
    int trap(vector<int> height) {
        if (height.size() == 1) return 0;
        vector<int> climax;
        vector<int> left;
        vector<int> right;
        int N = height.size();
        int ll = 0;
        int ans = 0;
        left.push_back(0);
        for (int i = 1; i < N; i++) {
            if (height[i] >= height[ll]) {
                left.push_back(i);
                ll = i;
            }
        }
        int rr = N - 1;
        right.push_back(N - 1);
        for (int i = N - 2; i >= 0; i--) {
            if (height[i] >= height[rr]) {
                right.push_back(i);
                rr = i;
            }
        }
        while (!right.empty() && right.back() <= left.back())
            right.pop_back();
        climax = vector<int>(left.begin(), left.end());
        for (auto it = right.rbegin(); it != right.rend(); it++)
            climax.push_back(*it);
        int M = climax.size();
        height_.swap(height);
//        for (const auto& it : climax)
//            cout<< it<< endl;
        for (int i = 0; i < M - 1; i++)
            ans += calc(climax[i], climax[i + 1]);
        return ans;
    }
};

int main()
{
    Solution ins;
    cout<< ins.trap({0,1,0,2,1,0,1,3,2,1,2,1});
    return 0;
}
