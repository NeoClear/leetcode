#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> slide;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            int cur = nums[i];
            slide.insert(cur);
            if (slide.size() > k)
                slide.erase(slide.find(nums[i - k]));
            if (slide.size() == k)
                ans.push_back(*slide.rbegin());
        }
        return ans;
    }
};

int main()
{
    return 0;
}
