#include <bits/stdc++.h>
#include <map>
using namespace std;

static int sufix[0xffffff];

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const char *meta = s.c_str();
        int siz = static_cast<int>(s.length());
        sufix[0] = 1;
        for (int i = 1; i < siz; i++) {
            char cur = meta[i];
            bool flag = true;
            for (int j = i - 1; j > i - sufix[i - 1] - 1; j--) {
                if (meta[j] == cur)
                    flag = false;
            }
            if (flag) {
                sufix[i] = sufix[i - 1] + 1;
            } else {
                map<char, int> ins;
                for (int k = i; k >= 0; k--) {
                    map<char, int>::iterator iter;
                    iter = ins.find(meta[k]);
                    if (iter != ins.end()) {
                        sufix[i] = i - k;
                        break;
                    } else {
                        ins[meta[k]] = 1;
                    }

                }
            }
        }
        int ans = 0;
        for (int i = 0; i < siz; i++) {
//            cout<< sufix[i]<< endl;
            ans = ans > sufix[i] ? ans : sufix[i];
        }
        return ans;
    }
};

int main()
{
    Solution ins;
    cout<< ins.lengthOfLongestSubstring("dvdf")<< endl;
    return 0;
}
