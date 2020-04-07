#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<pair<int, int>> counts;
        int cur = 0;
        int len = 0;
        for (auto it = words.begin(); it != words.end(); it++) {
            string& word = (*it);
            cur++;
            len += (cur == 1 ? 0 : 1) + word.size();
            if (next(it) == words.end() || next(it)->size() + len + 1 > maxWidth) {
                counts.push_back({cur, len});
                cur = 0;
                len = 0;
            }
        }
//        for (const auto& ele : counts)
//            cout<< ele.first<< ", "<< ele.second<< endl;
        vector<string> ans;
        int id = 0;
        for (int k = 0; k < counts.size() - 1; k++) {
            auto line = counts[k];
            int extra = maxWidth - line.second;
            if (line.first == 1) {
                ans.push_back(words[id++] + string(extra, ' '));
                continue;
            }
            int base = extra / (line.first - 1);
            int bonus = extra - base * (line.first - 1);
            string curLine;
            for (int i = 0; i < line.first; i++, id++) {
                if (i != 0) {
                    curLine += string((bonus > 0 ? 1 : 0) + base + 1, ' ');
                    bonus--;
                }
                curLine += words[id];
            }
            ans.push_back(curLine);
        }
        bool flag = true;
        string lastLine;
        for (; id < words.size(); id++) {
            lastLine += ((flag ? "" : " ") + words[id]);
            flag &= false;
        }
        lastLine += string(maxWidth - lastLine.size(), ' ');
        ans.push_back(lastLine);
        return ans;
    }
};

int main()
{
    vector<string> in = {
        "This", "is", "an", "example", "of", "text", "justification."
    };
    Solution ins;
    for (const auto& line : ins.fullJustify(in, 16))
        cout<< line<<"@" << endl;
    return 0;
}
