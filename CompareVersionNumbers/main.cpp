#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> trans(string s) {
        s.push_back('.');
        vector<int> ret;
        string cur;
        for (const auto& c : s) {
            if (c == '.') {
                ret.push_back(stoi(cur));
                cur.clear();
                continue;
            }
            cur.push_back(c);
        }
        return ret;
    }
    int compareVersion(string version1, string version2) {
        auto v1 = trans(version1);
        auto v2 = trans(version2);
        auto& ref = v1.size() < v2.size() ? v1 : v2;
        auto& reff = v1.size() < v2.size() ? v2 : v1;
        while (ref.size() < reff.size())
            ref.push_back(0);
        for (int i = 0; i < v1.size() && i < v2.size(); i++) {
            if (v1[i] < v2[i])
                return -1;
            else if (v1[i] > v2[i])
                return 1;
        }
        return 0;
    }
};

int main()
{
    Solution ins;
    cout<< ins.compareVersion("1", "0")<< endl;
    return 0;
}
