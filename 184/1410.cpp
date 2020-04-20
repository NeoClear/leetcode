#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<string, string> parse = {
        {"&quot;", "\""},
        {"&apos;", "\'"},
        {"&amp;", "&"},
        {"&gt;", ">"},
        {"&lt;", "<"},
        {"&frasl;", "/"}
    };


    string entityParser(string text) {
        string cache;
        unordered_map<int, string> replace;
        for (int i = 0; i < text.length(); i++) {
            char cur = text[i];
            if (cur == '&') {
                cache.clear();
                cache.push_back('&');
                continue;
            }
            if (!cache.empty()) {
                cache.push_back(cur);
                if (cur == ';') {
                    if (parse.count(cache)) {
                        replace[i - cache.length() + 1] = cache;
                    }
                    cache.clear();
                }
            }
        }
        string result;
        for (int i = 0; i < text.length(); i++) {
            if (replace.count(i)) {
                result += parse[replace[i]];
                i += replace[i].length() - 1;
                continue;
            }
            result.push_back(text[i]);
        }
        return result;
    }
};

int main() {
    string s;
    Solution ins;
    while (true) {
        getline(cin, s);
        if (s == ".exit")
            break;
        cout << ins.entityParser(s) << endl;
    }
    return 0;
}
