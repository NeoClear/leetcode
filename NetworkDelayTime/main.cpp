#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        unordered_map<int, unordered_map<int, int>> G;
        unordered_map<int, int> dis;
        priority_queue<pair<int, int>> q;
        for (const auto& edge : times) {
            int u = edge[0], v = edge[1], w = edge[2];
            G[u][v] = w;
        }
        q.push({0, K});
        while (!q.empty()) {
            auto cur = q.top(); q.pop();
            int node_ = cur.second;
            int dis_ = -cur.first;
            if (dis.count(node_)) continue;
            dis[node_] = dis_;
            for (const auto& it : G[node_]) {
                int tar = it.first;
                int w = it.second;
                if (dis.count(tar)) continue;
                q.push({-(dis_ + w), tar});
            }
        }
        if (dis.size() != N)
            return -1;
        int ans = 0;
        for (const auto& it : dis) {
            ans = it.second > ans ? it.second : ans;
        }
        return ans;
    }
};

int main()
{
    Solution ins;

    return 0;
}
