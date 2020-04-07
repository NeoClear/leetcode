#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int last = 0;
        int cnt = 0;
        int ans = 0;
        for (const auto& it : light) {
            last = max(last, it);
            cnt++;
            if (last == cnt)
                ans++;
        }
        return ans;
    }
};

int main() {
    Solution ins;
    cout << ins.numTimesAllBlue({1,2,3,4,5,6});
    return 0;
}