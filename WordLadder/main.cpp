#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_set<string> visited;
    unordered_map<string, vector<string>> graph;
    bool diff(string a, string b) {
        int count = 0;
        for (int i = 0; i < a.size(); i++)
            if (a[i] != b[i])
                count++;
        return count == 1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        for (int i = 0; i < wordList.size(); i++)
            for (int j = i + 1; j < wordList.size(); j++)
                if (diff(wordList[i], wordList[j])) {
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
        queue<string> q;
        q.push(beginWord);
        int step = 1;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string cur = q.front();
                q.pop();
                if (visited.count(cur))
                    continue;
                visited.insert(cur);
                if (cur == endWord)
                    return step;
                for (const auto& dest : graph[cur])
                    q.push(dest);
            }
            step++;
        }
        return 0;
    }
};

int main()
{
    return 0;
}
