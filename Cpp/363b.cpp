#include <bits/stdc++.h>

using namespace std;

int h[150001], s[150001];

int main() {
    int n, k, minsum = 0x7fffffff, minsumpos;

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
        s[i] = s[i - 1] + h[i];
    }

    for (int i = 1; i <= n - k + 1; ++i) {
        if (s[i + k - 1] - s[i - 1] < minsum) {
            minsum = s[i + k - 1] - s[i - 1];
            minsumpos = i;
        }
    }

    cout << minsumpos << endl;

    return 0;
}