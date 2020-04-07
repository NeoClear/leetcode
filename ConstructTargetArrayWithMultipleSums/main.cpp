#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& target) {
        if (target.size() == 1)
            return target.front() == 1;
        priority_queue<long long> q;
        long long sum = 0;
        for (const auto& it : target) {
            q.push(it);
            sum += it;
        }
        
        while (sum > target.size()) {
            long long largest = q.top();
            q.pop();
            long long others = sum - largest;
            long long val = min(largest - others, largest % others + others);
            if (val <= 0)
                return false;
            long long diff = largest - val;
            sum -= diff;
            q.push(val);
        }
        return true;
    }
};

int main() {
    Solution ins;
    vector<int> in = {
        1, 1, 1, 4
    };
    if (ins.isPossible(in))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
