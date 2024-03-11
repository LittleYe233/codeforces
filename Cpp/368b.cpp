#include <cstdio>

using namespace std;

int a[100000], ord[100001], l[100000], ans[100000];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", l + i);
    }
    ans[n - 1] = 1;
    ++ord[a[n - 1]];
    for (int i = n - 2; i >= 0; --i) {
        if (ord[a[i]] == 0) {
            // printf("ord[a[%d]] == 0\n", i);
            ans[i] = ans[i + 1] + 1;
            ++ord[a[i]];
        } else {
            // printf("ord[a[%d]] != 0\n", i);
            ans[i] = ans[i + 1];
        }
    }
    for (int i = 0; i < m; ++i) {
        printf("%d\n", ans[l[i] - 1]);
    }

    return 0;
}
