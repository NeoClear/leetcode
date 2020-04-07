#include <iostream>

using namespace std;

static int prefix[1001];

class Solution {
private:
    int range = 0;
public:
    int expand(string s, int start, int end) {
        int i = start, j = end;
        while (i >= 0 && j <= s.length() - 1) {
            if (s[i] != s[j])
                break;
            i--;
            j++;
        }
        return start - i - 1;
    }
    string longestPalindrome(string s) {
        string ans;
        if (s.length() == 0)
            return ans;
        else if (s.length() == 1)
            return s;
        for (int i = 0; i < s.length() - 1; i++) {
            if (expand(s, i, i) * 2 + 1 > range) {
                range = expand(s, i, i) * 2 + 1;
                ans = s.substr(i - expand(s, i, i), range);
            }
            if (expand(s, i, i + 1) * 2 + 2 > range) {
                range = expand(s, i, i + 1) * 2 + 2;
                ans = s.substr(i - expand(s, i, i + 1), range);
            }
        }
        return ans;
    }
};

int main()
{
    Solution ins;
    cout<< ins.longestPalindrome("bb")<< endl;
    return 0;
}
