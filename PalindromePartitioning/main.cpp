#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        return s == string(s.rbegin(), s.rend());
    }
    unordered_map<string, vector<vector<string>>> cache;
    vector<vector<string>>& solve(string s) {
        if (cache.count(s))
            return cache[s];
        if (s.empty()) {
            return cache[s] = {{}};
        }
        vector<vector<string>> ret;
        for (int i = 1; i <= s.size(); i++) {
            string cur = s.substr(0, i);
            if (isPalindrome(cur)) {
                auto res = solve(s.substr(i));
                for (auto& it : res)
                    it.push_back(cur);
                for (const auto& it : res)
                    ret.push_back(it);
            }
        }
        return cache[s] = ret;
    }
    vector<vector<string>> partition(string s) {
        if (s.empty())
            return {};
        auto ans = solve(s);
        for (auto& it : ans)
            reverse(it.begin(), it.end());
        return ans;
    }
};

int main()
{
    Solution ins;
    for (const auto& sol : ins.partition("bcc")) {
        for (const auto& ele : sol)
            cout<< ele<< " ";
        cout<< endl;
    }
    return 0;
}
