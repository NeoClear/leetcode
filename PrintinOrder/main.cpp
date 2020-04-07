#include <bits/stdc++.h>

using namespace std;

class Foo {
public:
    Foo() {
        m2_.lock();
        m3_.lock();
    }

    void first(function<void()> printFirst) {

        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        m2_.unlock();
    }

    void second(function<void()> printSecond) {
        m2_.lock();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        m3_.unlock();
    }

    void third(function<void()> printThird) {
        m3_.lock();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
    private:
    std::mutex m2_, m3_;
};

int main()
{
    return 0;
}
