#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> parent;
    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    void merge(int x, int y) {
        parent[find(x)] = find(y);
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int ans = 0;
        parent = vector<int>(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        for (const auto& it : connections) {
            int x = it.front();
            int y = it.back();
            merge(x, y);
        }
        unordered_set<int> group;
        for (int i = 0; i < n; i++) {
            group.insert(find(i));
        }
        return connections.size() >= n - 1 ? group.size() - 1 : -1;
    }
};

int main() {
    Solution ins;
    vector<vector<int>> in = {{0,1},{0,2},{4,3},{3,2}};
    cout << ins.makeConnected(5, in) << endl;;
    return 0;
}