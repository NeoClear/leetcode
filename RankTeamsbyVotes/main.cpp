#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int N = votes[0].size();
        vector<unordered_map<char, int>> count(N);
        for (const auto& line : votes) {
            for (int i = 0; i < N; i++) {
                char ch = line[i];
                count[i][ch]++;
            }
        }
        string ans(votes[0].begin(), votes[0].end());
        sort(ans.begin(), ans.end(), [&](char& a, char& b) {
            for (int i = 0; i < N; i++) {
                if (count[i][a] == count[i][b])
                    continue;
                return count[i][a] > count[i][b];
            }
            return a < b;
        });
        return ans;
    }
};

int main() {
    Solution ins;
    vector<string> in{
        "M","M","M","M"
    };
    cout << ins.rankTeams(in);
    return 0;
}