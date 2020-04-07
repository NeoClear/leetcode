#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
//    unordered_map<int64_t, vector<vector<int>>> cache;
//    int64_t tag(int a, int b) {
//        return (static_cast<int64_t>(a) << 32) | static_cast<int64_t>(b);
//    }
    vector<vector<int>> ans;
    vector<int> cur;
    void solve(int limit, int left, int target) {
        if (limit > 9 || target < 0)
            return;
        if (left == 0) {
            if (target == 0)
                ans.push_back(cur);
            return;
        }
        for (int i = limit + 1; i <= 9; i++) {
            cur.push_back(i);
            solve(i, left - 1, target - i);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        if (k == 0)
            return {};
        solve(0, k, n);
        return ans;
    }
};

int main()
{
    Solution ins;
    for (const auto& sol : ins.combinationSum3(3, 9)) {
        for (const auto& ele : sol)
            cout<< ele<< " ";
        cout<< endl;
    }
    return 0;
}
