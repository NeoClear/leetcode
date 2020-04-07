#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int64_t gcd(int64_t a, int64_t b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
            return "0";
        vector<int64_t> ans;
        unordered_set<int64_t> visited;
        int64_t f = (numerator < 0 ? -1 : 1) * (denominator < 0 ? -1 : 1);
        int64_t x = abs(static_cast<int64_t>(numerator));
        int64_t y = abs(static_cast<int64_t>(denominator));
        auto divi = gcd(x, y);
        x /= divi;
        y /= divi;
        while (x != 0) {
            if (visited.count(x))
                break;
            visited.insert(x);
            ans.push_back(x);
            x = (x % y) * 10;
        }
        string ret;
        if (f == -1)
            ret.push_back('-');
        if (ans.size() == 1) {
            ret += to_string(ans.front() / y);
            return ret;
        }
        if (x == 0) {
            ret += to_string(ans.front() / y);
            ret.push_back('.');
            for (uint64_t i = 1; i < ans.size(); i++)
                ret += to_string(ans[i] / y);
            return ret;
        } else {
            ret += to_string(ans.front() / y);
            ret.push_back('.');
            for (uint64_t i = 1; i < ans.size(); i++) {
                if (ans[i] == x)
                    ret.push_back('(');
                ret += to_string(ans[i] / y);
            }
            ret.push_back(')');
            return ret;
        }
    }
};

int main()
{
    Solution ins;
    cout<< ins.fractionToDecimal(9, 7)<< endl;
    return 0;
}
