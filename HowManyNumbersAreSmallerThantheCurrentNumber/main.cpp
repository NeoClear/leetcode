#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> rank(nums.begin(), nums.end());
        sort(rank.begin(), rank.end());
        unordered_map<int, int> mm;
        for (int i = 0; i < rank.size(); i++) {
            if (!mm.count(rank[i]))
                mm[rank[i]] = i;
        }
        vector<int> ans;
        for (const auto& it : nums) {
            ans.push_back(mm[it]);
        }
        return ans;
    }
};

int main() {
    Solution ins;
    vector<int> in{
        7,7,7,7
    };
    for (const auto& it : ins.smallerNumbersThanCurrent(in))
        cout << it << " ";
    return 0;
}