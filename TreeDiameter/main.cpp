#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<int, vector<int>> graph;
    unordered_set<int> visited;
    int ans = 0;
    int get_max(vector<int>& v) {
        int cnt = 0;
        for (const auto& it : v)
            cnt = max(cnt, it);
        return cnt;
    }
    int sum_max2(vector<int> v) {
        sort(v.begin(), v.end());
        int acc = 2;
        int cnt = 0;
        for (auto it = v.rbegin(); it != v.rend() && acc; it++, acc--)
            cnt += *it;
        return cnt;
    }
    int solve(int id) {
//        cout << id << endl;
        visited.insert(id);
        vector<int> go;
        for (const auto& dest : graph[id])
            if (!visited.count(dest))
                go.push_back(solve(dest));
        ans = max(ans, sum_max2(go) + 1);
//        cout << ans << endl;
        return get_max(go) + 1;
    }

    int treeDiameter(vector<vector<int>> edges) {
        for (const auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        solve(0);
        return ans - 1;
    }
};

int main()
{
    Solution ins;
    cout << ins.treeDiameter({{0, 1},
                              {0, 2}})
         << endl;
    return 0;
}
