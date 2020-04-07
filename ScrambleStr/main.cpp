#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef unsigned long long u64;

typedef struct {
    bool fit;
    bool checked;
}pdd;

pdd cac[32][32][32];

class Solution {
private:
    const char *str1, *str2;
public:
    bool isScr(u64 b1, u64 s1, u64 b2)
        {
            if (s1 == 1) {
                if (str1[b1] == str2[b2])
                    return true;
                return false;
            }

            for (u64 vol = 1; vol < s1; vol++) {
                u64 res = s1 - vol;
                if (!cac[b1][b2][vol].checked) {
                    cac[b1][b2][vol].checked = true;
                    cac[b1][b2][vol].fit = isScr(b1, vol, b2);
                }
                if (!cac[b1 + vol][b2 + vol][res].checked) {
                    cac[b1 + vol][b2 + vol][res].checked = true;
                    cac[b1 + vol][b2 + vol][res].fit = isScr(b1 + vol, res, b2 + vol);
                }
                if (cac[b1][b2][vol].fit && cac[b1 + vol][b2 + vol][res].fit)
                    return true;
                if (!cac[b1][b2 + res][vol].checked) {
                    cac[b1][b2 + res][vol].checked = true;
                    cac[b1][b2 + res][vol].fit = isScr(b1, vol, b2 + res);
                }
                if (!cac[b1 + vol][b2][res].checked) {
                    cac[b1 + vol][b2][res].checked = true;
                    cac[b1 + vol][b2][res].fit = isScr(b1 + vol, res, b2);
                }
                if (cac[b1][b2 + res][vol].fit && cac[b1 + vol][b2][res].fit)
                    return true;
            }
            return false;
        }
    bool isScramble(string s1, string s2) {
        memset(cac, 0, sizeof(cac));
        str1 = s1.c_str();
        str2 = s2.c_str();
        return isScr(0, s1.size(), 0);
    }
};

int main()
{
    Solution ins;
    if (ins.isScramble("abcde",
                       "caebd"))
        cout<< "True"<< endl;
    else
        cout<< "False"<< endl;
    return 0;
}
