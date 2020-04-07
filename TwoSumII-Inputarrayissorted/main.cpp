#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right;
        for (right = 1; right < numbers.size() - 1; right++)
            if (numbers[right] + numbers.front() >= target)
                break;
        while (left < right) {
            int sums = numbers[left] + numbers[right];
            if (sums < target)
                left++;
            else if (sums > target)
                right--;
            else
                return {left + 1, right + 1};
        }
        return {-1, -1};
    }
};

int main()
{
    Solution ins;
    vector<int> in = {
        3, 24, 50, 79, 88, 150, 345
    };
    ins.twoSum(in, 200);
    return 0;
}
