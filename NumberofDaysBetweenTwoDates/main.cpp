#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void parse(string format, vector<int>& day) {
        day[0] = stoi(format.substr(0, 4));
        day[1] = stoi(format.substr(5, 2));
        day[2] = stoi(format.substr(8, 2));
    }
    int getDay(int year, int month) {
        switch (month) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                return 31;
            case 4:
            case 6:
            case 9:
            case 11:
                return 30;
            default:
                if (year % 4 == 0) {
                    if (year % 100 == 0) {
                        if (year % 400 == 0)
                            return 29;
                        return 28;
                    }
                    return 29;
                }
                return 28;
        }
    }
    int calc(vector<int> day1, vector<int> day2) {
        if (day1[0] == day2[0] && day1[1] == day2[1])
            return day2[2] - day1[2];
        if (day1 > day2)
            return -calc(day2, day1);
        return getDay(day1[0], day1[1]) + calc({day1[1] == 12 ? day1[0] + 1 : day1[0], day1[1] == 12 ? 1 : day1[1] + 1, day1[2]}, day2);
    }
    int daysBetweenDates(string date1, string date2) {
        vector<int> day1(3), day2(3);
        parse(date1, day1);
        parse(date2, day2);
        return abs(calc(day1, day2));
    }
};

int main() {
    Solution ins;
    cout << ins.daysBetweenDates("1971-06-29", "2010-09-23") << endl;
    return 0;
}