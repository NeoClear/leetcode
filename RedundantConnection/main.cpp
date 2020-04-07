#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<uint16_t> par_;
    uint16_t find(uint16_t x) {
        if (par_[x] != x) par_[x] = find(par_[x]);
        return par_[x];
    }
    void merge(uint16_t x, uint16_t y) { par_[find(y)] = find(x); }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        uint64_t N = edges.size();
        par_ = vector<uint16_t>(N + 1, 0);
        for (uint64_t i = 0; i <= N; i++) par_[i] = static_cast<uint16_t>(i);
        for (const auto& edge : edges) {
            uint16_t par = static_cast<uint16_t>(edge[0]);
            uint16_t child = static_cast<uint16_t>(edge[1]);
            if (find(par) == find(child)) return {par, child};
            merge(par, child);
        }
        return {0, 0};
    }
};

int main()
{
    return 0;
}
