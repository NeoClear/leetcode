#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int64_t digits(int64_t val) {
        int cnt = 0;
        while (val) {
            cnt++;
            val /= 10;
        }
        return cnt;
    }
    int64_t power(int64_t base, int64_t times) {
        int64_t ans = 1;
        while (times--)
            ans *= base;
        return ans;
    }
    int64_t left(int64_t val, int64_t id) {
        while (id--)
            val /= 10;
        return val;
    }
    int64_t right(int64_t val, int64_t id) {
        return val % power(10, id - 1);
    }
    int64_t cur(int64_t val, int64_t id) {
        while (--id)
            val /= 10;
        return val % 10;
    }
    int countDigitOne(int n) {
        if (n < 1)
            return 0;
        int64_t limits = digits(n);
        int64_t ans = 0;
        for (int64_t i = 1; i <= limits; i++) {
            ans += left(n, i) * power(10, i - 1);
            int64_t current = cur(n, i);
            if (current == 0)
                continue;
            else if (current > 1)
                ans += power(10, i - 1);
            else {
                ans += right(n, i) + 1;
            }
        }
        return static_cast<int>(ans);
    }
};

int main()
{
    Solution ins;
    cout<< ins.countDigitOne(13)<< endl;
    return 0;
}
