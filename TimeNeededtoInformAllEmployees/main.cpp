#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void solve(int id, int time, int& ans, unordered_map<int, vector<int>>& g, vector<int>& informTime) {
        ans = max(ans, time);
        for (const auto& it : g[id])
            solve(it, time + informTime[id], ans, g, informTime);
    };
    int numOfMinutes(int n, int headID, vector<int> manager, vector<int> informTime) {
        unordered_map<int, vector<int>> g;
        for (int i = 0; i < n; i++)
            g[manager[i]].push_back(i);
        int ans = 0;
        solve(headID, 0, ans, g, informTime);
        return ans;
    }
};

int main() {
    Solution ins;
    cout << ins.numOfMinutes(7, 6, {1,2,3,4,5,6,-1}, {0,6,5,4,3,2,1});
    return 0;
}