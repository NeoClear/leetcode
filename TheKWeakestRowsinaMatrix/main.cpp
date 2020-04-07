#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        map<pair<int, int>, int> graph;
        for (int i = 0; i < mat.size(); i++) {
            int val = accumulate(mat[i].begin(), mat[i].end(), 0);
            graph[{val, i}] = i;
        }
        int id = 0;
        vector<int> ans;
        for (const auto& it : graph) {
            if (id >= k) { break; }
            ans.push_back(it.second);
            id++;
        }
        return ans;
    }
};

int main() {
    return 0;
}