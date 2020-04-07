#include <bits/stdc++.h>

using namespace std;

class FooBar {
private:
    int n;
    mutex f, b;

public:
    FooBar(int n) {
        this->n = n;
        b.lock();
    }

    void foo(function<void()> printFoo) {

        for (int i = 0; i < n; i++) {
            f.lock();
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            b.unlock();
        }
    }

    void bar(function<void()> printBar) {

        for (int i = 0; i < n; i++) {
            b.lock();
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            f.unlock();
        }
    }
};

int main()
{
    return 0;
}
