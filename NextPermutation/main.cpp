#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int N;
    void solve(vector<int>& nums, int i) {
        int ppt;
        int mm = INT_MAX;
        for (int k = i + 1; k < N; k++)
            if (nums[k] > nums[i] && nums[k] < mm) {
                ppt = k;
                mm = nums[k];
            }
        swap(nums[i], nums[ppt]);
        sort(nums.begin() + i + 1, nums.end());
    }
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 1 || nums.empty())
            return;
        if (nums.size() == 2) {
            swap(nums[0], nums[1]);
            return;
        }
        N = nums.size();
        for (int i = N - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                solve(nums, i);
                return;
            }
        }
        nums = vector<int>(nums.rbegin(), nums.rend());
    }
};

int main()
{
    vector<int> in = {
        2, 3, 1
    };
    Solution ins;
    ins.nextPermutation(in);
    for (const auto& it : in)
        cout<< it<< endl;
    return 0;
}
