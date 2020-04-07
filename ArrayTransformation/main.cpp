#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> transformArray(vector<int> arr) {
        vector<int> prev;
        vector<int> cur(arr.begin(), arr.end());
        do {
            prev = vector<int>(cur.begin(), cur.end());
            for (int i = 1; i < arr.size() - 1; i++) {
                if (prev[i] > prev[i - 1] && prev[i] > prev[i + 1])
                    cur[i]--;
                else if (prev[i] < prev[i - 1] && prev[i] < prev[i + 1])
                    cur[i]++;
            }
        } while (prev != cur);
        return cur;
    }
};

int main()
{
    Solution ins;
    for (const auto& it : ins.transformArray({6, 2, 3, 4}))
        cout << it << " ";
    return 0;
}
