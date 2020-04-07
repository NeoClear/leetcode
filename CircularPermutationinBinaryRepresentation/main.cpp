#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        if (n == 0)
            return {};
        vector<int> ans = {0, 1};
        for (int offset = 1; offset < n; offset++) {
            for (int it = ans.size() - 1; it >= 0; it--) {
                ans.push_back(ans[it] | (1 << offset));
            }
        }
        vector<int> ret;
        for (auto it = ans.begin(); it != ans.end(); it++) {
            if (*it == start) {
                ret = vector<int>(it, ans.end());
                for (auto i = ans.begin(); i != it; i++)
                    ret.push_back(*i);
            }
        }
        return ret;
    }
};

int main()
{
    Solution ins;
    for (const auto& it : ins.circularPermutation(3, 2))
        cout << it << " ";
    return 0;
}
