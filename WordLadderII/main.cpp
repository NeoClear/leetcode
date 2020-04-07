#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string begin_, end_;
    vector<string> words_;
    unordered_map<string, vector<string>> map_;
    int N;
    vector<vector<string>> ans_;
    bool diff(string& a, string& b) {
        int n = a.size();
        int d = 0;
        for (int i = 0; i < n; i++)
            d = a[i] == b[i] ? d : d + 1;
        return d == 1 ? true : false;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> wordList) {
        begin_.swap(beginWord);
        end_.swap(endWord);
        words_.swap(wordList);
        if (!unordered_set<string>(words_.begin(), words_.end()).count(begin_))
            words_.push_back(begin_);
        N = words_.size();
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (diff(words_[i], words_[j])) {
                    map_[words_[i]].push_back(words_[j]);
                    map_[words_[j]].push_back(words_[i]);
                }
            }
        }
        bool found = false;
        queue<pair<string, vector<string>>> q;
        q.push({begin_, {}});
        unordered_set<string> visited;
//        for (const auto& port : map_) {
//            for (const auto& dest : port.second)
//                cout<< port.first<< " -> "<< dest<< endl;
//        }
        while (!q.empty() && !found) {
            int size = q.size();
            unordered_set<string> tmp;
            while (size--) {
                auto cur = q.front(); q.pop();
                string s = cur.first;
                auto p = cur.second;
                if (visited.count(s)) continue;
                tmp.insert(s);
                p.push_back(s);
                if (s == end_) {
                    ans_.push_back(p);
                    found = true;
                }
                for (const auto& dest : map_[s]) {
                    q.push({dest, p});
                }
            }
            visited.insert(tmp.begin(), tmp.end());
        }
        return ans_;
    }
};

int main()
{
    Solution ins;
    for (const auto& line : ins.findLadders("hit", "cog", {"hot","dot","dog","lot","log","cog"})) {
        for (const auto& ele : line)
            cout<< ele<< " ";
        cout<< endl;
    }
    return 0;
}
