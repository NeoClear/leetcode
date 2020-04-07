#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int N = equations.size();
        unordered_map<string, unordered_map<string, double>> G;
        for (int i = 0; i < N; i++) {
            G[equations[i][0]][equations[i][1]] = values[i];
            G[equations[i][1]][equations[i][0]] = 1 / values[i];
        }
        int queryNum = queries.size();
        vector<double> ans;
        for (int i = 0; i < queryNum; i++) {
            string src = queries[i][0], dst = queries[i][1];
            if (!G.count(src) || !G.count(dst)) { ans.push_back(-1.0); continue; }
            if (src == dst) { ans.push_back(1.0); continue; }
            queue<pair<string, double>> q;
            unordered_set<string> visited;
            q.push({src, 1.0});
            while (!q.empty()) {
                string cur = q.front().first;
                double val = q.front().second;
                q.pop();
                if (visited.count(cur)) continue;
                visited.insert(cur);
                if (cur == dst) { ans.push_back(val); break; }
                for (const auto& it : G[cur]) {
                    string node_ = it.first;
                    double v_ = it.second;
                    if (visited.count(node_)) continue;
                    q.push({node_, val * v_});
                }
            }
            if (!visited.count(dst)) ans.push_back(-1.0);
        }
        return ans;
    }
};

int main()
{
    Solution ins;
    vector<vector<string>> equation = {
        {"a", "b"},
        {"b", "c"}
    };
    vector<double> value = {
        2.0, 3.0
    };
    vector<vector<string>> query = {
        {"a", "c"},
        {"b", "a"},
        {"a", "e"},
        {"a", "a"},
        {"x", "x"}
    };
    vector<double> ans = ins.calcEquation(equation, value, query);
    for (const auto& it : ans)
        cout<< it<< endl;
    return 0;
}
