#include <bits/stdc++.h>

#define ll long long
#define mod 1000000007

using namespace std;

class Solution {
public:
    vector<string> layer;
    unordered_map<string, vector<string>> graph;
    string temp;
    void buildLayer(int depth) {
        if (depth == 3) {
            if (temp[0] != temp[1] && temp[1] != temp[2])
                layer.push_back(temp);
            return;
        }
        for (int i = 0; i < 3; i++) {
            temp[depth] = i + 'a';
            buildLayer(depth + 1);
        }
    }
    void buildGraph() {
        for (const auto& src : layer) {
            for (const auto& dest : layer) {
                if (src[0] != dest[0] &&
                    src[1] != dest[1] &&
                    src[2] != dest[2])
                    graph[src].push_back(dest);
            }
        }
    }
    
    int numOfWays(int n) {
        temp = string(3, ' ');
        buildLayer(0);
        buildGraph();
        unordered_map<string, ll> count;
        for (const auto& it : layer)
            count[it] = 1;
        for (int i = 1; i < n; i++) {
            unordered_map<string, ll> cnt;
            for (const auto& it : graph) {
                string src = it.first;
                for (const auto& dest : it.second) {
                    cnt[dest] += count[src];
                    cnt[dest] %= mod;
                }
            }
            count.swap(cnt);
        }
        ll acc = 0;
        for (const auto& it : count) {
            acc += it.second;
            acc %= mod;
        }
        return acc;
    }
};

int main() {
    Solution ins;
    int in;
    cin >> in;
    cout << ins.numOfWays(in) << endl;
    return 0;
}
