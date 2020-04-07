#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    map<pair<string, string>, bool> map_;
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.empty() && s2.empty())
            return s3.empty();
        if (map_.count({s1, s2}))
            return map_[{s1, s2}];
        if (s1.empty())
            return map_[{s1, s2}] = s2.front() == s3.front() && isInterleave(s1, s2.substr(1), s3.substr(1));
        if (s2.empty())
            return map_[{s1, s2}] = s1.front() == s3.front() && isInterleave(s1.substr(1), s2, s3.substr(1));
        bool ret = false;
        if (s1.front() == s3.front())
            ret |= isInterleave(s1.substr(1), s2, s3.substr(1));
        if (s2.front() == s3.front())
            ret |= isInterleave(s1, s2.substr(1), s3.substr(1));
        return map_[{s1, s2}] = ret;
    }
};

int main()
{
    Solution ins;
    if (ins.isInterleave("", "", "c"))
        cout<< "YES"<< endl;
    else
        cout<< "NO"<< endl;
    return 0;
}
