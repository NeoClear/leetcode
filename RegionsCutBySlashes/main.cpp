#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    class DSU {
    public:
        vector<int> par;
        DSU(int n): par(n) {
            for (int i = 0; i < n; i++)
                par[i] = i;
        }
        int find(int x) {
            if (par[x] != x)
                par[x] = find(par[x]);
            return par[x];
        }
        void merge(int x, int y) {
            par[find(y)] = find(x);
        }
    };
public:
    int regionsBySlashes(vector<string>& grid) {
        int N = grid.size();
        DSU dsu(4 * N * N);
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                int id =  4 * (r * N + c);
                switch (grid[r][c]) {
                case ' ':
                    dsu.merge(id, id + 1);
                    dsu.merge(id + 1, id + 2);
                    dsu.merge(id + 2, id + 3);
                    break;
                case '/':
                    dsu.merge(id + 1, id + 2);
                    dsu.merge(id, id + 3);
                    break;
                case '\\':
                    dsu.merge(id, id + 1);
                    dsu.merge(id + 2, id + 3);
                    break;
                }
                if (c < N - 1)
                    dsu.merge(id + 1, id + 7);
                if (r < N - 1)
                    dsu.merge(id + 2, id + N * 4);
            }
        }
        int ans = 0;
        for (int i = 0; i < 4 * N * N; i++)
            ans = dsu.par[i] == i ? ans + 1: ans;
        return ans;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
