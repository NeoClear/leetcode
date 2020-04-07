#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        auto count = vector<pair<int, int>>(s.size(), {0, 0});
        int ans = 0;
        for (uint64_t i = 0; i < s.size(); i++) {
            for (uint64_t j = 0; j <= i; j++) {
                if (count[j].first >= 0) {
                    count[j].first += (s[i] == '(' ? 1 : -1);
                    count[j].second++;
                    if (count[j].first == 0)
                        ans = max(ans, count[j].second);
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution ins;
    cout<< ins.longestValidParentheses(")(((((()())()()))()(()))(")<< endl;
    return 0;
}
