#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while (n) {
            if (n & 0x1)
                cnt++;
            n >>= 1;
        }
        return cnt;
    }
};

int main()
{
    return 0;
}
