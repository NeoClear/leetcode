#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> solve(int l, int r) {
        vector<string> ret;
        if (l + r == 1)
            return {")"};
        if (l) {
            for (const auto& suf : solve(l - 1, r))
                ret.push_back("(" + suf);
        }
        if (r > l) {
            for (const auto& suf : solve(l, r - 1))
                ret.push_back(")" + suf);
        }
        return ret;
    }
    vector<string> generateParenthesis(int n) {
        return solve(n, n);
    }
};

int main()
{
    return 0;
}
