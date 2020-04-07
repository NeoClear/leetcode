#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<pair<int, int>>> m_;
    vector<int> remain;
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
        m_ = vector<vector<pair<int, int>>>(N, vector<pair<int, int>>(0));
        remain = vector<int>(N);
        for (const auto& line : edges) {
            // hp reduction of every line
            m_[line[0]].push_back({line[1], line[2] + 1});
            m_[line[1]].push_back({line[0], line[2] + 1});
        }
        priority_queue<pair<int,  int>> q; // hp, node
        map<int, int> cac_;
        q.push({M, 0});
        while (!q.empty()) {
            auto node = q.top(); q.pop();
            int hp = node.first;
            int id = node.second;
            if (cac_.count(id)) continue;
            cac_[id] = 0;
            remain[id] = hp;
            for (const auto& edge : m_[id]) {
                int id_ = edge.first;
                int len_ = edge.second;
                if (hp >= len_)
                    q.push({hp - len_, id_});
            }
        }
//        for (int i = 0; i < N; i++)
//            cout<< i<< ": "<< remain[i]<< endl;
        int ans = 0;
        for (const auto& line : edges) {
            int left = line[0];
            int right = line[1];
            int nodes = line[2];
            ans += min(nodes, remain[left] + remain[right]);
        }
        return ans + cac_.size();
    }
};

int main()
{
    Solution ins;
    vector<vector<int>> in = {
        {1,2,4},{1,4,5},{1,3,1},{2,3,4},{3,4,5}
    };
    cout<< ins.reachableNodes(in, 17, 5)<< endl;
    return 0;
}
