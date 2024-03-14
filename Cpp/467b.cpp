#include <cstdio>

using namespace std;

int x[1001];

bool checkbit(int x, int k, int n) {
    int t = 0;
    for (int i = 0; i < n; ++i) {
        if ((x & 1) == 1) {
            ++t;
        }
        if (t > k) {
            return false;
        }
        x /= 2;
    }
    return true;
}

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m + 1; ++i) {
        scanf("%d", x + i);
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        if (checkbit(x[i] ^ x[m], k, n)) {
            ans++;
        }
    }
    printf("%d\n", ans);

    return 0;
}