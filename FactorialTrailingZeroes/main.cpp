#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int64_t ans = 0;
        for (int64_t base = 5; base <= (int64_t)n; base *= 5)
            for (int64_t i = base; i <= (int64_t)n; i += base)
                ans++;
        return ans;
    }
};

int main()
{
    return 0;
}
