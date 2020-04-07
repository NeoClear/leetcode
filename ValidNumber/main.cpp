#include <iostream>

using namespace std;

class Solution {
private:
    const char *str;
    unsigned long long ptr = 0;
    unsigned long long size;
    bool hasSign = false;
    bool hasPoint = false;
public:
    bool read_blank()
    {
        while (str[ptr] == ' ' && ptr < size)
            ptr++;
        return true;
    }
    bool read_digit()
    {
        if (ptr >= size || !(str[ptr] <= '9' && str[ptr] >= '0'))
            return false;
        ptr++;
        return true;
    }
    bool read_sign()
    {
        if (ptr >= size || !(str[ptr] == '-' || str[ptr] == '+'))
            return false;
        ptr++;
        hasSign = true;
        return true;
    }
    bool read_point()
    {
        if (ptr >= size || str[ptr] != '.')
            return false;
        ptr++;
        hasPoint = true;
        return true;
    }
    bool read_e()
    {
        if (ptr >= size || str[ptr] != 'e')
            return false;
        ptr++;
        return true;
    }
    bool read_natural()
    {
        if (ptr >= size)
            return false;
        if (!read_digit())
            return false;
        while (read_digit()) {}
        return true;
    }

    bool isNumber(string s) {
        str = s.c_str();
        size = s.size();
        read_blank();
        read_sign();
        bool b1 = read_natural();
        read_point();
        bool b2 = read_natural();
        if (!(b1 || b2))
            return false;
        if (read_e()) {
            read_sign();
            if (!read_natural()) {
                return false;
            }
        }
        read_blank();
        if (ptr != size) {
            return false;
        }
        return true;
    }
};

int main()
{
    Solution ins;
    if (ins.isNumber("1."))
        cout<< "True"<< endl;
    else
        cout<< "False"<< endl;
    return 0;
}
