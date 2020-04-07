#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> nums) {
        unordered_set<int> num = unordered_set<int>(nums.begin(), nums.end());
        unordered_map<int, int> count;
        unordered_set<int> visited;
        int ans = 0;
        for (const auto& n : num) {
            int acc = 1;
            if (visited.count(n))
                continue;
            visited.insert(n);
            int id = n;
            while (num.count(id + 1)) {
                if (count.count(id + 1)) {
                    acc += count[id + 1];
                    break;
                }
                acc++;
                visited.insert(id + 1);
                id++;
            }
            count[n] = acc;
            ans = max(ans, acc);
        }
        for (const auto& it : count)
            cout<< it.first<< " -> "<< it.second<< endl;
        return ans;
    }
};

int main()
{
    Solution ins;
    ins.longestConsecutive({100, 4, 200, 1, 3, 2});
    return 0;
}
