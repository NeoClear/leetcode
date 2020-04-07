#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    unordered_map<int, int> cache;
    int solve(int i, int& n, map<int, int>& cover) {
        if (i >= n) { return 0; }
        if (cache.count(i)) { return cache[i]; }
        auto it = cover.upper_bound(i);
        if (it == cover.begin()) { return -1; }
        int ans = INT_MAX / 2;
        do {
            it = prev(it);
            if (it->second > i) { ans = min(ans, solve(it->second, n, cover)); }
        } while (it != cover.begin());
        if (ans == INT_MAX / 2)
            ans = -1;
        return cache[i] = ans == -1 ? -1 : ans + 1;
    }
    int minTaps(int n, vector<int>& ranges) {
        map<int, int> cover;
        for (int i = 0; i < ranges.size(); i++) { cover[i - ranges[i]] = i + ranges[i]; }
        return solve(0, n, cover);
    }
};

int main() {
    Solution ins;
    vector<int> in = {4,0,0,0,0,0,0,0,4};
    cout << ins.minTaps(8, in) << endl;
    return 0;
}
