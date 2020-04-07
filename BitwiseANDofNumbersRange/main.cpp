#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ans = 0xffffffff;
        for (int i = m; i <= n; i++) {
            ans &= i;
            if (ans == 0)
                return 0;
            if (i == INT_MAX)
                break;
        }
        return ans;
    }
};

int main()
{
    return 0;
}
