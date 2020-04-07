#include <iostream>

using namespace std;

#define MAX 0x7fffffff

class Solution {
private:
    int flag = 1;
    int bitm[32];
    int digits;
public:
    long long reverse(int x) {
        digits = 0;
        if (x == -2147483648)
            return 0;
        if (x < 0) {
            x = 0 - x;
            flag = -1;
        }
        while (x > 0) {
            bitm[digits] = x % 10;
            x = (x - bitm[digits]) / 10;
            digits++;
        }
        int ans = 0;
        for (int i = 0; i < digits; i++) {
            if (ans > (MAX - bitm[i]) / 10) {
                return 0;
            }
            ans = ans * 10 + bitm[i];
        }
        return ans * flag;
    }
};

int main()
{
    Solution ins;
    cout<< ins.reverse(-2147483412)<< endl;
    return 0;
}
