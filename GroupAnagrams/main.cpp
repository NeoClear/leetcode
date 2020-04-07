#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    map<vector<int>, vector<string>> map_;
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        for (const auto& word : strs) {
            vector<int> sig = vector<int>(26, 0);
            for (const auto& c : word)
                sig[c - 'a']++;
            map_[sig].push_back(word);
        }
        vector<vector<string>> ans;
        for (const auto& group : map_) {
            vector<string> g;
            for (const auto& it : group.second) {
                g.push_back(it);
            }
            ans.push_back(g);
        }
        return ans;
    }
};

int main()
{
    vector<string> in = {
        "eat", "tea", "tan", "ate", "nat", "bat"
    };
    Solution ins;
    for (const auto& g : ins.groupAnagrams(in)) {
        for (const auto& ele : g)
            cout<< ele<< " ";
        cout<< endl;
    }
    return 0;
}
