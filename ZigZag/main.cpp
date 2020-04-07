#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string ret;

        if (numRows == 1)
            return s;
        int space = (numRows - 1) * 2;
        for (int i = 0; i < s.length(); i += space)
            ret.push_back(s[i]);
        for (int i = 2; i < space; i += 2) {
            int start = i / 2;
            for (int j = start; j < s.length(); ) {
                ret.push_back(s[j]);
                j += space - i;
                if (j >= s.length())
                    break;
                ret.push_back(s[j]);
                j += i;
            }
        }
        for (int i = numRows - 1; i < s.length(); i += space)
            ret.push_back(s[i]);
        return ret;
    }
};

int main()
{
    Solution ins;
    cout << ins.convert("PAYPALISHIRING", 4) << endl;
    return 0;
}
