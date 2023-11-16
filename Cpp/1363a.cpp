#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int t, n, x, a, odd, even;
    cin >> t;
    while (t--) {
        scanf("%d%d", &n, &x);
        odd = even = 0;
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a);
            if (a % 2) {
                odd++;
            } else {
                even++;
            }
        }
        bool result = [odd, even, x] () -> bool {
            for (int i = 1; i <= odd && i <= x; i += 2) {
                if (x - i <= even) {
                    return true;
                }
            }
            return false;
        }();
        printf(result ? "Yes\n" : "No\n");
    }
    return 0;
}
