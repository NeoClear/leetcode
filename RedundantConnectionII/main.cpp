#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> par_;
    vector<int> lead_;
    int find(int v) {
        if (lead_[v] != v) lead_[v] = find(lead_[v]);
        return lead_[v];
    }
    void merge(int x, int y) {
        lead_[find(y)] = find(x);
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int N = edges.size();
        par_ = vector<int>(N + 1, 0);
        pair<int, int> del_ = {0, 0};
        pair<int, int> remain_ = {0, 0};
        vector<int> ans_;
        for (int i = 0; i < N; i++) {
            int par = edges[i][0];
            int child = edges[i][1];
            if (par_[child]) {
                del_ = {par, child};
                remain_ = {par_[child], child};
                edges[i][0] = edges[i][1] = -1;
            }
            par_[child] = par;
        }
        lead_ = vector<int>(N + 1);
        for (int i = 0; i < N; i++) lead_[i] = i;
        for (const auto& edge : edges) {
            int par = edge[0];
            int child = edge[1];
            if (par == -1 && child == -1) continue;
            cout<< par<< " -> "<< child<< endl;
            if (find(par) == find(child)) {
                if (!del_.first && !del_.second) return {par, child};
                else return {remain_.first, remain_.second};
            }
            merge(par, child);
        }
        return {del_.first, del_.second};
    }
};

int main()
{
    Solution ins;
    vector<vector<int>> in = {
        {2, 1},
        {3, 1},
        {4, 2},
        {1, 4}
    };
    for (const auto& it : ins.findRedundantDirectedConnection(in)) cout<< it<< endl;
    return 0;
}
