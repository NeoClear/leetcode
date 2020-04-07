#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int N = arr.size();
        if (N == 0) { return 0; }
        unordered_map<int, int> count;
        for (const auto& it : arr) { count[it]++; }
        vector<int> vals;
        for (const auto& it : count) {
            vals.push_back(it.second);
        }
        int ans = 0;
        int cnt = 0;
        sort(vals.begin(), vals.end());
        for (auto it = vals.rbegin(); it != vals.rend(); it++) {
            cnt += *it;
            ans++;
            if (cnt * 2 >= N) { return ans; }
        }
        return vals.size();
    }
};

int main() {
    return 0;
}