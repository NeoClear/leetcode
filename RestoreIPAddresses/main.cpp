#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    map<pair<string, int>, vector<vector<int>>> map_;
    int len(int x) {
        if (x < 10)
            return 1;
        if (x < 100)
            return 2;
        if (x < 1000)
            return 3;
        return 0;
    }
    vector<vector<int>> solve(string s, int left) {
        if (s.size() > left * 3)
            return {};
        if (map_.count({s, left}))
            return map_[{s, left}];
        if (left == 1) {
            if (stoi(s) > 255 || s.size() != len(stoi(s)))
                return {};
            else
                return map_[{s, left}] = {{stoi(s)}};
        }
        vector<vector<int>> res;

        for (int i = 1; i < s.size() - left + 2; i++) {
            int cur = stoi(s.substr(0, i));
            auto ret = solve(s.substr(i), left - 1);
            if (cur > 255)
                continue;
            if (i != len(cur))
                continue;
            if (ret.empty())
                continue;
            for (auto& sol : ret) {
                sol.push_back(cur);
                res.push_back(sol);
            }
        }
        return map_[{s, left}] = res;
    }
    vector<string> restoreIpAddresses(string s) {
        if (s.length() > 12 || s.length() < 4)
            return {};
        auto res = solve(s, 4);
        vector<string> ret;
        for (const auto& line : res) {
            string cur;
            for (auto it = line.rbegin(); it != line.rend(); it++) {
                cur += to_string(*it);
                cur.push_back('.');
            }
            cur.pop_back();
            ret.push_back(cur);
        }
        return ret;
    }
};

int main()
{
    Solution ins;
    for (const auto& it : ins.restoreIpAddresses("010010"))
        cout<< it<< endl;
//    for (const auto& sol : ins.solve("0010", 2)) {
//        for (auto it = sol.rbegin(); it != sol.rend(); it++)
//            cout<< *it<< " ";
//        cout<< endl;
//    }
    return 0;
}
