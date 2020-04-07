#include <bits/stdc++.h>

using namespace std;

#define kInf 101

class Solution {
private:
    vector<vector<int>> pos_;
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        pos_ = vector<vector<int>>(T + 1, vector<int>(T + 1, kInf));
        for (const auto& c : clips) {
            int s = c[0];
            int e = c[1];
            for (int len = 1; len <= T; len++) {
                for (int base = 0; base <= T - len; base++) {
                    int tail = base + len;
                    if (tail < s || base > e) continue;
                    if (base >= s && tail <= e) pos_[base][tail] = 1;
                    else if (s > base && e >= tail) pos_[base][tail] = min(pos_[base][tail], pos_[base][s] + 1);
                    else if (e < tail && s <= base) pos_[base][tail] = min(pos_[base][tail], pos_[e][tail] + 1);
                    else pos_[base][tail] = min(pos_[base][tail], pos_[base][s] + 1 + pos_[e][tail]);
//                    cout<< base<< ", "<< tail<< ": "<< pos_[base][tail]<< endl;
                }
            }
        }
//        for (int i = 0; i <= T; i++) {
//            for (int j = i; j <= T; j++)
//                cout<< i<< " "<< j<< ": "<< pos_[i][j]<< endl;
//        }
        return pos_[0][T] == kInf ? -1 : pos_[0][T];
    }
};

int main()
{
    Solution ins;
    vector<vector<int>> in = {
        {0,2},{4,6},{8,10},{1,9},{1,5},{5,9}
    };
    vector<vector<int>> i = {
        {0, 1}, {1, 2}
    };
    cout<< ins.videoStitching(in, 10)<< endl;
    return 0;
}
