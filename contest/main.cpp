#include <bits/stdc++.h>

using namespace std;

class xry {
public:
    int real, imaginary;
    xry(int x, int y) {
        real = x;
        imaginary = y;
    }
    xry(int x) {
        real = x;
    }
};

int main()
{
    xry x1 = 1;
    cout<< x1.real<< endl;
    return 0;
}
