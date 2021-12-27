#include <bits/stdc++.h>

using namespace std;

unsigned long long v[100001], u[100001], sv[100001], su[100001];

int main() {
    int n, m, type, l, r;

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        sv[i] = sv[i - 1] + v[i];
    }

    memcpy(u + 1, v + 1, sizeof(unsigned long long) * n);
    sort(u + 1, u + n + 1);
    for (int i = 1; i <= n; ++i) {
        su[i] = su[i - 1] + u[i];
    }

    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> type >> l >> r;
        
        if (type == 1) {
            cout << sv[r] - sv[l - 1] << endl;
        } else {
            cout << su[r] - su[l - 1] << endl;
        }
    }

    return 0;
}