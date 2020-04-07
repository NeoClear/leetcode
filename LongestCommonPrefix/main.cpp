#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> strs) {
        if (strs.size() == 0) return "";
        if (strs.size() == 1) return strs[0];
        string prefix = strs[0];
        for (const string it : strs) {
            int i;
            for (i = min(it.size(), prefix.size()); i >= 0 && prefix.substr(0, i) != it.substr(0, i); i--) {
            }
            prefix = prefix.substr(0, i);
        }
        return prefix;
    }
};

int main()
{
    Solution ins;
    cout<< ins.longestCommonPrefix({"dog", "flow", "flight"})<< endl;
    return 0;
}
