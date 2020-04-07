#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        int N = routes.size();
        queue<int> q;
        unordered_map<int, vector<int>> g;
        unordered_set<int> visited;
        vector<int> bus(500, 0);
        for (int b = 0; b < N; b++) {
            for (const auto& stop : routes[b])
                g[stop].push_back(b);
        }
        int steps = 0;
        q.push(S);
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int station = q.front(); q.pop();
                if (station == T) return steps;
                visited.insert(station);
                for (const auto& buses : g[station]) {
                    if (bus[buses]) continue;
                    bus[buses] = 1;
                    for (const auto& stop_ : routes[buses]) {
                        if (visited.count(stop_)) continue;
                        q.push(stop_);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};

int main()
{
    Solution ins;
    vector<vector<int>> in = {
        {1, 2, 7},
        {3, 6, 7}
    };
    cout<< ins.numBusesToDestination(in, 1, 6)<< endl;
    return 0;
}
