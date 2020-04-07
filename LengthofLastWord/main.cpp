#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty()) return 0;
        int it = s.size() - 1;
        for (; it >= 0; it--)
            if (s[it] != ' ')
                break;
        if (it == -1)
            return 0;
        int len = 0;
        for (; it >= 0; it--) {
            if (s[it] == ' ')
                break;
            len++;
        }
        return len;
    }
};

int main()
{
    Solution ins;
    cout<< ins.lengthOfLastWord("Hello World")<< endl;
    return 0;
}
