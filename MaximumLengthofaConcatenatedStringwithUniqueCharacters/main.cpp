#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> bits;
    vector<int> length;
    int max_len = 0;
    void solve(int state, int id, int len) {
        if (id == bits.size())
            max_len = max(max_len, len);
        for (int nt = id; nt < bits.size(); nt++) {
            if (bits[nt] + state == (bits[nt] | state)) {
                solve(state | bits[nt], nt + 1, len + length[nt]);
            } else {
                max_len = max(max_len, len);
            }
        }
    }
    bool duplicate(string s) {
        int flag = 0;
        for (const auto& c : s) {
            if (flag == (flag | (1 << (c - 'a'))))
                return true;
            flag |= 1 << (c - 'a');
        }
        return false;
    }
    int maxLength(vector<string>& arr) {
        for (const auto& s : arr) {
            if (duplicate(s))
                continue;
            int state = 0;
            for (const auto& c : s) {
                state |= (1 << (c - 'a'));
            }
            bits.push_back(state);
            length.push_back(s.length());
        }
        solve(0, 0, 0);
        return max_len;
    }
};

int main()
{
    Solution ins;
    vector<string> in = {
        "cha","r","act","ers"
    };
    cout << ins.maxLength(in) << endl;
    return 0;
}
