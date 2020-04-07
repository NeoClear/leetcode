#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        for (unsigned long long i = 0; i < nums.size(); i++) {
            for (unsigned long long j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    ret.push_back(static_cast<int>(i));
                    ret.push_back(static_cast<int>(j));
                    return ret;
                }
            }
        }
        return ret;
    }
};

int main()
{
    vector<int> test = {5, 2, 3, 7};
    class Solution ins;
    vector<int> res = ins.twoSum(test, 9);
    for (unsigned long long i = 0; i < res.size(); i++)
        cout<< res[i]<< endl;
    return 0;
}
