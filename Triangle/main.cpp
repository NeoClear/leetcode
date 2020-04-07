#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<long long, int> cache;
    long long tag(int x, int y) {
        return (static_cast<long long>(x) << 32) + static_cast<long long>(y);
    }
    int solve(int x, int y, vector<vector<int>>& triangle) {
        if (x == triangle.size())
            return 0;
        if (cache.count(tag(x, y)))
            return cache[tag(x, y)];
        int left = solve(x + 1, y, triangle);
        int right = solve(x + 1, y + 1, triangle);
        return cache[tag(x, y)] = min(left, right) + triangle[x][y];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        return solve(0, 0, triangle);
    }
};

int main()
{
    return 0;
}
