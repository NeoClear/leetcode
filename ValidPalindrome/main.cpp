#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string meta;
        for (const auto& c : s)
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
                meta.push_back(isalpha(c) && c <= 'Z' ? c + 32 : c);
        cout<< meta<< endl;
        return meta == string(meta.rbegin(), meta.rend());
    }
};

int main()
{
    Solution ins;
    ins.isPalindrome("0P");
    return 0;
}
