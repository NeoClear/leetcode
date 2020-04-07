#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c, char aa = 'a', char bb = 'b', char cc = 'c') {
        if (a < b)
            return longestDiverseString(b, a, c, bb, aa, cc);
        if (b < c)
            return longestDiverseString(a, c, b, aa, cc, bb);
        if (b == 0)
            return string(min(2, a), aa);
        int used_a = min(2, a);
        int used_b = a - used_a >= b ? 1 : 0;
        return string(used_a, aa) +
               string(used_b, bb) +
               longestDiverseString(a - used_a, b - used_b, c, aa, bb, cc);
    }
};

int main() {
    Solution ins;
    cout << ins.longestDiverseString(2, 2, 1) << endl;
    return 0;
}
