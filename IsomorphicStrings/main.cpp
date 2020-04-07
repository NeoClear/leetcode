#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> convert(string s) {
        int id = 0;
        unordered_map<char, int> map_;
        vector<int> ans;
        for (const auto& c : s) {
            if (!map_.count(c))
                map_[c] = id++;
            ans.push_back(map_[c]);
        }
        return ans;
    }
    bool isIsomorphic(string s, string t) {
        return convert(s) == convert(t);
    }
};

int main()
{
    return 0;
}
