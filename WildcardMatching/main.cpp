#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
//        cout<< s<< ", "<< p<< endl;
        if (p.empty()) return s.empty();
        auto f = [](const string& pass) {
            for (const auto& it : pass)
                if (it != '*')
                    return false;
            return true;
        };
        if (s.empty()) return p.empty() || f(p);
        if (p.back() != '?' && p.back() != '*' && p.back() != s.back())
            return false;
        bool firstMatch = p[0] == '?' || p[0] == s[0];
        if (p[0] == '*') {
            return isMatch(s, p.substr(1)) || isMatch(s.substr(1), p);
        } else {
            return firstMatch && isMatch(s.substr(1), p.substr(1));
        }
    }
};

int main()
{
    Solution ins;
    if (ins.isMatch("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba",
                    "a*******b"))
        cout<< "YES"<< endl;
    else
        cout<< "NO"<< endl;
    return 0;
}
