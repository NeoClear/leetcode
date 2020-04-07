#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int N = nums.size();
        vector<int> cache;
        for (int i = 0; i < N; i++) {
            cache.insert(cache.begin() + index[i], {nums[i]});
        }
        return cache;
    }
};
