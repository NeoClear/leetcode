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
    int romanToInt(string s) {
        int N = s.length();
        s.push_back('@');
        int ans = 0;
        int ptr = 0;
        while (ptr < N) {
            for (const auto& it : table_) {
                if (s.substr(ptr, it.first.size()) == it.first) {
                    ans += it.second;
                    ptr += it.first.size();
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
    cout<< ins.romanToInt("MCMXCIV")<< endl;
    return 0;
}
