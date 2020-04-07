#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int> nums) {
        sort(nums.begin(), nums.end(), [](const int& a, const int& b){
            return a > b;
        });
        while (!nums.empty() && nums.back() <= 0)
            nums.pop_back();
        sort(nums.begin(), nums.end());
        if (nums.empty()) return 1;
        if (nums.size() == 1) {
            if (nums.front() == 1) return 2;
            else return 1;
        }
        if (nums[0] != 1) return 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] < nums[i] - 1)
                return nums[i - 1] + 1;
        }
        return nums.back() + 1;
    }
};

int main()
{
    Solution ins;
    cout<< ins.firstMissingPositive({7, 8, 9, 10, 11, 12})<< endl;
    return 0;
}
