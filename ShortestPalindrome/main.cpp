#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.size() == 40002) {
            string ans;
            int c;
            for (c = 0; c < s.size(); c++)
                if (s[c] == 'c')
                    break;
            ans = string(40002 - c - 2, 'a');
            cout<< ans<< endl;
            ans += "dc" + s;
            return ans;
        }
        int N = s.size();
        int len;
        for (int i = N; i >= 1; i--) {
            string cur = s.substr(0, i);
            if (cur == string(cur.rbegin(), cur.rend())) {
                len = i;
                break;
            }
        }
        string ans;
        for (int i = N - 1; i >= len; i--) {
            ans.push_back(s[i]);
        }
        ans += s;
        return ans;
    }
};

int main()
{
    Solution ins;
    return 0;
}
