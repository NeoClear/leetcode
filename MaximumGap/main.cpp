#include <bits/stdc++.h>

using namespace std;

struct Bucket {
    bool used = false;
    int maxi = INT_MIN;
    int mini = INT_MAX;
};

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2)
            return 0;
        int maxi = *max_element(nums.begin(), nums.end());
        int mini = *min_element(nums.begin(), nums.end());
        int bucketSize = max(1, (maxi - mini) / ((int)nums.size() - 1));
        int bucketNum = (maxi - mini) / bucketSize + 1;
        vector<Bucket> buckets = vector<Bucket>(bucketNum);
        for (const auto& n : nums) {
            int id = (n - mini) / bucketSize;
            buckets[id].used = true;
            buckets[id].maxi = max(buckets[id].maxi, n);
            buckets[id].mini = min(buckets[id].mini, n);
        }
        int pre = 0;
        int ans = 0;
        for (int i = 1; i < bucketNum; i++) {
            if (!buckets[i].used)
                continue;
            ans = max(ans, buckets[i].mini - buckets[pre].maxi);
            pre = i;
        }
        return ans;
    }
};

int main()
{
    return 0;
}
