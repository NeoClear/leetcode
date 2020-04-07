#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<int, int> cache;  // cache[i] is the maximum number of indices can visit
    int solve(int id, int d, vector<int>& arr) {
        if (cache.count(id)) { return cache[id]; }
        int ans = 0;
        for (int i = id - 1; i >= 0 && arr[i] < arr[id] && id - i <= d; i--)
            ans = max(ans, solve(i, d, arr));
        for (int i = id + 1; i < arr.size() && arr[i] < arr[id] && i - id <= d; i++)
            ans = max(ans, solve(i, d, arr));
        return cache[id] = ans + 1;
    }
    int maxJumps(vector<int>& arr, int d) {
        int ans = 0;
        for (int i = 0; i < arr.size(); i++)
            ans = max(ans, solve(i, d, arr));
        return ans;
    }
};

int main() {
    Solution ins;
    vector<int> in = {1};
    cout << ins.maxJumps(in, 1) << endl;
    return 0;
}