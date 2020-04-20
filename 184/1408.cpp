#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for (const auto& it : words) {
            for (const auto& w : words) {
                if (w.find(it) != w.npos && w != it) {
                    ans.push_back(it);
                    break;
                }
            }
        }
        return ans;
    }
};
