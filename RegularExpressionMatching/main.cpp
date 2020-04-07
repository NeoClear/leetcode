#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
//        cout<< s<< ", "<< p<< endl;
        if (p.empty()) return s.empty();
        bool firstMatch = s.empty() ? false : p[0] == '.' || s[0] == p[0];
        if (p.size() >= 2 && p[1] == '*') {
            if (firstMatch) {
                return isMatch(s, p.substr(2)) ||
                        isMatch(s.substr(1), p);
            } else {
                return isMatch(s, p.substr(2));
            }
        } else {
            if (firstMatch) {
                return isMatch(s.substr(1), p.substr(1));
            } else
                return false;
        }
    }
};

int main()
{
    Solution ins;
    if (ins.isMatch("aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*c"))
        cout<< "YES"<< endl;
    else
        cout<< "NO"<< endl;
    return 0;
}
