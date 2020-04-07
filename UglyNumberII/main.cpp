#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int64_t> mul = {2, 3, 5};
        priority_queue<int64_t> q;
        q.push(-1);
        unordered_set<int64_t> visited;
        int64_t cnt = 0;
        while (!q.empty()) {
            int64_t cur = -q.top();
            q.pop();
            cnt++;
            if (cnt == n)
                return cur;
            for (const auto& fact : mul) {
                int64_t val = -cur * fact;
                if (visited.count(val))
                    continue;
                visited.insert(val);
                q.push(val);
            }
        }
        return 0;
    }
};

int main()
{
    return 0;
}
