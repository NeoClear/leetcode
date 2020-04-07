#include <bits/stdc++.h>

using namespace std;


class CustomFunction {
public:
    // Returns f(x, y) for any given positive integers x and y.
    // Note that f(x, y) is increasing with respect to both x and y.
    // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
    int f(int x, int y);
};


class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> ans;
        int x = 1, y = 1;
        while (customfunction.f(x, y) < z)
            y++;
        while (y > 0) {
            if (customfunction.f(x, y) == z) {
                ans.push_back({x, y});
                y--;
            }
            if (customfunction.f(x, y) > z)
                y--;
            if (customfunction.f(x, y) < z)
                x++;
        }
        return ans;
    }
};

int main()
{
    return 0;
}
