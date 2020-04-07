#include <bits/stdc++.h>

using namespace std;

class ProductOfNumbers {
private:
    vector<int> product;
    set<int> isZero;
public:

    ProductOfNumbers() {
        product.push_back(1);
    }
    
    void add(int num) {
        if (num == 0)
            isZero.insert(product.size());
        product.push_back(num == 0 ? 1 : product.back() * num);
    }
    
    int getProduct(int k) {
        if (isZero.upper_bound(product.size() - 1 - k) != isZero.end())
            return 0;
        return product.back() / product[product.size() - k - 1];
    }
};

int main() {
    ProductOfNumbers ins;
    ins.add(2);
    ins.add(3);
    ins.add(0);
    ins.add(7);
    cout << ins.getProduct(2) << endl;
    return 0;
}
