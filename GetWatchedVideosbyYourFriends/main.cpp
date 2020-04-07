#include <unordered_map>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        unordered_map<string, int> count;
        unordered_set<int> visited;
        queue<int> q;
        q.push(id);
        visited.insert(id);
        for (int i = 0; i < level && !q.empty(); i++) {
            int size = q.size();
            while (size--) {
                int cur = q.front(); q.pop();
                for (const auto& dest : friends[cur]) {
                    if (visited.count(dest))
                        continue;
                    q.push(dest);
                    visited.insert(dest);
                }
            }
        }
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (const auto& it : watchedVideos[cur])
                count[it]++;
        }
        vector<pair<int, string>> ans;
        for (const auto& [k, v] : count) {
            ans.push_back({v, k});
        }
        sort(ans.begin(), ans.end());
        vector<string> ret;
        for (const auto& [k, v] : ans)
            ret.push_back(v);
        return ret;
    }
};

int main() {
    vector<vector<string>> watchedVideos = {{"A","B"},{"C"},{"B","C"},{"D"}};
    vector<vector<int>> friends = {{1,2},{0,3},{0,3},{1,2}};
    Solution ins;
    auto ret = ins.watchedVideosByFriends(watchedVideos, friends, 0, 1);
    for (const auto& it : ret)
        cout << it << endl;
    return 0;
}