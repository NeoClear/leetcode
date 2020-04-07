#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> split(string s) {
        string t;
        vector<string> ret;
        for (const auto& c : s) {
            if (c == '/') {
                ret.push_back(t);
                t.clear();
                continue;
            }
            t.push_back(c);
        }
        ret.push_back(t);
        return ret;
    }
    string simplifyPath(string path) {
        string ret;
        for (const auto& c : path) {
            if (!ret.empty() && ret.back() == '/' && c == '/')
                continue;
            ret.push_back(c);
        }
        if (ret.back() == '/' && ret.size() != 1)
            ret.pop_back();
        if (ret.size() == 1)
            return "/";
        auto vec = split(ret.substr(1));
        vector<string> cons = {""};
        for (const auto& level : vec) {
            if (level == ".")
                continue;
            if (level == "..") {
                if (cons.size() != 1)
                    cons.pop_back();
                continue;
            }
            cons.push_back(level);
        }
        string res;
        if (cons.size() == 1)
            return "/";
        for (const auto& p : cons) {
            if (p != "")
                res.push_back('/');
            res += p;
        }
        return res;
    }
};

int main()
{
    Solution ins;
    cout<< ins.simplifyPath("/");
    return 0;
}
