#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int cton(char c) {
        return c - 'A' + 1;
    }
    int titleToNumber(string s) {
        int64_t ans = 0;
        int64_t base = 1;
        for (auto it = s.rbegin(); it != s.rend(); it++) {
            cout<< *it<< endl;
            ans += (cton(*it)) * base;
            base *= 26;
        }
        return static_cast<int>(ans);
    }
};

int main()
{
    Solution ins;
    cout<< ins.titleToNumber("A");
    return 0;
}
