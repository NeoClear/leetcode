#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        string r = string(s.crbegin(), s.crend());
        return s == r;
    }
};

int main()
{
    Solution ins;
    cout<< ins.isPalindrome(90);
    return 0;
}
