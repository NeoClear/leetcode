#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string generateTheString(int n) {
        if (n & 0b1)
            return string(n, 'x');
        return string(n - 1, 'x') + "y";
    }
};

int main() {
    Solution ins;
    cout << ins.generateTheString(1) << endl;
    return 0;
}