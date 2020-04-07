#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0;
        for (int i = 0; i < 32; i++) {
            if ((c >> i) & 0x1) {
                cnt += 1 - (((a >> i) & 0x1) | ((b >> i) & 0x1));
            } else {
                cnt += ((a >> i) & 0x1) + ((b >> i) & 0x1);
            }
            // cout << i << ", " << cnt << endl;
        }
        return cnt;
    }
};

int main() {
    Solution ins;
    cout << ins.minFlips(2, 6, 5) << endl;
}