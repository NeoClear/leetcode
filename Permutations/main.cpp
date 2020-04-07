#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> endGame;
    vector<vector<int>> ans_;
    void solve(vector<int>& nums) {
        int id;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                id = i;
                break;
            }
        }
        int sw = -1;
        int v = INT_MAX;
        for (int i = id + 1; i < nums.size(); i++) {
            if (nums[i] > nums[id] && nums[i] < v) {
                v = nums[i];
                sw = i;
            }
        }
        swap(nums[id], nums[sw]);
        sort(nums.begin() + id + 1, nums.end());
    }
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        endGame = vector<int>(nums.rbegin(), nums.rend());
        ans_.push_back(nums);
        while (nums != endGame) {
            solve(nums);
            ans_.push_back(nums);
        }
        return ans_;
    }
};

int main()
{
    Solution ins;
    vector<int> in = {
        1, 1, 3
    };
    for (const auto& pos : ins.permute(in)) {
        for (const auto& ele : pos)
            cout<< ele<< " ";
        cout<< endl;
    }
    return 0;
}
