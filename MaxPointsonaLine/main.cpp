#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    pair<int, int> steer(pair<int, int> x, pair<int, int> y) {
        int dx = y.first - x.first;
        int dy = y.second - x.second;
        if (dx == 0)
            return {0, 1};
        if (dy == 0)
            return {1, 0};
        int n = gcd(dx, dy);
        return {dx / n, dy / n};
    }
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            map<pair<int, int>, int> map_;
            pair<int, int> fix = {points[i].front(), points[i].back()};
            int samePoint = 1;
            int localAns = 0;
            for (int j = i + 1; j < n; j++) {
                pair<int, int> cur = {points[j].front(), points[j].back()};
                if (fix == cur)
                    samePoint++;
                else
                    localAns = max(localAns, ++map_[steer(fix, cur)]);
            }
            ans = max(ans, localAns + samePoint);
        }
        return ans;
    }
};

int main()
{
    Solution ins;
    vector<vector<int>> in = {
        {1, 1},
        {2, 2},
        {3, 3}
    };
    cout<< ins.maxPoints(in)<< endl;
    return 0;
}
