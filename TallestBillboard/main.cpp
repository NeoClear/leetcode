#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        int hh = accumulate(begin(rods), end(rods), 0);
        vector<vector<int>> C(n + 1, vector<int>(hh + 1, -1));
        C[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            int h = rods[i - 1];
            for (int k = 0; k <= hh - h; k++) {
                if (C[i - 1][k] < 0) continue;
                C[i][k] = max(C[i][k], C[i - 1][k]);
                C[i][k + h] = max(C[i][k + h], C[i - 1][k]);
                C[i][abs(k - h)] = max(C[i][abs(k - h)], C[i - 1][k] + min(k, h));
            }
        }
        return C[n][0] < 0 ? 0 : C[n][0];
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
