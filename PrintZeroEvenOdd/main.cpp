#include <bits/stdc++.h>

using namespace std;

class ZeroEvenOdd {
private:
    int n;
    mutex z, e, o;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        e.lock();
        o.lock();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i++) {
            z.lock();
            printNumber(0);
            if (i % 2 == 0) {
                e.unlock();
            } else {
                o.unlock();
            }
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            e.lock();
            printNumber(i);
            z.unlock();
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            o.lock();
            printNumber(i);
            z.unlock();
        }
    }
};

int main()
{
    return 0;
}
