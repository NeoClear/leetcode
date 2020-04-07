#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<string, vector<vector<string>>> map_;
    vector<vector<string>> dict;
    unordered_map<string, bool> cache;
    bool solve(string s) {
        if (s.empty())
            return true;
        if (cache.count(s))
            return cache[s];
        vector<vector<string>> ans;
        bool flag = false;
        for (const auto& it : dict[s.front() - 'a']) {
            if (it.size() <= s.size() && it == s.substr(0, it.size()))
                if (solve(s.substr(it.size()))) {
                    flag = true;
                    auto dest = map_[s.substr(it.size())];
                    for (auto& ele : dest) {
                        ele.push_back(it);
                        ans.push_back(ele);
                    }
                }
        }
        if (!flag)
            return cache[s] = false;
        map_[s] = ans;
        return cache[s] =  true;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        dict = vector<vector<string>>(26);
        for (const auto& it : wordDict)
            dict[it.front() - 'a'].push_back(it);
        map_[""] = {{}};
        solve(s);
        if (!map_.count(s))
            return {};
        for (auto& it : map_[s])
            reverse(it.begin(), it.end());
        vector<string> ans;
        for (auto& it : map_[s]) {
            string cur;
            for (auto& ele : it) {
                cur += ele;
                cur.push_back(' ');
            }
            if (!cur.empty())
                cur.pop_back();
            ans.push_back(cur);
        }
        return ans;
    }
};

int main()
{
    Solution ins;
    vector<string> dict = {
        "apple",
        "pen",
        "pine",
        "applepen",
        "pineapple"
    };
    for (const auto& it : ins.wordBreak("pineapplepenapple", dict))
        cout<< it<< endl;
    return 0;
}
