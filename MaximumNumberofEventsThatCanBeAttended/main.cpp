#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](auto& a, auto& b) {
            return a.front() < b.front();
        });
        int pos = 0, ans = 0;
        priority_queue<int, vector<int>, greater<int>> q;
        for (int d = 1; d <= 100000; d++) {
            while (pos < events.size() && events[pos].front() == d)
                q.push(events[pos++].back());
            while (!q.empty() && q.top() < d)
                q.pop();
            if (!q.empty()) {
                q.pop();
                ans++;
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}