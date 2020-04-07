#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_set<int> visited;
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        k++;
        if (nums.size() < k) {
            for (int i = 0; i < nums.size(); i++) {
                if (visited.count(nums[i]))
                    return true;
                visited.insert(nums[i]);
            }
            return false;
        }
        int l = 0, r = k - 1;
        for (int i = 0; i < k; i++) {
            if (visited.count(nums[i]))
                return true;
            visited.insert(nums[i]);
        }
        for (r = k; r < nums.size(); r++) {
            l = r - k;
            visited.erase(nums[l]);
            if (visited.count(nums[r]))
                return true;
            visited.insert(nums[r]);
        }
        return false;
    }
};

int main()
{
    return 0;
}
