#include <bits/stdc++.h>

using namespace std;

int s[200001];

int sgn(int);

int main() {
    int t, n, a, len, limit;
    long long ans;

    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n;

        ans = len = 0;
        s[1] = 0;
        for (int j = 1; j <= n + 1; ++j) {
            if (j <= n) {
                cin >> a;
            }
            if (j > n || sgn(s[1]) * sgn(a) == -1) {
                limit = -0x7fffffff;
                for (int k = 1; k <= len; ++k) {
                    limit = max(limit, s[k]);
                }
                // cout << limit << endl;
                ans += limit;
                len = 0;
            }
            s[++len] = a;
        }

        cout << ans << endl;
    }

    return 0;
}

int sgn(int a) {
    if (a > 0) {
        return 1;
    } else if (a < 0) {
        return -1;
    } else {
        return 0;
    }
}