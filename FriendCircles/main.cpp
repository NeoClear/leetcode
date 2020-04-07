#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int N;
    vector<int> par_;
    int find(int x) {
        if (par_[x] != x)
            par_[x] = find(par_[x]);
        return par_[x];
    }
    void merge(int x, int y) {
        par_[find(y)] = find(x);
    }
    int findCircleNum(vector<vector<int>>& M) {
        N = M.size();
        par_ = vector<int>(N);
        for (int i = 0; i < N; i++)
            par_[i] = i;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (M[i][j] == 1) {
                    if (find(i) != find(j))
                        merge(i, j);
                }
            }
        }
        int ans_ = 0;
        for (int i = 0; i < N; i++)
            if (par_[i] == i) ans_++;
        return ans_;
    }
};

int main()
{
    return 0;
}
