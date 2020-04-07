#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> ans_;
    int diff;
    int length;
    void solve(int v, int len) {
        if (len == length) {
            ans_.push_back(v);
            return;
        }
        int i;
        if ((i = v % 10 - diff) >= 0)
            solve(v * 10 + i, len + 1);
        if ((i = v % 10 + diff) <= 9 && diff != 0)
            solve(v * 10 + i, len + 1);
    }
    vector<int> numsSameConsecDiff(int N, int K) {
        if (N == 1) return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        diff = K;
        length = N;
        for (int i = 1; i <= 9; i++)
            solve(i, 1);
        return ans_;
    }
};

int main()
{
    return 0;
}
