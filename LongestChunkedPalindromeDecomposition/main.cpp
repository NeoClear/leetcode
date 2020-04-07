#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int ans_ = 0;
    string text_;
    void solve(int l, int r) {
        if (l > r) return;
        for (int k = 1; k <= (r - l + 1) / 2; k++) {
            if (text_.substr(l, k) == text_.substr(r - k + 1, k)) {
                ans_ += 2;
                cout<< text_.substr(l, k)<< endl;
                cout<<3<<endl;
                solve(l + k, r - k);
                return;
            }
        }
        cout<< text_.substr(l, r - l + 1)<< endl;
        cout<<2<< endl;
        ans_++;
    }
    int longestDecomposition(string text) {
        text_.swap(text);
        solve(0, text_.size() - 1);
        return ans_;
    }
};

int main()
{
    Solution ins;
    ins.longestDecomposition("elvtoelvto");
    return 0;
}
