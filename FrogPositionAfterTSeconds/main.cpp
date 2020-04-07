#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

class Solution {
private:
    unordered_map<int, vector<int>> tree;
public:
    double frogPosition(int n, vector<vector<int>> edges, int t, int target) {
        for (const auto& it : edges) {
            tree[it.front()].push_back(it.back());
            tree[it.back()].push_back(it.front());
        }
        // {id, prob, time}
        unordered_set<int> visited;
        queue<tuple<int, double, int>> q;
        q.push({1, 1.0, 0});
        visited.insert(1);
        while (!q.empty()) {
            int id;
            double prob;
            int time;
            tie(id, prob, time) = q.front();
            q.pop();
            if (id == target && t == time) {
                return prob;
            }
            if (time > t)
                break;
            int num_dest = tree[id].size() - (id == 1 ? 0 : 1);
            for (const auto& dest : tree[id]) {
                if (visited.count(dest))
                    continue;
                visited.insert(dest);
                // cout << dest << ", " << prob / num_dest << endl;
                q.push({dest, prob / num_dest, time + 1});
            }
            if (num_dest == 0)
                q.push({id, prob, time + 1});
        }
        return 0.0;
    }
};

int main() {
    Solution ins;
    cout << ins.frogPosition(8, {{2,1},{3,2},{4,1},{5,1},{6,4},{7,1},{8,7}}, 2, 4);
    return 0;
}