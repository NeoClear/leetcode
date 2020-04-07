#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int N = max_element(nums.begin(), nums.end()) + 1;
        // num of div, sum of div other than itself and 1
        vector<pair<int, int>> sol(N, {2, 0});
        for (int i = 2; i < N; i++) {
            if (sol[i].first > 5)
                continue;
        }

    }
};