#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int leastOpsExpressTarget(int x, int target) {
        set<pair<int, int>> q;
        unordered_set<int> seen;
        q.emplace(0, target);
        while (!q.empty()) {
            const auto it = begin(q);
            const int c = it->first;
            const int t = it->second;
            q.erase(it);
            if (t == 0)
                return c - 1;
            if (seen.count(t))
                continue;
            seen.insert(t);
            int n = log(t) / log(x);
            int l = t - pow(x, n);
            if (!seen.count(l))
                q.emplace(c + (n == 0 ? 2 : n), l);
            int r = pow(x, n + 1) - t;
            if (!seen.count(r))
                q.emplace(c + n + 1, r);
        }
        return -1;
    }
};

int main()
{
    Solution ins;
    return 0;
}
