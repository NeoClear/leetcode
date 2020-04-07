#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        auto graph = vector<vector<int>>(n, vector<int>(m, 0));
        for (const auto& it : indices) {
            for (int i = 0; i < m; i++)
                graph[it.front()][i]++;
            for (int i = 0; i < n; i++)
                graph[i][it.back()]++;
        }
        int ans = 0;
        for (const auto& line : graph)
            for (const auto& ele : line)
                if (ele & 0x1)
                    ans++;
        return ans;
    }
};

int main()
{
    return 0;
}
