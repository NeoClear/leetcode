#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> count = vector<int>(3, 0);
        for (const auto& it : nums)
            count[it]++;
        int id = 0;
        for (int i = 0; i <= 2; i++) {
            for (int j = 0; j < count[i]; j++, id++) {
                nums[id] = i;
            }
        }
    }
};

int main()
{
    return 0;
}
