#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int t, n, k, tt;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        scanf("%d%d", &n, &k);
        tt = k % (n - 1);
        tt = (tt == 0) ? n - 1 : tt;
        printf("%d\n", (int)ceil(k * 1.0 / (n - 1) - 1) * n + tt);
    }
}
