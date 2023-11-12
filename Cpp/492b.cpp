#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

int a[1001];

int main() {
    int n, l;
    cin >> n >> l;
    for (int i = 0; i < n; ++i) {
        scanf("%d", a+i);
    }
    sort(a, a + n);
    double maxd = a[0];
    for (int i = 1; i < n; ++i) {
        maxd = max(maxd, (a[i] - a[i - 1]) / 2.0);
    }
    maxd = max(maxd, (double)l - a[n - 1]);
    printf("%.10lf\n", maxd);
}
