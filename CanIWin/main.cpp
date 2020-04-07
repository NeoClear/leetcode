#include <bits/stdc++.h>
#include <stdlib.h>
#include <string>

using namespace std;

char cac_[1 << 21];

class Solution {
private:
    int win(int M, int T, unsigned long long state)
    {
        if (T <= 0)
            return cac_[state] = -1;
        if (cac_[state])
            return cac_[state];
        for (int i = 0; i < M; i++) {
            if (state & (1 << i))
                continue;
            if (cac_[state | (1 << i)] == 0)
                win(M, T - i - 1, state | (1 << i));
            if (cac_[state | (1 << i)] == -1)
                return cac_[state] = 1;
        }
        return cac_[state] = -1;
    }
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal)
            return true;
        if ((maxChoosableInteger + 1) * maxChoosableInteger / 2 < desiredTotal)
            return false;
        memset(cac_, 0, sizeof(cac_));
        if (win(maxChoosableInteger, desiredTotal, 0) == 1)
            return true;
        return false;
    }
};


int main()
{
    Solution ins;
    if (ins.canIWin(4, 6))
        cout<< "Win"<< endl;
    else
        cout<< "Lose"<< endl;
    return 0;
}
