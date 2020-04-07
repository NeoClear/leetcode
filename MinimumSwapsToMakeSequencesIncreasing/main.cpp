#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSwap(vector<int> A, vector<int> B) {
        int N = A.size();
        if (N == 1) return 0;
        vector<int> modif(N, INT_MAX), keep(N, INT_MAX);
        modif[0] = 1;
        keep[0] = 0;
        for (int i = 1; i < N; i++) {
            if (A[i] > A[i - 1] && B[i] > B[i - 1]) {
                modif[i] = min(modif[i], modif[i - 1] + 1);
                keep[i] = min(keep[i], keep[i - 1]);
            }
            if (A[i] > B[i - 1] && B[i] > A[i - 1]) {
                modif[i] = min(modif[i], keep[i - 1] + 1);
                keep[i] = min(keep[i], modif[i - 1]);
            }
        }
        return min(modif[N - 1], keep[N - 1]);
    }
};

int main()
{
    Solution ins;
    cout<< ins.minSwap({0, 4, 4, 5, 9}, {0, 1, 6, 8, 10})<< endl;
    return 0;
}
