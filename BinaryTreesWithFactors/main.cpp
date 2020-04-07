#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<int, uint64_t> dp_;
    int numFactoredBinaryTrees(vector<int>& A) {
        if (A.empty()) return 0;
        sort(A.begin(), A.end());
        dp_ = unordered_map<int, uint64_t>();
        constexpr int modulo = 1000000007;
        for (uint64_t i = 0; i < A.size(); i++) {
            dp_[A[i]] = 1;
            for (uint64_t j = 0; j < i; j++) {
                int remain_ = A[i] % A[j];
                int div_ = A[i] / A[j];
                if (remain_ == 0 && dp_.count(div_)) dp_[A[i]] = (dp_[A[i]] + dp_[A[j]] * dp_[div_]) % modulo;
            }
        }
        uint64_t ans = 0;
        for (const auto& it : dp_) ans = (ans + it.second) % modulo;
        return static_cast<int>(ans);
    }
};

int main()
{
    Solution ins;
    vector<int> in = {
        2, 4, 5, 10
    };
    cout<< ins.numFactoredBinaryTrees(in)<< endl;
    return 0;
}
