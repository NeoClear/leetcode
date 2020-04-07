#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int tag(int a, int b) { return (a << 16) | b; }
    unordered_map<int, int> cache;
    int solve(int item, int day, vector<int>& jobDifficulty) {
        if (cache.count(tag(item, day))) { return cache[tag(item, day)]; }
        if (day == 1) {
            int diff = 0;
            for (int i = 0; i < item; i++) { diff = max(diff, jobDifficulty[i]); }
            return cache[tag(item, day)] = diff;
        }
        int diff = 0;
        int ans = INT_MAX / 2;
        for (int i = item - 1; i >= day - 1; i--) {
            diff = max(diff, jobDifficulty[i]);
            ans = min(ans, solve(i, day - 1, jobDifficulty) + diff);
        }
        return cache[tag(item, day)] = ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if (jobDifficulty.size() < d) { return -1; }
        return solve(jobDifficulty.size(), d, jobDifficulty);
    }
};

int main() {
    Solution ins;
    vector<int> in = {
        11,111,22,222,33,333,44,444
    };
    cout << ins.minDifficulty(in, 6) << endl;
    return 0;
}