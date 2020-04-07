#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<pair<string, int>> table_ = {
        {"M", 1000},
        {"CM", 900},
        {"D", 500},
        {"CD", 400},
        {"C", 100},
        {"XC", 90},
        {"L", 50},
        {"XL", 40},
        {"X", 10},
        {"IX", 9},
        {"V", 5},
        {"IV", 4},
        {"I", 1}
    };
    string intToRoman(int num) {
        string ans;
        while (num) {
            for (const auto& it : table_) {
                if (num >= it.second) {
                    num -= it.second;
                    ans += it.first;
                    break;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution ins;
    cout<< ins.intToRoman(1994)<< endl;
    return 0;
}
