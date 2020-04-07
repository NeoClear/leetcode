#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        long long flag = 1;
        if (dividend < 0)
            flag = -flag;
        if (divisor < 0)
            flag = -flag;
        long long dividendd = abs((long long)dividend);
        long long divisord = abs((long long)divisor);
        vector<pair<long long, long long>> table;
        table.push_back({1, divisord});

        while (table.back().second + table.back().second <= dividendd) {
            table.push_back({table.back().first + table.back().first,
                            table.back().second + table.back().second});
        }
        long long ans = 0;
        long long res = 0;
        for (auto i = table.rbegin(); i != table.rend(); i++) {
            if (i->second + res <= dividendd) {
                ans += i->first;
                res += i->second;
            }
        }
        return ans * flag;
    }
};

int main()
{
    Solution ins;
    cout<< ins.divide(-2147483648, 1)<< endl;
    return 0;
}
