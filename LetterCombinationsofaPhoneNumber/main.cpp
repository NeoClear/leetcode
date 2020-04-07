#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> table = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.length() == 0) return {};
        if (digits.size() == 1) {
            for (const char& c : table[digits[0] - '0'])
                ans.push_back(string(1, c));
            return ans;
        }
        vector<string> ret = letterCombinations(digits.substr(1));
        vector<string> src;
        for (const char& c : table[digits[0] - '0'])
            src.push_back(string(1, c));
        for (const auto& p : src)
            for (const auto& suf : ret)
                ans.push_back(p + suf);
        return ans;
    }
};

int main()
{
    Solution ins;
    for (const auto& it : ins.letterCombinations("23"))
        cout<< it<< endl;
    return 0;
}
