#include <bits/stdc++.h>

using namespace std;

class fwt {
private:
    vector<int> sums_;
    static inline int lowbit(int x) { return x & (-x); }
public:
    fwt(int n): sums_(n + 1, 0) {}
    void update(int i, int delta) {
        while (i < sums_.size()) {
            sums_[i] += delta;
            i += lowbit(i);
        }
    }
    int query(int i) const {
        int ans = 0;
        while (i > 0) {
            ans += sums_[i];
            i -= lowbit(i);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        set<int> set_ = set<int>(nums.begin(), nums.end());
        vector<int> vec_ = vector<int>(set_.begin(), set_.end());
        unordered_map<int, int> map_;
        for (int i = 0; i < vec_.size(); i++) map_[vec_[i]] = i + 1;
        fwt fwt_(nums.size());
        vector<int> ans = vector<int>(nums.size(), 0);
        for (int i = nums.size() - 1; i >= 0; i--) {
            fwt_.update(map_[nums[i]], 1);
            ans[i] = fwt_.query(map_[nums[i]] - 1);
        }
        return ans;
    }
};

int main()
{
    Solution ins;
    vector<int> in = {
        2, 0, 1
    };
    for (const auto& it : ins.countSmaller(in)) cout<< it<< endl;
    return 0;
}
