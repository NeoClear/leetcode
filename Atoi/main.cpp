#include <iostream>

using namespace std;

#define MAX 2147483647
#define MIN -2147483648

class Solution {
public:
    int myAtoi(string str) {
        unsigned long long ptr = 0;
        long long f = 1;
        long long ans = 0;
        long long trig = 0;
        while (str[ptr] == ' ' && ptr < str.size())
            ptr++;

        while (ptr < str.size()) {
            if (str[ptr] == '+') {
                if (trig)
                    break;
                else
                    trig = 1;
            } else if (str[ptr] == '-') {
                if (trig)
                    break;
                else {
                    trig = 1;
                    f = -1;
                }
            } else if (str[ptr] <= '9' && str[ptr] >= '0') {
                if (!trig)
                    trig = 1;
                if (f == 1) {
                    if ((ans * 10 + str[ptr] - '0') > MAX) {
                        return static_cast<int>(MAX);
                    }

                } else {
                    if (0 - (ans * 10 + str[ptr] - '0') < MIN) {
                        return static_cast<int>(MIN);
                    }
                }
                ans = ans * 10 + str[ptr] - '0';
            } else
                break;
            ptr++;
        }
        return static_cast<int>(ans * f);
    }
};

int main()
{
    Solution ins;
    cout<< ins.myAtoi("-1-")<< endl;
    return 0;
}
