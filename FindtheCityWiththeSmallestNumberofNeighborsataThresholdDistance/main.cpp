#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    unordered_map<int, vector<pair<int, int>>> graph;
    int bfs(int i, int threshold) {
        unordered_set<int> visited;
        priority_queue<pair<int, int>> q;   // remain, dest
        q.push({threshold, i});
        while (!q.empty()) {
            int cur = q.top().second;
            int dis = q.top().first;
            q.pop();
            if (visited.count(cur)) { continue; }
            visited.insert(cur);
            for (const auto& dest : graph[cur]) {
                int dest_id = dest.first;
                int remain = dis - dest.second;
                if (remain < 0) { continue; }
                q.push({remain, dest_id});
            }
        }
        return visited.size() - 1;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<int> reach(n);
        for (const auto& e : edges) {
            int from = e[0];
            int to = e[1];
            int dis = e[2];
            graph[from].push_back({to, dis});
            graph[to].push_back({from, dis});
        }
        for (int i = 0; i < n; i++) { reach[i] = bfs(i, distanceThreshold); }
        pair<int, int> ans = {-1, 200};
        for (int i = 0; i < n; i++) {
            cout << reach[i] << endl;
            if (reach[i] <= ans.second) { ans = {i, reach[i]}; }
        }
        return ans.first;
    }
};
