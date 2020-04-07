#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int diff(vector<int>& t) {
        return abs(t.front() - t.back());
    }
    vector<int> closestDivisors(int num) {
        vector<int> ans = {1, num + 1};
        for (int i = 1; i <= sqrt(num + 2); i++) {
            if ((num + 1) % i == 0) {
                if (abs(i - (num + 1) / i) < diff(ans))
                    ans = {i, (num + 1) / i};
            }
            if ((num + 2) % i == 0) {
                if (abs(i - (num + 2) / i) < diff(ans))
                    ans = {i, (num + 2) / i};
            }
        }
        return ans;
    }
};

int main() {
    Solution ins;
    for (const auto& it : ins.closestDivisors(8))
        cout << it << " ";
    return 0;
}