#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & -n) == n;
    }
};

int main()
{
    return 0;
}
