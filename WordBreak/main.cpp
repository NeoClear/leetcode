#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> meta;
    unordered_map<string, bool> cache;
    bool solve(string s, vector<string>& wordDict) {
        if (s.empty())
            return true;
        if (cache.count(s))
            return cache[s];
        for (const auto& it : meta[s.front() - 'a'])
            if (it.size() <= s.size() && s.substr(0, it.size()) == it)
                if (solve(s.substr(it.size()), wordDict))
                    return cache[s] = true;
        return cache[s] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        meta = vector<vector<string>>(26);
        for (const auto& it : wordDict)
            meta[it.front() - 'a'].push_back(it);
        return solve(s, wordDict);
    }
};

int main()
{
    Solution ins;
    vector<string> dict = {
        "cats",
        "dog",
        "sand",
        "and",
        "cat"
    };
    if (ins.wordBreak("catsandog", dict))
        cout<< "YES"<< endl;
    else
        cout<< "NO"<< endl;
    return 0;
}
