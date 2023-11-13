#include <algorithm>
#include <iostream>

using namespace std;

int s[100001];

int main() {
    int n, m, a, q, *p;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a);
        s[i] = s[i - 1] + a;
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        scanf("%d", &q);
        p = lower_bound(s, s + n, q);
        printf("%d\n", int(p - s));
    }
    return 0;
}
