#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        if (src == dst) return 0;
        K++;
        int N = n;
        int flightNum = flights.size();
        unordered_map<int, vector<pair<int, int>>> G;
        int ans = INT_MAX;
        for (int i = 0; i < flightNum; i++)
            G[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        queue<pair<int, int>> q;
        q.push({src, 0});
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto node_ = q.front(); q.pop();
                int cur = node_.first;
                int cost = node_.second;
                if (cur == dst) ans = min(ans, cost);
                for (const auto& next : G[cur]) {
                    int fellow = next.first;
                    int fee = next.second;
                    if (cost + fee >= ans) continue;
                    q.push({fellow, cost + fee});
                }
            }
            if (K == 0) break;
            K--;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

int main()
{
    Solution ins;

    return 0;
}
