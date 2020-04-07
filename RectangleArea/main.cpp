#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int64_t a = A, b = B, c = C, d = D, e = E, f = F, g = G, h = H;
        int64_t deltaX = max(static_cast<int64_t>(0), (c - a) + (g - e) - (max(c, g) - min(a, e)));
        int64_t deltaY = max(static_cast<int64_t>(0), (d - b) + (h - f) - (max(d, h) - min(b, f)));
        return (c - a) * (d - b) + (g - e) * (h - f) - deltaX * deltaY;
    }
};

int main()
{
    return 0;
}
