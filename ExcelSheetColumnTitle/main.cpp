#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    char ntoc(int n) {
        return n + 'A';
    }
    string convertToTitle(int n) {
        string ans;
        while (n) {
            n--;
            ans = ntoc(n % 26) + ans;
            n /= 26;
        }
        return ans;
    }
};

int main()
{
    return 0;
}
