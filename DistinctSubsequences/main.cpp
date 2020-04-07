#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    map<pair<string, string>, int> map_;
    int numDistinct(string s, string t) {
        if (t.empty())
            return 1;
        if (s.size() == t.size())
            return s == t;
        if (s.size() < t.size())
            return 0;
        if (map_.count({s, t}))
            return map_[{s, t}];
        int id;
        for (id = 0; id < s.size(); id++)
            if (s[id] == t.front())
                break;
        if (id == s.size())
            return 0;
        int ans = numDistinct(s.substr(id + 1), t);
        ans += numDistinct(s.substr(id + 1), t.substr(1));
        return map_[{s, t}] = ans;
    }
};

int main()
{
    Solution ins;
    cout<< ins.numDistinct("rabbbit", "rabbit")<< endl;
    return 0;
}
