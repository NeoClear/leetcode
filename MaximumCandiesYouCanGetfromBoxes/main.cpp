#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int size = status.size();
        unordered_set<int> visiting(initialBoxes.begin(), initialBoxes.end());
        unordered_set<int> visited;
        unordered_set<int> has_key;
        int cnt = 0;
        bool changed = true;
        while (changed) {
            changed = false;
            vector<int> insert, remove;
            for (const auto& box : visiting) {
                if (status[box] || has_key.count(box)) {
                    changed = true;
                    cnt += candies[box];
                    remove.push_back(box);
                    visited.insert(box);
                    for (const auto& k : keys[box])
                        has_key.insert(k);
                    for (const auto& dest : containedBoxes[box])
                        if (!visited.count(dest))
                            insert.push_back(dest);
                }
            }
            for (const auto& it : insert)
                visiting.insert(it);
            for (const auto& it : remove)
                visiting.erase(it);
        }
        return cnt;
    }
};

int main() {
    return 0;
}