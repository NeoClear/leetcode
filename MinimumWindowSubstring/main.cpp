#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> count;
    vector<int> t_;
    bool contain() {
        for (int i = 0; i < 58; i++)
            if (count[i] < t_[i])
                return false;
        return true;
    }
    string minWindow(string s, string t) {
        count = vector<int>(58, 0);
        t_ = vector<int>(58, 0);
        for (const auto& c : t)
            t_[c - 'A']++;;
        int l = 0, r = 0;
        count[s.front() - 'A']++;
        pair<int, string> ans = {INT_MAX, ""};
        s.push_back('[');
        while (r < s.size() - 1) {
            cout<< l<< ", "<< r<< endl;
            int len = r - l + 1;
            if (contain()) {
                if (len < ans.first)
                    ans = {len, s.substr(l, len)};
                count[s[l] - 'A']--;
                l++;
            } else {
                r++;
                count[s[r] - 'A']++;
            }
        }
        return ans.second;
    }
};

int main()
{
    return 0;
}
