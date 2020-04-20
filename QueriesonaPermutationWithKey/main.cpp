#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        // the position of number i is pos[i]
        unordered_map<int, int> pos;
        vector<int> result;
        for (int i = 1; i <= m; i++)
            pos[i] = i - 1;
        for (const auto& it : queries) {
            int cur = pos[it];
            result.push_back(cur);
            for (auto& p : pos) {
                if (p.second < cur)
                    p.second++;
            }
            pos[it] = 0;
        }
        return result;
    }
};

int main() {
    return 0;
}
