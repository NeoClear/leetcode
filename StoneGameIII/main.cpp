#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int N = stoneValue.size();
        int tot = accumulate(stoneValue.begin(), stoneValue.end(), 0);
        unordered_map<int, int> cache;

        function<int(int)> solve = [&](int id) {
            if (cache.count(id))
                return cache[id];
            if (id >= N)
                return 0;
            int sum = 0;
            int best = INT_MIN;
            for (int i = id; i < min(N, id + 3); i++) {
                sum += stoneValue[i];
                int otc = sum - solve(i + 1);
                best = max(best, otc);
            }
            return cache[id] = best;
        };
        int result = solve(0);
        if (result > 0)
            return "Alice";
        else if (result == 0)
            return "Tie";
        return "Bob";
    }
};

int main() {
    return 0;
}
