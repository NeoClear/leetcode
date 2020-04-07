#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n < 2)
            return 0;
        int cnt = 0;
        vector<bool> arr = vector<bool>(n, false);
        for (int i = 2; i < n; i++) {
            if (!arr[i]) {
                cnt++;
                for (int acc = i; acc < n; acc += i)
                    arr[acc] = true;
            }
        }
        return cnt;
    }
};

int main()
{
    Solution ins;
    cout<< ins.countPrimes(13)<< endl;
    return 0;
}
