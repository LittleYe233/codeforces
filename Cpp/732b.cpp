#include <bits/stdc++.h>

using namespace std;

int a[501];

int main() {
    int n, k, ans = 0, d;

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 2; i <= n; ++i) {
        if (a[i] + a[i - 1] < k) {
            d = a[i];
            a[i] = k - a[i - 1];
            ans += a[i] - d;
        }
    }

    cout << ans << endl;
    for (int i = 1; i <= n; ++i) {
        cout << a[i] << ' ';
    }

    return 0;
}