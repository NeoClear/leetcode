#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<int> v_;
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        v_.clear();
        int len = A.size();
        v_ = vector<int>(len, INT_MIN);

        for (int i = 0; i < len; i++) {
            int mx = INT_MIN;
            for (int j = i; j >= 0 && j > i - K; j--) {
                mx = max(mx, A[j]);
                v_[i] = max(v_[i], (j == 0 ? 0 : (v_[j - 1])) + mx * (i - j + 1));
            }
        }
        return v_.back();
    }
};

int main()
{
    Solution ins;
    vector<int> t = {
        1, 15, 7, 9, 2, 5, 10
    };
    cout<< ins.maxSumAfterPartitioning(t, 3);
    return 0;
}
