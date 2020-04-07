#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> shade;
    vector<vector<int>> m_;
    bool bfs(int x) {
        queue<int> q;
        q.emplace(x);
        while (!q.empty()) {
            int node = q.front(); q.pop();
            int color = shade[node];
            for (int i = 0; i < m_[node].size(); i++) {
                int target = m_[node][i];
                if (shade[target] == 0) {
                    shade[target] = -color;
                    q.emplace(target);
                } else {
                    if (shade[target] == color)
                        return false;
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        int S = dislikes.size();
        shade = vector<int>(N + 1, 0);
        m_ = vector<vector<int>>(N + 1);
        for (int i = 1; i <= N; i++)
            m_[i] = vector<int>(0);
        for (int i = 0; i < S; i++) {
            m_[dislikes[i][0]].push_back(dislikes[i][1]);
            m_[dislikes[i][1]].push_back(dislikes[i][0]);
        }

        for (int i = 1; i <= N; i++) {
            if (!shade[i]) {
                shade[i] = 1;
                if (!bfs(i))
                    return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution ins;
    vector<vector<int>> in = {
        {1, 2},
        {1, 3},
        {2, 4}
    };
    if (ins.possibleBipartition(4, in))
        cout<< "True"<< endl;
    else
        cout<< "False"<< endl;
    return 0;
}
