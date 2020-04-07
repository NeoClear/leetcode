#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;
    int K, N;
    void solve() {
        if (cur.size() == K) {
            ans.push_back(cur);
            return;
        }
        int start = cur.empty() ? 1 : cur.back() + 1;
        int end = N - (K - cur.size()) + 1;
        for (int i = start; i <= end; i++) {
            cur.push_back(i);
            solve();
            cur.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        N = n;
        K = k;
        solve();
        return ans;
    }
};
int main()
{
    Solution ins;
    for (const auto& solution : ins.combine(4, 2)) {
        for (const auto& ele : solution)
            cout<< ele<< " ";
        cout<< endl;
    }
    return 0;
}
