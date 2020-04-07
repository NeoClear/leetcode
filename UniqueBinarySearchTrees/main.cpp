#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> cache;
    int numTrees(int n) {
        cache = vector<int>(n + 1, 0);
        cache[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                int l = j;
                int r = i - l - 1;
                cache[i] += cache[l] * cache[r];
            }
        }
        return n == 0 ? 0 : cache.back();
    }
};

int main()
{
    return 0;
}
