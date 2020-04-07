#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<vector<int>> pos_;
public:
    string shortestCommonSupersequence(string str1, string str2) {
        pos_.clear();
        int len1 = str1.size();
        int len2 = str2.size();
        pos_ = vector<vector<int>>(len1 + 1, vector<int>(len2 + 1, 0));
        for (int l1 = 1; l1 <= len1; l1++) {
            for (int l2 = 1; l2 <= len2; l2++) {
                if (str1[l1 - 1] == str2[l2 - 1])
                    pos_[l1][l2] = pos_[l1 - 1][l2 - 1] + 1;
                else
                    pos_[l1][l2] = max(pos_[l1 - 1][l2], pos_[l1][l2 - 1]);
            }
        }
        string ans;
        ans.clear();
        for (int l1 = len1, l2 = len2; !(l1 == 0 && l2 == 0);) {
            if (l1 == 0) {
                ans.push_back(str2[l2 - 1]);
                l2--;
            } else if (l2 == 0) {
                ans.push_back(str1[l1 - 1]);
                l1--;
            } else if (str1[l1 - 1] == str2[l2 - 1]) {
                ans.push_back(str1[l1 - 1]);
                l1--;
                l2--;
            } else if (pos_[l1 - 1][l2] == pos_[l1][l2]) {
                ans.push_back(str1[l1 - 1]);
                l1--;
            } else if (pos_[l1][l2 - 1] == pos_[l1][l2]) {
                ans.push_back(str2[l2 - 1]);
                l2--;
            }
        }
        string anses;
        anses.clear();
        for (int i = ans.size() - 1; i >= 0; i--)
            anses.push_back(ans[i]);
        return anses;
    }
};

int main()
{
    Solution ins;
    cout<< ins.shortestCommonSupersequence("bcacaaab", "bbabaccc")<< endl;
    return 0;
}
