#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        s.push_back(' ');
        vector<string> ans;
        string cur;
        for (const auto& it : s) {
            if (it == ' ') {
                if (!cur.empty()) {
                    ans.push_back(cur);
                    cur.clear();
                }
            } else
                cur.push_back(it);
        }
        string ret;
        for (auto it = ans.rbegin(); it != ans.rend(); it++) {
            ret += *it;
            ret.push_back(' ');
        }
        if (!ret.empty())
            ret.pop_back();
        return ret;
    }
};

int main()
{
    return 0;
}
