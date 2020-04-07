#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int cntx(string s) {
        int cnt = 0;
        for (const auto& c : s)
            if (c == 'x')
                cnt++;
        return cnt;
    }
    int minimumSwap(string s1, string s2) {
        if ((cntx(s1) + cntx(s2)) & 0x1)
            return -1;
        string ss1, ss2;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                ss1.push_back(s1[i]);
                ss2.push_back(s2[i]);
            }
        }
        return solve(ss1, ss2);
    }
    int diff(string s1, string s2) {
        int cnt = 0;
        for (int i = 0; i < s1.size(); i++)
            if (s1[i] != s2[i])
                cnt++;
        return cnt;
    }
    int solve(string s1, string s2) {
        int pairs = s1.size() / 2; // 3
        int dif = (abs(cntx(s1) - cntx(s2)) / 2) & 0x1; // 3
        return (pairs + dif) & 0x1 ? pairs + 1 : pairs;
    }
};

int main()
{
    Solution ins;
    cout << ins.minimumSwap("xy",
                            "yx")
         << endl;
    return 0;
}
