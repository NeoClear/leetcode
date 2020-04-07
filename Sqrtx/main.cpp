#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        long long des = (long long)x;
        long long l = 0, r = 1 << 16;
        long long mid;
        while (l < r) {
            mid = (l + r + 1) / 2;
            if (mid * mid <= des) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};

int main()
{
    Solution ins;
    for (int i = 0; i < 32; i++)
        cout<< i<< ", "<< ins.mySqrt(i)<< endl;
    return 0;
}
