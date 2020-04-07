#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        queue<int> q;
        q.push(n);
        int steps = 0;
        unordered_set<int> visited;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int cur = q.front();
                q.pop();
                if (cur == 0)
                    return steps;
                for (int i = sqrt(cur); i >= 1; i--) {
                    int val = cur - i * i;
                    if (visited.count(val))
                        continue;
                    visited.insert(val);
                    q.push(val);
                }
            }
            steps++;
        }
        return 0;
    }
};

int main()
{
    return 0;
}
