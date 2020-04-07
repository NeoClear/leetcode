#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0;
        for (const auto& line : grid)
            for (const auto& ele : line)
                cnt += ele < 0 ? 1 : 0;
        return cnt;
    }
};

int main() {
    return 0;
}