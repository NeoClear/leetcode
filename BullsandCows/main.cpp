#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        if (secret.empty() || guess.empty())
            return "0A0B";
        int bull = 0;
        int cow = 0;
        auto stats = vector<int>(10, 0);
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i])
                bull++;
            else
                stats[secret[i] - '0']++;
        }
        for (int i = 0; i < guess.size(); i++) {
            if (secret[i] != guess[i] && stats[guess[i] - '0']-- > 0)
                cow++;
        }
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};

int main()
{
    return 0;
}
