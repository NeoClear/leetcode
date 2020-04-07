#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        vector<pair<int, int>> count(26);
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a'].first++;
            count[t[i] - 'a'].second++;
        }
        int ans = 0;
        for (int i = 0; i < 26; i++)
            ans += abs(count[i].first - count[i].second);
        return ans >> 1;
    }
};

int main() {
    Solution ins;
    cout << ins.minSteps("friend", "family") << endl;
    return 0;
}

