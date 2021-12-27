#include <bits/stdc++.h>

using namespace std;

int a[101], s[101];

int main() {
    int n, max_delta = -1;

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            max_delta = max(max_delta, j - i - 2 * s[j] + 2 * s[i - 1] + 1);
        }
    }

    cout << s[n] + max_delta << endl;

    return 0;
}