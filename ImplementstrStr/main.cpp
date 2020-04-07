#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        if (needle.length() > haystack.length()) return -1;
        uint64_t N = haystack.length();
        uint64_t M = needle.length();
        bool flag;
        for (uint64_t i = 0; i < N - M + 1; i++) {
            flag = true;
            for (uint64_t j = 0; j < M; j++) {
                if (haystack[i + j] != needle[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                return static_cast<int>(i);
        }
        return -1;
    }
};

int main()
{
    Solution ins;
    cout<< ins.strStr("aaaaa", "bba")<< endl;
    return 0;
}
