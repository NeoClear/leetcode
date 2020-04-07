#include <vector>
#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<int> dirs = {1, -1};
        int size = arr.size();
        unordered_set<int> visited;
        queue<int> q;
        q.push(start);
        visited.insert(start);
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            if (arr[cur] == 0)
                return true;
            for (const auto& it : dirs) {
                int dest = cur + arr[cur] * it;
                if (dest >= size || dest < 0)
                    continue;
                if (!visited.count(dest)) {
                    q.push(dest);
                    visited.insert(dest);
                }
            }
        }
        return false;
    }
};

int main() {
    return 0;
}