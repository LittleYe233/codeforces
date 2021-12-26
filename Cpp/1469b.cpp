#include <bits/stdc++.h>

using namespace std;

int r[101], b[101], rsum[101], bsum[101];

int main() {
    int t, n, m, maxrsum, maxbsum;

    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        for (int j = 1; j <= n; ++j) {
            cin >> r[j];
            rsum[j] = rsum[j - 1] + r[j];
        }
        cin >> m;
        for (int j = 1; j <= m; ++j) {
            cin >> b[j];
            bsum[j] = bsum[j - 1] + b[j];
        }

        maxrsum = maxbsum = 0;
        for (int j = 1; j <= n; ++j) {
            maxrsum = max(maxrsum, rsum[j]);
        }
        for (int j = 1; j <= m; ++j) {
            maxbsum = max(maxbsum, bsum[j]);
        }

        cout << maxrsum + maxbsum << endl;
    }

    return 0;
}